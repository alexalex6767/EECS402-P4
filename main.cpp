#include <iostream>
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "LIFOStackClass.h"

using namespace std;

//main.cpp, project4
//Programmer: Tzu-Yu Peng, typeng
//Date: Nov 9th 2023
//This project is for creating 4 classes and three different data sctructures

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main(){
  SortedListClass testList;
  testList.printForward();
  testList.insertValue(42);
  testList.printForward();
  return 0;
}
#endif
