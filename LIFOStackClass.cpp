#include "LIFOStackClass.h"
#include <iostream>

using namespace std;
//LIFOStackCLass.cpp, project4
//Programmer: Tzu-Yu Peng, typeng
//Date: Nov 9th 2023
//This class is for making a stack data structure, LIFO!!!

LIFOStackClass::LIFOStackClass(){
  head = 0;
  tail = 0;
}

LIFOStackClass::~LIFOStackClass(){
  clear();
}


//Inserts the value provided (newItem) into the stack.
void LIFOStackClass::push(const int &newItem){
  LinkedNodeClass *newStack;
  //if empty list
  if((head == 0) && (tail == 0)){
    newStack = new LinkedNodeClass(0, newItem, 0);
    head = newStack;
    tail = newStack;
  }
  else{
    newStack = new LinkedNodeClass(0, newItem, head);
    newStack->setBeforeAndAfterPointers();
    head = newStack;
  }
};


//Attempts to take the next item out of the stack. If the
//stack is empty, the function returns false and the state
//of the reference parameter (outItem) is undefined. If the
//stack is not empty, the function returns true and outItem
//becomes a copy of the next item in the stack, which is
//removed from the data structure.
bool LIFOStackClass::pop(int &outItem){
  bool popOrNot;
  //if stack is empty
  if((head == 0) && (tail == 0)){
    popOrNot = false;
    return popOrNot;
  }
  else{
    outItem = head->getValue();
    LinkedNodeClass *frontPtr = head;
    head = head->getNext();
    
    //make the second to first, so need to set its prev = 0
    //if it is the next node, set tail = 0
    if(head != 0){
      head->setPreviousPointerToNull();
    }
    else{
      tail = 0;
    };
    delete frontPtr;
    popOrNot = true;
    return popOrNot;
  }
};


//Prints out the contents of the stack. All printing is done
//on one line, using a single space to separate values, and a
//single newline character is printed at the end. Values will
//be printed such that the next value that would be popped
//is printed first.
void LIFOStackClass::print() const{
  LinkedNodeClass *printQueuePtr = head;
  while(printQueuePtr != 0){
    cout << printQueuePtr->getValue() << " ";
    printQueuePtr = printQueuePtr->getNext();
  }
  cout << endl;
};


//Returns the number of nodes contained in the queue.
int LIFOStackClass::getNumElems() const{
  int count = 0;
  LinkedNodeClass *nodePtr = head;
  while(nodePtr != 0){
    count++;
    nodePtr = nodePtr->getNext();
  }
  return count;
};


//Clears the stack to an empty state without resulting in any
//memory leaks.
void LIFOStackClass::clear(){
  while(head != 0){
    LinkedNodeClass *tmp;
    tmp = head;
    head = head->getNext();
    delete tmp;
  }
  head = 0;
  tail = 0;
};
