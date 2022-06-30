#include <iostream>
#include <string> 
#include <cstdlib>

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


};

int main() {
    //testing 
    requestGeneration setUnitsObject;
    setUnitsObject.setUnits();
    
    
    return 0;
}