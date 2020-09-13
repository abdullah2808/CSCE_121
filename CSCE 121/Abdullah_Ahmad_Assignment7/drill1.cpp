#include <iostream>
using namespace std;

class B1 // class definition 
{
	public:
		virtual void vf() // creation of virtual function 
		{
			cout<< "Virtual Function B1" << endl; // what the virtual function does
		}
		void f() // creation of function
		{
			cout<< "Function B1" ; // what the function does
		}

};
int main() {

	B1 object; // creation of object of class B1
	object.vf(); // calls virtual function on object
	object.f(); // calls function on object

return 0;
}