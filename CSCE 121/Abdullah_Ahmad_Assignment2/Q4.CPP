#include<iostream>
using namespace std;
#include <vector> 
#include<stdio.h>

void guess_number()
	{
		
	int min = 1; // variable declerations 
	int max = 64;
	int mid;
	string choice;
	
	while (min < max-1){ // runs the loop until min is greater than max - 1 
		mid = (min+max) / 2;
		
		cout << "Is your number less than " << mid << " yes (y) or no (n): " ; // gets input 
		cin >> choice;
		choice = choice[0];
		
		if (choice == "y"){ // if choie is greater sets max to mid -1 which in the first case is will be 31
			max = mid - 1;
		}
		else if (choice == "n"){ // sets min to the mid range which in the first case is 32
			min = mid;
		}
	}
	// testing what my values were from the while loop cout << min << max << mid;
if(min == max-1) { // once two numbers are left this is finds the choice between the numbers 
	
    cout << "Is your number less than " << max << "? yes (y) or (n): ";
	cin >> choice;
	choice = choice[0];
	
    if(choice == "y"){
      cout << "Number is " << min << endl;
	}
    else if (choice == "n"){
      cout << "Number is " << max << endl;
	}
	}
	else{ // if the min isn't let then the max and they are the same number the number has been found
	    cout << "Number is " << max << endl; 
}
}
	
int main() {
	guess_number();
	
	

	
	
	return 0;
}
