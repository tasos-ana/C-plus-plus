//Hy-150-Programming
//Assigment 4
//Part 1
//Writed By Taso Anastasa
//A.M 3166

#include "std_lib_facilities.h"

template <class type> class List{
private:
	struct linked_list{	//here we got the linked_list that was struct with
		type data;		// unknowned type of data that store the input data 
		linked_list* next; // the linked_list pointer next that got the pointer of the next linked_list struct
	};
	linked_list* start;//here we store the start pointer of list
	linked_list* curr;//here we store the currence pointer that we use on main programm
	linked_list* temp;//here we store the temporary pointer 
public:
	List(){//the list constructor that declares the pointers to NULL
	start=NULL;
	curr=NULL;
	temp=NULL;
	}
	 void Add (type data);//that fuction put the data in linked_list
	 void Concatenate (List A,List B);//here we concatenate the list B on list A
	 void PrintNewList();//that fuction cout all the data of the new A list
};

template <class type> void List<type>::Add(type a){
	linked_list* n = new linked_list;//here we make new struct
	n->next = NULL;//with pointer next declared to NULL
	n->data=a;//and store on variable data the a that we read from console
	if (start!=NULL)//we check if start got value that mean we have already add 1 data
	{
		curr = start;//make the curr same we start to start check all list from start
		while ( curr->next!=NULL)//while we are not in the end
		{
			curr = curr->next;// we going on next struct pointer
		}
		curr->next=n;//make the last null next point same with new pointer that got on var n
	}
	else
	{
		start=n;//if that was the first time that we add data on list we make start same with  n
	}
}

template <class type> void List<type>::PrintNewList()
{
	curr = start;//make curr same with start of list to start print it
	while (curr->next!=NULL)//while we are not in the end
	{
		cout<<curr->data<<endl;//print the data
		curr=curr->next;//continue with next struct
	}
	cout<<curr->data<<endl;//print the last data because of the last data next pointer was NULL that mean  no enter while to print it!!
}

template <class type> void List<type>::Concatenate(List<type> A,List<type> B)
{

	if (A.start!=NULL && B.start!=NULL)//if the first and second list not in the end then
	{
		A.curr=A.start;//start reading first list until found the last data
		while(A.curr->next!=NULL)
		{
			A.curr=A.curr->next;
		}
		B.curr=B.start;//then we got the last pointer of first list, so we start with first data of second list
		while(B.curr->next!=NULL)//if that not null
		{
		   A.Add(B.curr->data);// we call fuction add and we put in the end of first list the new data of second list
			B.curr=B.curr->next;//we moved on next struct of second list
		}
		A.Add(B.curr->data);//here we put the last data of second list to the first
		cout<<"The new list it is:\n";
		A.PrintNewList();//cout the new list with new datas
		
	}
	else if (A.start=NULL)//if the first list was empty 
	{
		cout<<"The new list it is the second list because first was empty\n";
		B.PrintNewList();//then we printh the second list only
	}
	else if(B.start=NULL)//if the second list was empty
	{
		cout<<"The new list it is the first list because second was empty\n";
		A.PrintNewList();//we print the data of first list
	}
	else
	{
		cout<<"Your list that you gave was empty\n";//if was both lists empty no put something except that msg
	}
}

int main()
{
	List<char> first;//make the first list
	List<char> second;//make the second list
	List<char> link;//the list that call the concatenate fuction
	char read;//we want a char input
	cout<<"Please give your data for the first linked list, press ';' to stop!\n";
	cin>>read;//read the char
	while(read!=';')//if no give ; for end reading
	{
		first.Add(read);// put data that we read on first list
		cin>>read;//read again
	}
	cout<<"\nPlease give your data for the second linked list press ';' to stop!\n";
	read='f';//change read from ; to something else
	cin>>read;//read the new input for second list
	while(read!=';')//if not ;
	{
		second.Add(read);// we put that data on second list
		cin>>read;//read again new input
	}
		link.Concatenate(first,second);//call the fuction for concatenate 2 lists
		keep_window_open();//w8 to take grade 10!!
	return 0;
}

//Hy-150-Programming
//Assigment 4
//Part 1
//Writed By Taso Anastasa
//A.M 3166