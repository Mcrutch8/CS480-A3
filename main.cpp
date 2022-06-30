#include "RequestGeneration.cpp"
#include "memory.cpp"
#include <iostream>
#include <string> 
#include <cstdlib>
#include <vector>

using namespace std;

int allocate_mem (int process_id, int num_units){
    int numNodesTrav = 0;

    int emptyCount = 0;
    temp = head;
    
    while(temp->prev == nullptr || temp->prev->value != 0 ){      //traverse through until it finds an empty space big enough to fit in
        if(temp->next == nullptr){
            return -1;
        }
        temp = temp->next;
        numNodesTrav++;   //calculate node traversal forwards or back, always add one
        if(temp->value == 0 && temp->prev->value == 0){
            emptyCount = emptyCount + 2;   //we need to start with adding 2 because the prev and current are zero
            while(temp->next->value == 0 && emptyCount <=10){
                temp = temp->next;    //while the next value is 0 keep on moving on to count empty spaces
                emptyCount++;   
                numNodesTrav++;

            }
        }
        if(emptyCount >= num_units){  //Successfully a big enough space: traverse back to start of empty space
            int overkill = emptyCount - num_units;    //calcualte how much more empty space there is than required and find the overkill
            for (int i= 0; i < emptyCount -1; i++){
                temp = temp->prev;
                if(i >= overkill - 1){    //use the overkill to correctly fill up the correct amount of num_units instead of the full empty space
                    temp->value = process_id;
                }
                numNodesTrav++;
                
            }
            return numNodesTrav;
    
        }
        else{ //failed, not big enough, move to the next temp so you are one extra ahgead because we are checking the previous
           temp = temp->next;
           numNodesTrav++; 
        }
        
        
    }

    return numNodesTrav;
}

int main() {
    createMemory(); //creates memory and prints the empyt 0 filled doubly linked list to the consol 
    requestGeneration Requests;
    Requests.allocationRequest();   //create the allocation requests
    Requests.deallocationRequest(); //create the deallocation requests

    cout << "deallocate:\n" << endl;           //print the deallocation requests
    for(int i=0; i <Requests.deallocateReq.size(); i++) {

       cout <<Requests.deallocateReq.at(i) <<' '; }

    cout<<endl;
    cout << "allocate:\n" << endl;            //print the allocation requests
    for(int i=0; i <Requests.allocateReq.size(); i++) {
        for (int j = 0; j < Requests.allocateReq[i].size(); j++)
        {
            cout << Requests.allocateReq[i][j] << " ";
        }  
        cout << ", "; 
    
    }
    cout << endl;
    cout << endl;
    allocate_mem(Requests.allocateReq[0][0],Requests.allocateReq[0][1]);  //allocate the first 3 pairs of requests
    allocate_mem(Requests.allocateReq[1][0],Requests.allocateReq[1][1]);
    allocate_mem(Requests.allocateReq[2][0],Requests.allocateReq[2][1]);
    
    traverse();   //print the doubly linked list again
    return 0;
}



