#include<fstream>
#include<string>
#include<iostream>
#include <algorithm>


using namespace std;
class Invalid_File {};

int main()
{
	int numb; // will hold the sum values
	int sum; // we will add the numbers up in this
	sum = 0;
	string line;
	cout << "Please enter input file name: ";

	string sumfile;
	cin >> sumfile;

	ofstream ost;
	ost.open("LCase.txt");

	ifstream ist; // takes user input for the file I could have predfined the file
	ist.open(sumfile.c_str()); // convert from string to char
	if (!ist) {
		cout << "Cannot open input file " << sumfile << endl;
		throw Invalid_File();
	}

	while (getline(ist, line)) {
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		ost << line << "\n";
	}

	ist.close();

	return 0;
}
