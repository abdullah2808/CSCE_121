#include <iostream>


using namespace std;

char *strdup(const char *s){ //duplicate function 
	
	int length;
	for (length = 0; s[length]!='\0'; length++){}

	char *duplicate; // creating the duplicate 
	duplicate = new char[length + 1]; // new heap 
	
	for (int i = 0; i < length; i++){ // iterating through to duplicate
		duplicate[i] = s[i];
	}
	
	duplicate[length] = '\0'; // makes the last thing \0
	return duplicate; // returing the duplicate 
	
}

int main() {
    /*
	I wasn't entirely sure how to test this so I copied my code from the previous assignment
	
	*/
	char a[256]; // char array size 256
	char *s; // char *s pointer array
	cout << "Please enter any string: \n";
	cin.getline(a,256); // gets in the string
	s = strdup(a); // creates a copy of A in S
	cout << s;
	
	// tested with the code for Exe 1
    return 0;
}