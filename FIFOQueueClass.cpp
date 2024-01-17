#include "FIFOQueueClass.h"
#include <iostream>

using namespace std;
//FIFOQueueClass.cpp, project4
//Programmer: Tzu-Yu Peng, typeng
//Date: Nov 9th 2023
//This class is for making a Queue Data Structure.

//Note:: this class does not have copy ctor ot operator assignment
//using these will be a shallow copy

//Default Constructor
FIFOQueueClass::FIFOQueueClass(){
  head = 0;
  tail = 0;
}

//Destructor, making sure every dynamic memory is freed
FIFOQueueClass::~FIFOQueueClass(){
  clear();
}

//Inserts the value provided (newItem) into the queue.
void FIFOQueueClass::enqueue(const int &newItem){
  LinkedNodeClass *newQueue;
  //if empty Queue
  if((head == 0) && (tail == 0)){
    newQueue = new LinkedNodeClass(0, newItem, 0);
    head = newQueue;
    tail = newQueue;
  }
  //Not empty Queue
  else{
    newQueue = new LinkedNodeClass(tail, newItem, 0);
    newQueue->setBeforeAndAfterPointers();
    tail = newQueue;
  };
};


//Attempts to take the next item out of the queue. If the
//queue is empty, the function returns false and the state
//of the reference parameter (outItem) is undefined. If the
//queue is not empty, the function returns true and outItem
//becomes a copy of the next item in the queue, which is
//removed from the data structure.
bool FIFOQueueClass::dequeue(int &outItem){
  bool deOrNot;
  //if list is empty
  if((head == 0) && (tail == 0)){
    deOrNot = false;
    return deOrNot;
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
    deOrNot = true;
    return deOrNot;
  };
};


//Prints out the contents of the queue. All printing is done
//on one line, using a single space to separate values, and a
//single newline character is printed at the end. Values will
//be printed such that the next value that would be dequeued
//is printed first.
void FIFOQueueClass::print() const{
  LinkedNodeClass *printQueuePtr = head;
  while(printQueuePtr != 0){
    cout << printQueuePtr->getValue() << " ";
    printQueuePtr = printQueuePtr->getNext();
  }
  cout << endl;
};


//Returns the number of nodes contained in the queue.
int FIFOQueueClass::getNumElems() const{
  int count = 0;
  LinkedNodeClass *nodePtr = head;
  while(nodePtr != 0){
    count++;
    nodePtr = nodePtr->getNext();
  }
  return count;
};


//Clears the queue to an empty state without resulting in any
//memory leaks.
void FIFOQueueClass::clear(){
  while(head != 0){
    LinkedNodeClass *tmp;
    tmp = head;
    head = head->getNext();
    delete tmp;
  }
  head = 0;
  tail = 0;
};
