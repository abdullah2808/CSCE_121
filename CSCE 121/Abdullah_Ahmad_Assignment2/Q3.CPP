#include<iostream>
using namespace std;

int main() {
	string firstName; // initializing some variables
	string lastName;
	int secNum;


	// asks for user input
	cout << "Enter your first and last name, and the section number (space inbetween each)" << endl ;
	cin >> firstName >> lastName >> secNum;
	cout << firstName << " " << lastName << ": " << secNum << endl;
	
	// if statements to check for sections
	if (secNum <= 528 || secNum >= 537) { 
		cout << "Thats not a valid section number. Ending Program.";
		return 0;
		
	}
	if (secNum == 529 || secNum == 530 || secNum == 531 || secNum == 536) { // checks the section number entered and prints the correspondind PTs and TAs
		cout << secNum << " TA: Andrew Lam \n" ;
		if (secNum == 529) {
			cout << secNum << " PT: Hunter Hewitt \n" ;
			cout << secNum << " PT: Kyle Coffey \n" ;
		}
		if (secNum == 530) {
			cout << secNum << " PT: Hunter Hewitt \n" ;
			cout << secNum << " PT: Scott Wilkins \n" ;
		}
		if (secNum == 531) {
			cout << secNum << " PT: Cameron Lopez \n" ;
			cout << secNum << " PT: Luis Pantin \n" ;
		}
		if (secNum == 536) {
			cout << secNum << " PT: Nicholas Harris \n" ;
			cout << secNum << " PT: Cameron Lopez \n" ;
		}
	}
	if (secNum == 532 || secNum == 533 || secNum == 534 || secNum == 535) { // checks the section number entered and prints the correspondind PTs and TAs
		cout << secNum << " TA: Xien Thomas\n" ;
		if (secNum == 532) {
			cout << secNum << " PT: Lauren Ruffner \n" ;
			cout << secNum << " PT: Nicholas Harris \n" ;
		}
		if (secNum == 533) {
			cout << secNum << " PT: Emily Davis \n" ;
			cout << secNum << " PT: Luis Pantin \n" ;
		}
		if (secNum == 534) {
			cout << secNum << " PT: Emily Davis \n" ;
			cout << secNum << " PT: Karsen Keith \n" ;
		}
		if (secNum == 535) {
			cout << secNum << " PT: Nicholas Harris \n" ;
			cout << secNum << " PT: Cameron Lopez \n" ;
		}
	}
	
	return 0;
}

