#include "SortedListClass.h"
#include "LinkedNodeClass.h"
#include <iostream>

using namespace std;
//SortedListClass.cpp, project4
//Programmer: Tzu-Yu Peng, typeng
//Date: Nov 9th 2023
//This class does not store any data directly. Instead,
//it contains a collection of LinkedNodeClass objects, each of which
//contains one element.

//Default Constructor
//Will initialize an empty list
SortedListClass::SortedListClass(){
  head = 0;
  tail = 0;
};

//Copy Constructor, will make a deep copy of the list,
//such that one can be changed without affecting the other
SortedListClass::SortedListClass(const SortedListClass &rhs){
  head = 0;
  tail = 0;
  
  LinkedNodeClass *rhsNodePtr;
  rhsNodePtr = rhs.head;
  
  //Iterate through all the RHS node to copy the value
  while(rhsNodePtr != 0){
    insertValue(rhsNodePtr->getValue());
    rhsNodePtr = rhsNodePtr->getNext();
  }
};

//Destructor, to clean the memory.
SortedListClass::~SortedListClass(){
  clear();
};

//Assignment Opertator, will make lhs list to be a copy of rhs
SortedListClass& SortedListClass::operator=(const SortedListClass &rhs){
  if(this != &rhs){
    //need to clear the current list to assign rhs to here
    clear();
    LinkedNodeClass *rhsNodePtr;
    rhsNodePtr = rhs.head;
    while(rhsNodePtr != 0){
      insertValue(rhsNodePtr->getValue());
      rhsNodePtr = rhsNodePtr->getNext();
    }
  }
  return *this;
};

//Clears the list to en empty state to avoid memory leakage
void SortedListClass::clear(){
  while(head != 0){
    LinkedNodeClass *tmp;
    tmp = head;
    head = head->getNext();
    delete tmp;
  }
  head = 0;
  tail = 0;
}

//Insert the new node at the right position, so no need to specify index.
//If new node vlue = existed node, insert after
void SortedListClass::insertValue(const int &valToInsert){
  //check if list is empty
  if((head == 0) && (tail == 0)){
    //make new node
    LinkedNodeClass *newNode = new LinkedNodeClass(0, valToInsert, 0);
    head = newNode;
    tail = newNode;
  }
  //not empty list
  else{
    //made two pointer to know which one is where
    LinkedNodeClass *findPlaceHead = head;
    LinkedNodeClass *findPlaceBack = 0;
    
    //findPlaceHead != 0, means not tail
    //Second one means, value is smaller
    //This will make the valToInsert insert at the next node of findPlaceHead
    while((findPlaceHead != 0) && (findPlaceHead->getValue() <= valToInsert)){
      findPlaceBack = findPlaceHead;
      findPlaceHead = findPlaceHead->getNext();
    };
    //put at the front, if valToInert < head
    if(findPlaceBack == 0){
      LinkedNodeClass *newNode = new LinkedNodeClass(0, valToInsert, head);
      newNode->setBeforeAndAfterPointers();
      head = newNode;
    }
    //put at the last
    else if(findPlaceHead == 0){
      LinkedNodeClass *newNode = new LinkedNodeClass(tail, valToInsert, 0);
      newNode->setBeforeAndAfterPointers();
      tail = newNode;
    }
    else{
      LinkedNodeClass *newNode = new LinkedNodeClass(findPlaceBack,
                                                     valToInsert,
                                                     findPlaceHead);
      newNode->setBeforeAndAfterPointers();
    }
  }
};

//Prints the contents of the list from head to tail to the screen.
void SortedListClass::printForward() const{
  LinkedNodeClass *printNodePtr = head;
  cout << "Forward List Contents Follow:" << endl;
  while(printNodePtr != 0){
    cout << "  " << printNodePtr->getValue() << endl;
    printNodePtr = printNodePtr->getNext();
  }
  cout << "End Of List Contents" << endl;
};

//Prints the contents of the list from tail to head to the screen.
void SortedListClass::printBackward() const{
  LinkedNodeClass *printNodePtr = tail;
  cout << "Backward List Contents Follow:" << endl;
  while(printNodePtr != 0){
    cout << "  " << printNodePtr->getValue() << endl;
    printNodePtr = printNodePtr->getPrev();
  };
  cout << "End Of List Contents" << endl;
};

//This is for removing the first element
bool SortedListClass::removeFront(int &theVal){
  bool removeOrNot;
  //if list is empty
  if((head == 0) && (tail == 0)){
    removeOrNot = false;
    return removeOrNot;
  }
  else{
    theVal = head->getValue();
    LinkedNodeClass *frontPtr = head;
    head = head->getNext();
    
    //make the second to first, so need to set its prev = 0'
    //if it is the next node, set tail = 0
    if(head != 0){
      head->setPreviousPointerToNull();
    }
    else{
      tail = 0;
    }
    delete frontPtr;
    removeOrNot = true;
    return removeOrNot;
  };
};

//This is for removing the last element
bool SortedListClass::removeLast(int &theVal){
  bool removeOrNot;
  //if list is empty
  if((head == 0) && (tail == 0)){
    removeOrNot = false;
    return removeOrNot;
  }
  else{
    theVal = tail->getValue();
    LinkedNodeClass *backPtr = tail;
    tail = tail->getPrev();
    
    //make the second to first, so need to set its prev = 0
    if(tail != 0){
      tail->setNextPointerToNull();
    }
    else{
      tail = 0;
    }
    delete backPtr;
    removeOrNot = true;
    return removeOrNot;
  };
};

//Returns the number of nodes contained in the list.
int SortedListClass::getNumElems() const{
  int count = 0;
  LinkedNodeClass *nodePtr = head;
  while(nodePtr != 0){
    count++;
    nodePtr = nodePtr->getNext();
  }
  return count;
};

//get element Index
bool SortedListClass::getElemAtIndex(const int index, int &outVal) const{
  bool getOrNot = true;
  //if it is invalid index
  if(index < 0){
    getOrNot = false;
  }
  else if(index >= getNumElems()){
    getOrNot = false;
  }
  else{
    LinkedNodeClass *indexPtr = head;
    int nowIndex = 0;
    while(indexPtr != 0){
      if(nowIndex == index){
        outVal = indexPtr->getValue();
        getOrNot = true;
      };
      nowIndex++;
      indexPtr = indexPtr->getNext();
    };
  };
  return getOrNot;
};
