#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


void to_lower(char *s){

	int length;
	length = strlen(s); // finding length to iterate through 
	
	for (int i = 0; i < length; i++){
		if (s[i] >=65 && s[i] <= 90) // 65 to 90 are the values of upper case characters
		{
			s[i] = s[i] + 32; // by adding 32 to it we can get the lower case version
		}
		
	}
	cout << "The new lowercase string is : " << s; 
}
int main (){
	char a[256]; // char array size 256
	char *s; // char *s pointer array
	cout << "Please enter any string: \n";
	cin.getline(a,256); // gets in the string
	s = strdup(a); // creates a copy of A in S
	to_lower(s); // using the function above
	
	return 0;
	
}
