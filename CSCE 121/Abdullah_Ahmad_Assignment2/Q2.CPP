#include<iostream>
using namespace std;

int main() {
	string firstName; // initializes ariables to include inputed information from user
	string friendName; 
	char friendSex = 0; 
	string friendM = "him";
	string friendF = "her";
	int age;
	
	cout << "Enter the first name of the person you would like to write to: " << endl; // collects and asks for information from the user
	getline(cin, firstName);
	cout << "Enter the first name of another friend: " << endl;
	getline(cin, friendName) ;
	cout << "Enter the sex of your friend (Enter either m or f -- lowercase)): " << endl;
	cin >> friendSex;
	cout << "Enter the age of the person you're writing too: \n";
	cin >> age;
	
	if (age <= 0 || age >= 110) { // checks if age is less than 0 or greater than 110 and ends the program if that is given
		cout << "You're kidding, thats not a valid age.";
		return 0;
	}
	
	
	
	cout << "Dear " << firstName << "," << endl; // most of this part of the code just prints out the letter after getting inputs
	cout << "\t How are you? I'm doing well and its been a while since we've spoke" << endl; 
	cout << "I miss you and I hope we can meet in person soon" << endl;

	
	if (friendSex == 'm') { // if statements that check the freind's sex and prints the character statement
		cout << "If you see " << friendName << " tell " << friendM << " to call me. \n";
	}
	if (friendSex == 'f') {
		cout << "If you see " << friendName << " tell " << friendF << " to call me. \n";
	}
	
	cout << "I heard you just had a birthday and are " << age << " years old. \n"; // this part here checks the age given and prints the correct statements
	if (age < 12) {
		cout << "Next year you will be " << age + 1 << endl;
	}
	if (age == 17) {
		cout << "Next year you will be able to vote. \n" ;
	}
	if (age > 70) {
		cout << "I hope you're enjoying your retirement. \n";
	}
	
	cout << "Yours sincerly, \n " << endl; // signing of the letter
	cout << "Abdullah Ahmad";
	
	
	return 0;
}