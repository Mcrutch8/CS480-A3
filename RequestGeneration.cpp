#include <iostream>
#include <string> 
#include <cstdlib>
#include <vector>
using namespace std;

class requestGeneration {
    public:
        int processID = 0;
        int units = 0;

        int setUnits() {
            // sets the number of memory units being requested
            // This sets the memory units for the request to be between 3 - 10  
            srand(time(0));
            units = rand()%(10-3 + 1) + 3;
            std::string stringUnits = std::to_string(units);

            cout << stringUnits << " units requested " << endl;
            return units;
        }

        int setID() {
            // every time this method is called the process id increments by one and returns the new ID
            processID++;
            return processID;
        }
        void allocationRequest() {
            vector<int> procID;
            vector<int> memUnits;

            // generating 100 request, each request has a process id and a number of memory units requested
            for(int i = 0; i < 100; i++) {
                procID.push_back(setID());
                memUnits.push_back(setUnits());
            }

        }
        void deallocationRequest() {
            // get a random process id to deallocate 
            int num;
	        srand(time(0));
		    num = rand() % 99 + 1;
            vector<int> deallocateID;
            // sepcify the process id that needs to be deallocated
            for(int i = 0; i < 100; i++) {
                deallocateID.push_back(num);
            } 
        }


};

int main() {
    //testing 
    requestGeneration setUnitsObject;
    setUnitsObject.setUnits();
    
    
    return 0;
}