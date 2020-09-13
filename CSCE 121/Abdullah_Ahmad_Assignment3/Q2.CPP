#include <iostream>
using namespace std;
#include <cstdlib>
void print_pyramid(int n){


	int k; // number being printed
	int counter;  // line number
	int spaces; // blank spaces
	int count; // counter used for number of spaces
	int counter2; // 2nd counter used for right side of printing pyramid
	

	if (n > 15){ // if the input is greater than 15 it ends the program
		cout << "N is greater than 15" << endl;
		return;
	}
	
	k = 1;
	counter = k;
	count = 0;
	counter2 = 0; // some different counters for different loops 
	
	while (counter <= n){ // bigger outer loop that runs until everything is printed 
	spaces = (3 * (n-counter));
		while(count <= spaces){ //inner loop that prints spaces before any numbers 
			cout << " ";
			count += 1;
		}

		while(k >= 1){ // second inner loop that prints left side of numbers
			if (k > 9){
				cout << k << " "; // double digit printing
				k -= 1;
			}
			else{
				cout << k << "  "; // single digit printing
				k -= 1;
			}

		}
		
		k = 0;
		counter2 += 1; // incrementing the 2nd counter
		
		while(k < counter2){ // third inner loop that prints right side of numbers (right from 1)
			if (k != 0){ // checks if k is 0 and if it is doesn't print 1
			k += 1;
				if (k >= 9){
					cout << (abs(k)) << " "; // double digit printing
			}
				else {
					cout << (abs(k)) << "  "; // single digit printing 
			}
			}
			else{
			k += 1; // incrementing 
			}
		}
		
	counter += 1;
	k = counter; // incrementing to reduce the loop and increase k which is line number

	cout << endl; // goes to next line 
	count = 0; 
	}
	}
int main()
{
	int q ;

	while (q != -1){
	cout << "Please enter number of lines or -1 to cancel: \n";
	cin >> q; // takes input
	print_pyramid(q);

	}
	return 0;
}

