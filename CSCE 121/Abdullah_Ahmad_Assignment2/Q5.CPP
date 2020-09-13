#include<iostream>
using namespace std;


int main() {
	float quizTot; // declares the variables needed 
	float examTot;
	float AssnTot;
	float Total;
	int Quiz [3] = {}; // uses arrays to store grades 
	int Assn [4] = {};
	int Exam [2] = {};
	
	cout << "Enter 3 Quiz Grades (out of 10) Seperated by 1 space: \n"; // takes inputs for the grades
	cin >> Quiz[0] >> Quiz[1] >> Quiz[2] ;
	cout << "Enter 2 Exam Grades (out of 100) Seperated by 1 space: \n";
	cin >> Exam[0] >> Exam[1];
	cout << "Enter 4 Assignment Grades (out of 100) Seperated by 1 space: \n";
	cin >> Assn[0] >> Assn[1] >> Assn[2] >> Assn[3] ;
	
	
	for (int i=0; i<3; ++i){ // totals the inputs for the grades
		quizTot += Quiz[i];
	}
	for (int i=0; i<2; ++i){
	examTot += Exam[i];
	}
	for (int i=0; i<4; ++i){
	AssnTot += Assn[i];
	}

	quizTot = (quizTot * 10 / 3) * .12; // does some basic math to get total grade 
	examTot = (examTot / 2) * .60;
	AssnTot = (AssnTot / 4) * .28;

	Total = quizTot + examTot + AssnTot; 
	
	cout << "Your total grade is \: " << Total;
	return 0;
}