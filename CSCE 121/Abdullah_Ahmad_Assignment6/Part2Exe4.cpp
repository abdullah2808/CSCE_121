#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;



void convert(const string& str, const string& type) { // I had a friend help me with this function, but I wrote the explanations after he explained it to me

	istringstream s(str); //using string stream as a input 
	int number = 0;
	if (type == "hexadecimal") s >> hex >> number; // the type is input into the function in main
	if (type == "octal") s >> oct >> number;
	else s >> number;
	cout << str << '   ' << type << "  converts to " << dec << number << " decimal.\n"; 
}
int main() {
	cout << "Enter any integar in decimal, octal, or hexadecimal with the base suffix";
	while (cin) { // runs continously while inputs
		string input; 
		cin >> input; // takes input as a string
		if (input[0] == '0') { // checks if the first element is 0
			if (input[1] == 'x') convert(input, "hexadecimal"); // if the input is hexadecimal and checks if second elemnt is x
			else convert(input, "octal"); // if the input is octal
		}
		else convert(input, "decimal"); // if the input is decimal 
	}
	return 0;
}
