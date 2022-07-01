Matthew Herron, Max Crutchfield
cssc0820, cssc0809
CS480 Summer S1 2022 
Assignment 3
README

files: main.cpp, memory.cpp, RequestGeneration.cpp, firstFit.cpp, bestFit.cpp, Makefile, README.txt, 
created files from Make: main.o, mot.exe


Compilation command:
 g++ -pthread -c main.cpp         first line compiles your main object file
 g++ -pthread main.o -o mot      will compile you final executable from the object file

 
Operation instructions: to compile use the make file found in this same directory(/a3), just type the 
 command "make" to start, to remove the object and executable files afterwards use the command "make clean".


--To start the program--
$ make
$ mot

--To clean up--
$ make clean


includes:
#include <iostream>
#include <string> 
#include <cstdlib>
#include <vector>


Process:
declared vars: 
     int processID, int units,  int num

AddToMemory():
    This function creates a new node for the linked list memory which is used as a block for this program

traverse():
this function traverses the linked list starting from the head node or first block

createMemory():
    This function creates our memory of 256KB divided into 128 2KB blocks  

int setUnits():
    This sets the memory units for the request to be between 3 - 10

int setID():
    Every time this method is called the process id increments by one and returns the new ID

void allocationRequest():
    This function creates allocation request and provides a process id and the number of memory units that process needs

void deallocationRequest():
    This function gives a random process ID to be deallocated

int allocate_mem(int process_id, int num_units):
    In this function we traverse through the linked list until we find the first fit or an empty space big enough 
    for the process to fit in. This function also keeps track of the empty space that is left after this allocation takes place.
    An overkill integer variable is used to correctly fill up the memory with the number of memory units requested in the allocation request.

int deallocate_mem(int process_id):
    This function ...



Known bugs:
Waiting till finished for this 

Lessons learned:
During this Assignment we learned a lot about memory allocation request and deallocation request. This Assignment
also gave us a better general idea of how memory works as a whole. We also learned how best fit and first fit algorithms
work and what their similarities and differences are.  
