all: proj4.exe
 
main.o: main.cpp LinkedNodeClass.h SortedListClass.h FIFOQueueClass.h LIFOStackClass.h
	g++ -std=c++98 -g -Wall -c main.cpp -o main.o
 
LinkedNodeClass.o: LinkedNodeClass.cpp LinkedNodeClass.h
	g++ -std=c++98 -g -Wall -c LinkedNodeClass.cpp -o LinkedNodeClass.o
  
SortedListClass.o: SortedListClass.cpp SortedListClass.h LinkedNodeClass.h
	g++ -std=c++98 -g -Wall -c SortedListClass.cpp -o SortedListClass.o
 
FIFOQueueClass.o: FIFOQueueClass.cpp FIFOQueueClass.h
	g++ -std=c++98 -g -Wall -c FIFOQueueClass.cpp -o FIFOQueueClass.o
 
LIFOStackClass.o: LIFOStackClass.cpp LIFOStackClass.h
	g++ -std=c++98 -g -Wall -c LIFOStackClass.cpp -o LIFOStackClass.o

proj4.exe: LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o main.o
	g++ -std=c++98 LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o main.o -o proj4.exe
 
clean:
	rm -f *.o *.exe
