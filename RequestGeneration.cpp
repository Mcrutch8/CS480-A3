#include <iostream>
#include <string> 
#include <cstdlib>
#include <vector>
using namespace std;

class requestGeneration {
    public:
        int processID = 0;
        int units = 0;
        vector<int> procID;
        vector<int> memUnits;
        vector<vector<int>> allocateReq; 
        vector<int> deallocateReq;

        int setUnits() {
            // sets the number of memory units being requested
            // This sets the memory units for the request to be between 3 - 10  
            //srand(time(0));
            units = rand()%(10-3 + 1) + 3;
            std::string stringUnits = std::to_string(units);

            //cout << stringUnits << " units requested " << endl;
            return units;
        }

        int setID() {
            // every time this method is called the process id increments by one and returns the new ID
            processID++;
            return processID;
        }
        void allocationRequest() {
            

            // generating 30 request, each request has a process id and a number of memory units requested
            for(int i = 0; i < 30; i++) {
                vector<int> entry = {setID(), setUnits()};
                allocateReq.push_back(entry);
                //procID.push_back(setID());
                //memUnits.push_back(setUnits());
            }

        }
        void deallocationRequest() {
            // get a random process id to deallocate 
            int num;
	        //srand(time(0));
		    
            // sepcify the process id that needs to be deallocated
            for(int i = 0; i < 300; i++) {
                num = rand() % 29 + 1;
                deallocateReq.push_back(num);
            } 
        }


};
