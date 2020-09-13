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

class D2 :public D1 // D2 derived from D1 
{
	public:
		void pvf()
		{
			cout<<"Overridden PVF in D2";
		}
};

int main() {

	D2 Object;
	Object.vf();
	Object.f();
	Object.pvf();

return 0;
}