#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
#include "student_structs.h"

//Exceptions
class InvalidInsert{};
class InvalidRemove{};

//NOTE THAT I ALSO ADDED A "Student* next" TO MY STUDENT_STRUCTS.H FILE
typedef struct studentNode
{
public:
	Student stud;
	studentNode* nextPtr;
}studentNode;

class Singly_linked_list{
	private:
	studentNode* headPtr;
	int size;
    public:
    //constructors
    Singly_linked_list();
	Singly_linked_list(Student stud);
	~Singly_linked_list();
    //insert and remove functions
    void insertFirst(Student s);
    void insertAfter(Student s_old, Student s_new);
    void removeFirst();
    void removeAfter(Student s);

    void print_list();

    Student* get_head() const {return head;} //use this for the operator<< overload

    private:
    Student* head; //pointer so I can keep track of beginning of list
};

ostream& operator<<(ostream &out, Singly_linked_list &studList);

#endif