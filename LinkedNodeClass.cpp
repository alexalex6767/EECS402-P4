#include "LinkedNodeClass.h"
//LinkedNodeClass.cpp, project4
//Programmer: Tzu-Yu Peng, typeng
//Date: Nov 9th 2023
//The list node class will be the data type for individual nodes of
//a doubly-linked data structure.

//This is the only constructor
LinkedNodeClass::LinkedNodeClass(LinkedNodeClass *inPrev,
                                 const int &inVal,
                                 LinkedNodeClass *inNext){
  prevNode = inPrev;
  nodeVal = inVal;
  nextNode = inNext;
};

//This is the function for getting the value of the node.
int LinkedNodeClass::getValue() const{
  return nodeVal;
};

//This is the function for getting the next node, whole node!
LinkedNodeClass* LinkedNodeClass::getNext() const{
  return nextNode;
};

//This is the function for getting the previous node, whole node!
LinkedNodeClass* LinkedNodeClass::getPrev() const{
  return prevNode;
};

//This is the function for setting the next node pointer to NULL
void LinkedNodeClass::setNextPointerToNull(){
  nextNode = 0;
};

//This is the function for setting the prev node pointer to NULL
void LinkedNodeClass::setPreviousPointerToNull(){
  prevNode = 0;
};

//This function is for linking the previous and next node to this node.
//Will need to make previous node's next node = this node.
//Will need to make next node's prevNode p this node.
void LinkedNodeClass::setBeforeAndAfterPointers(){
  if(nextNode != 0){
    if(prevNode != 0){
      //this means it is in the middle of the list
      prevNode->nextNode = this;
      nextNode->prevNode = this;
    }
    else{
      //this means it is at the first
      nextNode->prevNode = this;
    };
  }
  else{
    prevNode->nextNode = this;
  };
};
