#include <string>
#include <fstream>
#include "singly_linked_list.h"
#include <iostream>

using namespace std;

// constructor

Singly_linked_list::Singly_linked_list() // null constructor 
{
     headPtr = NULL;
     size = 0;
}

Singly_linked_list::Singly_linked_list(Student stud) // consructor for linked list 

{
     headPtr = new studentNode;
     headPtr->stud = stud;
     headPtr->nextPtr = NULL;
     size = 0;
}

Singly_linked_list::~Singly_linked_list() // deconstructor 

{
     while (headPtr != NULL)
     {
          studentNode *temp = headPtr;
          headPtr = headPtr->nextPtr;
          delete(temp);
     }
}

void Singly_linked_list::insertFirst(Student stud) // defines inesrt after function 
{
     studentNode *newNode = new studentNode; // creates new student node
     newNode->stud = stud; // using new node to equal student 
     newNode->nextPtr = headPtr; // setting newnode to nextptr to equal head ptr
     headPtr = newNode; // basically moves everythign down 1 
     size++;

}

void Singly_linked_list::insertAfter(Student prevStud, Student stud) // defines the insertAfter function
{
     studentNode *newNode = new studentNode;
     newNode->stud = stud;
     newNode->nextPtr = NULL;
     studentNode *currStudNodePtr = headPtr;
     studentNode *prevStudNodePtr = NULL;
	 
     while (currStudNodePtr != NULL) // inserts stuff to the list directly after the prevstud
     {
          if (currStudNodePtr->stud == prevStud)
          {
              newNode->nextPtr = currStudNodePtr->nextPtr;
              currStudNodePtr->nextPtr = newNode;
              break;
          }
          prevStudNodePtr = currStudNodePtr;
          currStudNodePtr = currStudNodePtr->nextPtr;
     }
     prevStudNodePtr->nextPtr = newNode;
     size++;
}
void Singly_linked_list::removeFirst() // removes the first node 
{
     if (headPtr != NULL)
     {        
          studentNode *tempNode = headPtr;
          headPtr = headPtr->nextPtr;
          delete(tempNode); // deletes the temp node that was set to the headptr which is the first node 
          size--;
     }

}

void Singly_linked_list::removeAfter(Student prevStud) // removes before the given node
{
     studentNode *currStudNodePtr = headPtr; 
     studentNode *prevStudNodePtr = NULL;
     while (currStudNodePtr != NULL)
     {
          if (currStudNodePtr->stud == prevStud)
          {
              if (prevStudNodePtr != NULL)
              {
                   prevStudNodePtr->nextPtr = currStudNodePtr->nextPtr;
              }
              else
                   headPtr = currStudNodePtr->nextPtr;
              delete(currStudNodePtr);
              size--;
              return;

          }
          prevStudNodePtr = currStudNodePtr;
          currStudNodePtr = currStudNodePtr->nextPtr;
     }
}

void Singly_linked_list::print_list() // prints the list using function from class struct_cpp
{
     studentNode *currNodePtr = headPtr;
     if (currNodePtr == NULL)

     {
          cout << "The list is empty" << endl;
     }
     else
     {
          while (currNodePtr != NULL)
          {
              currNodePtr->stud.print();
              currNodePtr = currNodePtr->nextPtr;
          }
          cout << endl;
     }
}

ostream& operator<<(ostream &out, Singly_linked_list &studList) // for printing pulls the print function from the struct_cpp

{
     studList.print_list();
     return out;
}
