#ifndef STUDENT_STRUCT_H
#define STUDENT_STRUCT_H
#include <iostream>
#include <string>
using namespace std;
struct Student
{
private:
	int studentID;
	double GPA;
	string major;
	bool record_status;
public:
	Student() {}
	Student(int, double, string);
	Student(int, double, string, bool);
	bool operator == (Student const&);
	void print();
};

#endif