#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include <stdlib.h>
using namespace std;

struct Reading{
	int hour; // hour after midnight
	double temperature; // in fahrenheight

};


int main()
{
	Reading R1;
	vector<Reading> readings; // vector full of readings
	for (int i = 0; i < 50; i++){
		R1.hour = rand() % 24; // randomizes the hour from 0 to 23
		R1.temperature = rand() % 100; // randomizes the temp from 0 to 100
		readings.push_back(R1);	 // pushes into a vector
	}
	ofstream ost; 
	ost.open("raw_temps.txt"); 
	for (int i = 0; i < 50; i++){
		ost << readings.at(i).hour << " " << readings.at(i).temperature << "\n"; // prints to file
	}
	ost.close();
	return 0;
	
}