#include <cctype>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{

	string s;
	cout << "Please enter a string:";
	getline(cin, s); // gets a string from command line

	//printing output
	cout << "Character classification:\n";
	for (int i = 0; s[i] != '\0'; i++) // for loop until 
	{
		cout << s[i] << " :"; // prints and iterates through the string 
		char c = s[i];
		// this parts just reads from the stroustrup textbook 
		if (isspace(c))
			cout << " Space\n";
		if (isalpha(c))
			cout << " Alphabet\n";
		if (isdigit(c))
			cout << " Digit\n";
		if (isxdigit(c))
			cout << " Hex Digit \n";
		if (isupper(c))
			cout << " Uppercase letter\n";
		if (islower(c))
			cout << " Lowercase letter\n";
		if (isalnum(c))
			cout << " Alphanumeric\n";
		if (iscntrl(c))
			cout << " Control character\n";
		if (ispunct(c))
			cout << " Punctuation Mark \n";
		if (isprint(c))
			cout << " Printable \n";
		if (isgraph(c))
			cout << " Alpha, Digit, or Punctuation not Space\n";



	}

	return 0;
}