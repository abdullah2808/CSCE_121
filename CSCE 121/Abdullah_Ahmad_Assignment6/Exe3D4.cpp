#include<fstream>
#include<string>
#include<iostream>
#include<vector>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;




int main()
{
	int hour;
	double temp;
	char type;
	string line;

	
	double mean;
	double median;
	vector<double> temps;
	ifstream ist; 
	ist.open("raw_temps.txt"); 
	while(!ist.eof()){
		getline(ist, line); // uses getline to get the data in
		istringstream data(line);
		data >> hour;
		data >> temp;
		data >> type; // to check for C
		if (type == 'c') (temp * 1.8) + 32; // converst temp to f if its c
		temps.push_back(temp);
	}

	ist.close();
	// calculations
	
	for (int i = 0; i < 50; i++){
		mean += temps.at(i);
	}
	sort(temps.begin(), temps.end());
	mean = mean / 50;
	median = temps.at(24);
	cout << "Mean is " << mean << "\n" << "Median is " << median;
	return 0;
	
}