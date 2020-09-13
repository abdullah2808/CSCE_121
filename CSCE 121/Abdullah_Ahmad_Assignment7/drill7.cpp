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

class B2 // B2 contains a pure virtual function 
{
	public:
		virtual void pvf() = 0;

};

class D21 :public B2  // D21 WITH A STRING 
{
	private:
		string str = "Howdy World!!!";
	public:
		void pvf()
		{
			cout << "D21: " << str << endl;
		}
};

class D22 :public B2 // D22 with an INT 
{
	private:
		int i = 22; // 22 cause you know :) 
	public:
		void pvf()
		{
			cout << "D22: " << i << endl;
		}
};

void f(B2 &object) // function F that calls an object
{
	object.pvf(); // calls the pure virtual function 
}

int main() {

	D21 Object1;
	D22 Object2;
	f(Object1);
	f(Object2);
	

return 0;
}