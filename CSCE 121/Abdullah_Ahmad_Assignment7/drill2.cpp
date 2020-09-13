#include <iostream>
using namespace std;

class B1 // class definition 
{
	public:
		virtual void vf() // creation of virtual function 
		{
			cout<< "Virtual Function B1" << endl; // what the virtual function does this is just so I can have some output and see what happens 
		}
		void f() // creation of function
		{
			cout<< "Function B1" << endl; // what the function does
		}

};

class D1 :public B1
{
	public:
		void vf() // polymorphism from the lecture slides 
		{
			cout<< "Virtual Function D1" << endl; 
		}

};

int main() {

	D1 object; // creation of object of class D1
/*	B1 object1;
	object1.vf();
	just some testing I was doing*/
	object.vf(); // calls virtual function on object virtual function D1 is called 
	object.f(); // calls function on object B1 is called 

return 0;
}