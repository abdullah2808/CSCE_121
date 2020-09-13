#include <iostream>
#include <string>
#include <fstream>
#include "singly_linked_list.h"

using namespace std;

int main()
{
     // some variables used to fill the list 

     int studID, statstud;
     double studentGPA;
     string studMajor;
     string studFileName;

     cout << "Enter the student file name: ";
     cin >> studFileName;
	 // takes user input for the file I could have predfined the file
	 ifstream inFile(studFileName.c_str());
     Singly_linked_list studentList;
	 
     if (inFile.is_open())
     {
          while (!inFile.eof())
          {
              inFile >> studID >> studentGPA >> studMajor >> statstud; // pulls in data 

              if (statstud == 0) // this part inserts it into the linked list 
              {
                   Student student(studID, studentGPA, studMajor, false);
                   studentList.insertFirst(student); // inserts at beginning
              }
              else
              {
                   Student student(studID, studentGPA, studMajor, true);
                   studentList.insertFirst(student); // inserts at beg
              }
          }
          inFile.close();
		  // you  can enter test values here 
          cout << "The Student List is : " << endl;
          cout << studentList;
		  // the current printed student list is the stuff pulled from the TXT file 
          Student stud1(927009064, 3, "ECEN", 0); // creates new things to insert
          Student stud(59321, 3.8, "PHYS", 1); // new thing 
          studentList.insertFirst(stud1); // insterting it at the beginning 
		  studentList.insertAfter(stud, stud1);
          Student stud2(49, 1.2, "ARCH", 0); // creates another thing to insert
          //studentList.insertAfter(stud1, stud); // inserts the new thing after the first thing inserted 
          cout << "Inserting New Objects at start and right after the start: " << endl;
          cout << studentList;
          studentList.removeAfter(stud1); // removes after stud1 
          cout << "Removing Object after Student " << endl;
          cout << studentList;
          studentList.removeFirst();
		  studentList.insertFirst(stud2);
          cout << "Removing first object and inserting new first object " << endl;
          cout << studentList;
     }
     else
     {
          cout << "File can't be found." << endl;
     }
	 
     return 0;
}