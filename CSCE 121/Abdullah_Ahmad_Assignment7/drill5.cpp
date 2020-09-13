#include <iostream>
using namespace std;

class B1 // class definition 
{
	public:
		virtual void pvf() = 0;
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
		void f() // polymorphism from the lecture slides 
		{
			cout<< "Virtual Function D1" << endl; 
		}

};



int main() {

	D1 object; // creation of object of class D1 cannot create object of abstract type 
	B1 &pointa = object; // a reference
	pointa.vf(); // calls virtual function on reference B1 is called
	pointa.f(); // calls function on reference function B1 is called
	pointa.pvf(); // calls pure virtual on the reference 
	// object.pvf(); // calls pure virtual on the object 

return 0;
}