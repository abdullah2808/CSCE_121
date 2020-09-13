#include <iostream>
using namespace std;

void swap_v(int a,int b){
	int temp;
	temp = a;
	a = b;
	b = temp;

}

void swap_r(int& a, int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;

}

void swap_cr(const int& a, const int& b){
	int temp;
	temp = a;
	//a = b;
	//b = temp;

}

int main(){
	int x = 7;
	int y = 9;
	swap_v(x,y);
	cout << "x is " << x << endl;
	cout << "y is " << y << endl;
	// 1 swap_r(7,9);
	const int cx = 7;
	const int cy = 9;
	// 2 swap_cr(cx,cy);
	// 3 swap_cr(7.7,9.9);
	double dx = 7.7;
	double dy = 9.9;
	// 4 swap_r(dx,dy);
	swap_v(7.7,9.9);
	cout << "x is " << dx << endl;
	cout << "y is " << dy << endl;

	return 0;	
}
	