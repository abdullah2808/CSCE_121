#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include <stdlib.h>
using namespace std;

struct Reading{
	int hour; // hour after midnight
	double temperature; // in fahrenheight
	char type;

};


int main()
{
	int type;
	Reading R1;
	vector<Reading> readings;
	
	for (int i = 0; i < 50; i++){
		R1.hour = rand() % 24;
		R1.temperature = rand() % 100;
		type = rand() % 2;
		if (type == 1) R1.type = 'c'; // randomizes to get c or f which is 0 or 1 
		else R1.type = 'f';
		readings.push_back(R1);	
	}
	
	ofstream ost; 
	ost.open("raw_temps.txt"); 
	for (int i = 0; i < 50; i++){
		ost << readings.at(i).hour << " " << readings.at(i).temperature << " " << readings.at(i).type <<"\n";
	}
	ost.close();
	return 0;
	
}