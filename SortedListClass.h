#ifndef SortedListClass_h
#define SortedListClass_h

#include "LinkedNodeClass.h"
//SortedListClass.h, project4
//Programmer: Tzu-Yu Peng, typeng
//Date: Nov 9th 2023
//This class does not store any data directly. Instead,
//it contains a collection of LinkedNodeClass objects, each of which
//contains one element.

class SortedListClass
{
  private:
    //Points to the first node in a list, or NULL
    //if list is empty.
    LinkedNodeClass *head;
  
    //Points to the last node in a list, or NULL
    //if list is empty.
    LinkedNodeClass *tail;
  
  public:
    //Default Constructor
    //Will initialize an empty list
    SortedListClass();
  
    //Copy Constructor, will make a deep copy of the list,
    //such that one can be changed without affecting the other
    SortedListClass(const SortedListClass &rhs);
  
    //Destructor, to clean the memory
    ~SortedListClass();
  
    //Assignment Opertator, will make lhs list to be a copy of rhs
    SortedListClass& operator=(const SortedListClass &rhs);
  
    //Clears the list to an empty state without resulting in any
    //memory leaks.
    void clear();
  
    //Insert the new node at the right position, so no need to specify index.
    //If new node vlue = existed node, insert after
    void insertValue(const int &valToInsert);
  
    //Prints the contents of the list from head to tail to the screen.
    void printForward() const;
  
    //Prints the contents of the list from tail to head to the screen.
    void printBackward() const;
  
    //This is for removing the first element
    bool removeFront(int &theVal);
  
    //This is for removing the last element
    bool removeLast(int &theVal);
  
    //Returns the number of nodes contained in the list.
    int getNumElems() const;
  
    //Provides the value stored in the node at index provided in the
    //0-based "index" parameter. If the index is out of range, then outVal
    //remains unchanged and false is returned. Otherwise, the function
    //returns true, and the reference parameter outVal will contain
    //a copy of the value at that location.
    bool getElemAtIndex(const int index,int &outVal) const;
};

#endif /* SortedListClass_h */
