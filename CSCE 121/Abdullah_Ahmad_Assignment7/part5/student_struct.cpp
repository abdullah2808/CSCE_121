//Student Struct code:
#include <iostream>
#include <string>
using namespace std;
#include "student_structs.h"

Student::Student(int new_student_id, double new_gpa, string new_major)

{
	this->studentID = new_student_id;
	this->GPA = new_gpa;
	this->major = new_major;
}

Student::Student(int new_student_id, double new_gpa, string new_major, bool new_record_status)

{
	this->studentID = new_student_id;
	this->GPA = new_gpa;
	this->major = new_major;
	this->record_status = new_record_status;
}

bool Student::operator==(const Student& st)

{
	return(studentID == st.studentID && GPA == st.GPA &&
		(major.compare(st.major) == 0) && record_status == st.record_status);
}

void Student::print()

{
	cout << "Student ID: " << this->studentID << ", Student GPA: " << this->GPA
		<< ", Student Major: " << this->major << ", Student Record Status: "
		<< this->record_status << endl;
}
