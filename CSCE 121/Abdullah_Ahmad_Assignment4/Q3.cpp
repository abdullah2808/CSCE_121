#include <iostream>
using namespace std;

void fibonacciInt(){ // int 
	int a = 0, b = 1, next = 0, n, count=0; // all data types are ints a = n-2 b = n-1 starting with 2 

	cout << "Fib Series with ints" << a << ", " << b << ", ";
	next = a + b; // the definition of a fibonacci number 

	while(next >=0) { // I basically took the logic of this part of my code from a 102 project and rewrote it in C++
		cout << next << ", ";
		a = b; // n-2 = n-1
		b = next; // n-1 = n-1 + n-2
		next = a + b; // n-1 + n-2 again
		count++;
	}

	cout<<"\n Amount: "<< count << endl;

	return;

}

void fibonacciLong(){ // long
	long a = 0, b = 1, next = 0, n, count=0; // change of data type

	cout << "Fib Series with long" << a << ", " << b << ", ";
	next = a + b;

	while(next >=0) {
		cout << next << ", ";
		a = b;
		b = next;
		next = a + b;
		count++;
	}

	cout<<"\n Amount: "<< count << endl;

	return;

}

void fibonacciLongLong(){ // long long
	long long a = 0, b = 1, next = 0, n, count=0; // change of data type

	cout << "Fib Series with long long" << a << ", " << b << ", ";
	next = a + b;

	while(next >=0) {
		cout << next << ", ";
		a = b;
		b = next;
		next = a + b;
		count++;
	}

	cout<<"\n Amount: "<< count << endl;

	return;

}



int main() {
    fibonacciInt();
	fibonacciLong();
	fibonacciLongLong();
    return 0;
}
	
