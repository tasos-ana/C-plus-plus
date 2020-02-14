#include "Simple_window.h"    
#include "Graph.h"      
using namespace Graph_lib;

int main()
{
   Simple_window win(Point(100,100),500,300,"Olympic Airways");//Here we make one window 500x300 and with name Olympic Airways
   Circle a(Point(100,50),40);//Make the first circle at x=100 and y=50 with range 20
   Circle b(Point(100,110),40);//Same with previous
   Circle c(Point(100,170),40);//Same with previous
   Circle d(Point(100,230),40);//Same with previous
   Circle e(Point(150,140),40);//Same with previous
   Circle f(Point(150,210),40);//Same with previous
   a.set_color(Color::yellow);//Change the color of the first circle
   b.set_color(Color::blue);//Same with previous
   c.set_color(Color::red);//Same with previous
   d.set_color(Color::blue);//Same with previous
   e.set_color(Color::blue);//Same with previous
   f.set_color(Color::red);//Same with previous
   Text t(Point(220,50),"The Olympic Airways Logo!");//Add a new text at x=220 and y=50 that told "The Olympic Airways Logo"
   t.set_font(Font::times_bold);//We make the text with bold font
   t.set_font_size(20);//Change size of text to 20
   Image i(Point(220,100),"Olympic_Airways_Logo.gif");//We add the image
   win.attach(a);//Add on the window the circle
   win.attach(b);//Add on the window the circle
   win.attach(c);//Add on the window the circle
   win.attach(d);//Add on the window the circle
   win.attach(e);//Add on the window the circle
   win.attach(f);//Add on the window the circle
   win.attach(t);//Add on the window the text
   win.attach(i);//Add on the window the image
   win.wait_for_button(); // give control to the display engine
}