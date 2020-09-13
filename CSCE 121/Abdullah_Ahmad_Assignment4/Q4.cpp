#include <iostream>
using namespace std;


void decimal_to_octal(int n)
{
	if(n == 0){
	return; // stops the function
	} 
	decimal_to_octal(n / 8);  // recursive to convert from decimal to octal you divide by 8 and the remainder is the digit value
	cout << n % 8; // prints the remainder value
	
}

int main()
{
	int n;
	char c;
	while (c != 'q'){ // runs until q is entered
		cout << "Enter Decimal number : ";
		cin >> n;
	if (n < 0){ // checks if postive value is entered
		cout << "Please enter a positive decimal number. " << endl;
		continue; // if not then runs from the start again
	}
	else {
		cout<< n << " to octal is : 0"; // prints the prefix
		decimal_to_octal(n); // prints the octal digits
		}
		
		cout << "\nEnter q to quit or anything else to continue. " << endl; // asks for user input to continue converting decimal to octal or to quit
		cin >> c;
	}
		

	

return 0;
}

	
	
	
	