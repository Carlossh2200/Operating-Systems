#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED

using namespace std;

class Process{
private:
    string programmersName;
    char operation;
    unsigned int maximumEstimatedTime;
    int iD;
    int numberA;
    int numberB;
    int result;
public:
    Process(string programmersName,char operation,unsigned int maximumEstimatedTime,unsigned int iD,
          int numberA,int numberB,int result);
    ~Process(){}
    Process& operator=(const Process& other) {
    if (this != &other) { // Self-assignment check
        // Copy the data members from 'other' to 'this'
        this->programmersName = other.programmersName;
        this->operation = other.operation;
        this->maximumEstimatedTime = other.maximumEstimatedTime;
        this->iD = other.iD;
        this->numberA = other.numberA;
        this->numberB = other.numberB;
        this->result = other.result;
    }
    return *this; // Return the current object
    }
    bool setProgrammersName(string n);
    bool setOperation(char o);
    bool setMaximunEstimatedTime(unsigned int t);
    bool setNumberA(int n);
    bool setNumberB(int n);
    bool setResult(int n);
    bool setId(int i);
    string getProgrammersName();
    char getOperation();
    unsigned int getMaximumEstimatedTime();
    int getNumberA();
    int getNumberB();
    int getResult();
    int getId();
};

Process::Process(string programmersName,char operation,unsigned int maximumEstimatedTime,unsigned int iD,
             int numberA,int numberB,int result){
    this->setProgrammersName(programmersName);
    this->setOperation(operation);
    this->setMaximunEstimatedTime(maximumEstimatedTime);
    this->setId(iD);
    this->setNumberA(numberA);
    this->setNumberB(numberB);
    this->setResult(result);
}

bool Process::setProgrammersName(string n){
    if (n.length()>0){
        programmersName=n;
        return true;
    }
    return false;
}

bool Process::setOperation(char o){
    if (o == '+' || o == '-' || o == '*' || o == '/' || o == '%'){
        operation = o;
        return true;
    }
    return false;
}

bool Process::setMaximunEstimatedTime(unsigned int t){
    if (t>0){
        maximumEstimatedTime = t;
        return true;
    }
    return false;
}

bool Process::setNumberA(int n){
    numberA=n;
    return true;
}

bool Process::setNumberB(int n){
    numberB=n;
    return true;
}

bool Process::setResult(int n){
    result=n;
    return true;
}

bool Process::setId(int i){
    if (i >=0){
        iD = i;
        return true;
    }
    return false;
}

string Process::getProgrammersName(){
    return this->programmersName;
}

char Process::getOperation(){
    return this->operation;
}

unsigned int Process::getMaximumEstimatedTime(){
    return this->maximumEstimatedTime;
}

int Process::getNumberA(){
    return this->numberA;
}

int Process::getNumberB(){
    return this->numberB;
}

int Process::getResult(){
    return this->result;
}

int Process::getId(){
    return this->iD;
}

#endif // PROCESS_H_INCLUDED
