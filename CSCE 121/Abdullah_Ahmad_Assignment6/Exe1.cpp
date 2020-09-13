#include<fstream>
#include<string>
#include<iostream>

using namespace std;
class Invalid_File{};

int main()
{
	int numb; // will hold the sum values
	int sum; // we will add the numbers up in this
	sum = 0;
	
	cout << "Please enter input file name: ";
	
	string sumfile;
	cin >> sumfile;
	
	ifstream ist; // takes user input for the file I could have predfined the file
	ist.open(sumfile.c_str()); // convert from string to char
	if (!ist){
			cout << "Cannot open input file " << sumfile << endl;
			throw Invalid_File();
		}
	while (ist >> numb) // takes in numbers seperated by white space
	{
		sum += numb;  // adds them to sum
	}
	ist.close();
	cout << "The sum of the integars in the file is : " << sum;
	return 0;
}

		