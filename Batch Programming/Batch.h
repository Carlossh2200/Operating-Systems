#ifndef BATCH_H_INCLUDED
#define BATCH_H_INCLUDED

using namespace std;

class Batch{
private:
    string programmersName;
    char operation;
    unsigned int maximumEstimatedTime;
    int iD;
public:
    Batch(string programmersName,char operation,unsigned int maximumEstimatedTime,unsigned int iD);
    ~Batch(){}
    bool setProgrammersName(string n);
    bool setOperation(char o);
    bool setMaximunEstimatedTime(unsigned int t);
    bool setId(int i);
    string getProgrammersName();
    char getOperation();
    unsigned int getMaximumEstimatedTime();
    int getId();
};

Batch::Batch(string programmersName,char operation,unsigned int maximumEstimatedTime,unsigned int iD){
    this->setProgrammersName(programmersName);
    this->setOperation(operation);
    this->setMaximunEstimatedTime(maximumEstimatedTime);
    this->setId(iD);
}

bool Batch::setProgrammersName(string n){
    if (n.length()>0){
        programmersName=n;
        return true;
    }
    return false;
}

bool Batch::setOperation(char o){
    if (o == '+' || o == '-' || o == '*' || o == '/' || o == '%'){
        operation = o;
        return true;
    }
    return false;
}

bool Batch::setMaximunEstimatedTime(unsigned int t){
    if (t>0){
        maximumEstimatedTime = t;
        return true;
    }
    return false;
}

bool Batch::setId(int i){
    if (i >=0){
        iD = i;
        return true;
    }
    return false;
}

string Batch::getProgrammersName(){
    return this->programmersName;
}

char Batch::getOperation(){
    return this->operation;
}

unsigned int Batch::getMaximumEstimatedTime(){
    return this->maximumEstimatedTime;
}

int Batch::getId(){
    return this->iD;
}
#endif // BATCH_H_INCLUDED
