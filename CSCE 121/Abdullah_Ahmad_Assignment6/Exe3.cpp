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
	//  uses these to fill in the vector
	int hour; 
	double temp;
	
	string line;

	
	double mean;
	double median;
	
	vector<double> temps; // vector full of doubles
	
	ifstream ist; 
	ist.open("raw_temps.txt"); // opens file
	while(!ist.eof()){ // reads until end of file
		getline(ist, line);
		istringstream data(line); // uses istringstream to sort 
		data >> hour; // takes out the hour
		data >> temp; // takes out the temp and fils in the vector
		temps.push_back(temp);
	}

	ist.close();
	for (int i = 0; i < 50; i++){
		mean += temps.at(i);
	}
	sort(temps.begin(), temps.end());
	mean = mean / 50; // finds mean
	median = temps.at(24); // median
	cout << "Mean is " << mean << "\n" << "Median is " << median; // prints
	return 0;
	
}