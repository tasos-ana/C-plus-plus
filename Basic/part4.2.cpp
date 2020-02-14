//Hy-150-Programming
//Assigment 4
//Part 2
//Writed By Taso Anastasa
//A.M 3166

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include "Graph.h"
#include "GUI.h"
#include "Window.h"

namespace Graph_lib {

	string In_box::get_string()
{
	Fl_Input& pi = reference_to<Fl_Input>(pw);
	return string(pi.value());
}

	void Out_box::put(int i)
{
	Fl_Output& po = reference_to<Fl_Output>(pw);
	std::stringstream ss;
	ss << i;
	po.value(ss.str().c_str());
}
	};

using namespace Graph_lib;
using namespace std;

stringstream in;
ostringstream out;
string read="";

struct calculate_window : Graph_lib::Window {
    calculate_window(Point xy, int w, int h, const string& title );
private:
	Button total_button;
    Button quit_button;
    In_box data;
    Out_box result;
    static void cb_quit(Address, Address); // callback for quit_button
	static void cb_calculate(Address,Address);
    void quit();
	void calculate();
};

calculate_window::calculate_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
	total_button(Point(30,64), 179, 52, "=", cb_calculate),
    quit_button(Point(215,64), 75, 52, "Quit", cb_quit),
    data(Point(50,12),240, 20, "Data"),
    result(Point(50,38), 240, 20, "Result")
{
	attach(total_button);
    attach(quit_button);
    attach(data);
    attach(result);
}

void calculate_window::cb_quit(Address , Address pw)    // "the usual"
{  
       reference_to<calculate_window>(pw).hide();
} 

void calculate_window::quit()
{
    hide();
}

void data_put(string a,Address pw)
	{
		Fl_Input& po = reference_to<Fl_Input>(pw);
		std::stringstream ss;
		ss << a;
		po.value(ss.str().c_str());
	}

void calculate_window::cb_calculate(Address, Address pw)
{
	reference_to<calculate_window>(pw).calculate();
}


const char number = '8'; // t.kind==number means that t is a number Token
const char print  = ';'; // t.kind==print means that t is a print Token
const char letter = 'k';// name token

class Token {
public:
    char kind;	// what kind of token
    double value;// for numbers: a value 
    Token(char ch)             : kind(ch), value(0)   {}
    Token(char ch, double val) : kind(ch), value(val) {}
};

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) 
		{
			return;
		}
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

Token Token_stream::get() // read characters from cin and compose a Token
{
    if (full) {         // check if we already have a Token ready
        full=false;
        return buffer;
    }  
    char ch;
    in >> ch;          // note that >> skips whitespace (space, newline, tab, etc.)
    switch (ch) {
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
	case print:
        return Token(ch); // let each character represent itself
    case '.':             // a floating-point literal can start with a dot
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':    // numeric literal
    {
        in.putback(ch);// put digit back into the input stream
        double val;
        in >> val;     // read a floating-point number
        return Token(number,val);
    }
    default:
		{
			return Token(letter); // keyword "k"
		}
	}
}

Token_stream ts; 
double expression();

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':           // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')')
				{
					return 0;
			    }
            return d;
        }
    case number:    
        return t.value;    // return the number's value
    case '-':
        return - primary();
    case '+':
        return primary();
	default:
			 {
					return 0;
			 }
    }
}

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get(); // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
            {    
                double d = primary();
                if (d == 0)
					{
						return 0;
				}
                left /= d; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);        // put t back into the token stream
            return left;
        }
    }
}

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

void calculate_window::calculate()
{
	in<<data.get_string();//we get data from data in_box
	in.put(';');//but on input stream after data the char ;
	out.str(" ");//make the results=0
	double val = 0;
    while(in)
	{
        Token t = ts.get();//reading token
		if (t.kind == print){//if token was ; we stop and print
            out<<val; 		//adds the result to the stream
            result.put(out.str());	//move the result to the output box
            break;	//terminate the function
		}
		else if (t.kind==letter)//if token is letter we stop and print msg
		{
			out<<"Input error, please try again";
			result.put(out.str());
			break;
		}
		else
		{
            ts.putback(t);
		}
        val = expression();
		}   
}

int main()
{
	  // predefine names:
	//define_name("pi",3.1415926535);
    //define_name("e",2.7182818284);
	try {
	   calculate_window win(Point(100,100),300,125,"Calculator");
	   return gui_main();
	}
	catch(exception& e)
	{
	    return 1;
	}
}

//Hy-150-Programming
//Assigment 4
//Part 2
//Writed By Taso Anastasa
//A.M 3166