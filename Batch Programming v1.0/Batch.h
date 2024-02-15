#ifndef BATCH_H_INCLUDED
#define BATCH_H_INCLUDED
#include <vector>
#include <string>

#include "Process.h"

class Batch{
public:
    vector<Process*> processes;
    int batchNumber;
    ~Batch(){
        for(Process* process : processes){
            delete process;
        }
    }
private:
};

#endif // BATCH_H_INCLUDED
