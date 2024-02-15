#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cmath>
#include "Batch.h"
#include "Process.h"
#include "util.h"

#define BATCH_SIZE 4

using namespace std;
enum {CAPTURE=1,EXIT=2};

vector<Batch*> batchList;
vector<Process*> processes;
vector<Process*> terminatedProcesses;
vector<Batch*> currentBatch;



int mainMenu();
void batchExecution(int processes);
Process* captureData();
void batchMenu();

int mainMenu(){
    int menuOption=0;
    cout << "1. Capturar datos. " << "\n";
    cout << "2. Salir del programa. " << "\n";
    cout << "Opcion: ";
    cin >> menuOption;
    cin.get();
    return menuOption;
}

Process* captureData(){
    string userName;
    char userOperation;
    int userMaxTime=0,userId=0,numberA=0,numberB=0,result=0;
    bool rightOperation=false,rightEstimatedTime=false,rightId=false,divisionByZero=true;
    cout << "Nombre del programador: ";
    cin >> userName;
    cin.get();
    while(!rightOperation){
        cout << "Operacion a realizar (+,-,*,/,%): " ;
        cin >> userOperation;
        cin.get();
        if (userOperation == '+' || userOperation == '-' || userOperation == '*' ||
            userOperation == '/' || userOperation == '%'){
                rightOperation=true;
            }
        else{
            cout << "Operacion incorrecta, presione entrar para ingresarla de nuevo...\n";
            cin.get();
        }
    }


    while(divisionByZero){
        cout << "Dame el numero -A- para la operacion: ";
        cin >> numberA;
        cin.get();

        cout << "Dame el numero -B- para la operacion: ";
        cin >> numberB;
        cin.get();

        if ((numberA == 0 || numberB == 0) && (userOperation=='/' || userOperation=='%')){
            cout << "La division por cero no es definida, intente de nuevo...\n";
            pause();
        }
        else{
            divisionByZero=false;
        }

    }


    switch(userOperation){
        case '+':
            result=numberA+numberB;
            break;
        case '-':
            result=numberA-numberB;
            break;
        case '*':
            result=numberA*numberB;
            break;
        case '/':
            result=numberA/numberB;
            break;
        case '%':
            result=numberA%numberB;
            break;
        default:
            cout << "Error en la operacion...";
    }

    while(!rightEstimatedTime){
        cout << "Defina el Tiempo Maximo Estimado: ";
        cin >> userMaxTime;
        cin.get();
        if (userMaxTime>0){
            rightEstimatedTime=true;
        }
        else{
            cout << "Tiempo estimado no valido, intente de nuevo...\n";
        }
    }

    while(!rightId){
        cout << "Numero de programa (ID): ";
        cin >> userId;
        cin.get();
        rightId=true;
        for(auto batchPtr : batchList){
            for(auto process : batchPtr->processes){
                if (userId == process->getId()){
                cout << "ID ya registrado, intente otro ID...\n";
                rightId=false;
                cin.get();
                break;
            }
            }
        }
    }
    cout << "\n";
    return new Process(userName,userOperation,userMaxTime,userId,numberA,numberB,result);
}

void batchMenu(){
    int numberOfProcesses=0;
    cout << "Dame el numero de procesos: ";
    cin >> numberOfProcesses;
    cin.get();
    int batchNumber = ceil(static_cast<double>(numberOfProcesses)/BATCH_SIZE);
    int remainingProcesses = numberOfProcesses;

    for(int i=0;i<batchNumber;i++){
        Batch* batch = new Batch();
        int processesToAdd = min(BATCH_SIZE,remainingProcesses);
        for(int j=0;j<processesToAdd;j++){
        batch->processes.push_back(captureData());
        remainingProcesses--;
        system(CLEAR);
    }
    batchList.push_back(batch);
}
    batchExecution(numberOfProcesses);
}

void batchExecution(int numberOfProcesses){
    int mainCounter=1;
    int terminatedCounter=0;

    int pendingBatch=ceil(static_cast<double>(numberOfProcesses)/BATCH_SIZE);

    for(Batch* batch : batchList){
        for(Process* process : batch->processes){
            for(unsigned int j=0;j<process->getMaximumEstimatedTime();j++){
                cout << "Contador: " << mainCounter << "\n\n";
                cout << "Lotes pendientes: " << pendingBatch << "\n";\
                int secondaryCounter=0;
                for (Process* batchProcess : batch->processes) {
                cout << "ID: " << batchProcess->getId() << "  TME: "<<
                batchProcess->getMaximumEstimatedTime() << "/n";
                secondaryCounter++;
                if (secondaryCounter >= 4){
                    break;
                    pendingBatch--;
                }
            }
                cout << "\n\nProcesos terminados: \n";
                for(int k=0;k<terminatedCounter;k++){
                    cout << "ID: " << terminatedProcesses[k]->getId() << "\n";
                    cout << terminatedProcesses[k]->getNumberA() <<
                    terminatedProcesses[k]->getOperation() << terminatedProcesses[k]->getNumberB()<<
                    " = " << terminatedProcesses[k]->getResult() << "\n\n";
                }

                cout << "\n\nLote en ejecucion: \n";
                cout << "Nombre: " << process->getProgrammersName() << "\n";
                cout << "ID:     " << process->getId() << "\n";
                cout << "Operacion:         \n";
                cout << "Tiempo estimado:     " << process->getMaximumEstimatedTime() << "\n";
                cout << "Tiempo transcurrido: " << j << "\n";
                cout << "Tiempo restante:     " << process->getMaximumEstimatedTime()-j
                << "\t\t";
                sleep(1);
                mainCounter+=1;
                if (numberOfProcesses==1 && process->getMaximumEstimatedTime()-j==1){
                    pause();
                }
                system(CLEAR);
            }
            terminatedCounter++;
            terminatedProcesses.push_back(batch->processes.front());
            batch->processes.erase(batch->processes.begin());
            //currentBatch.erase(currentBatch.begin());
            numberOfProcesses-=1;
        }
        }
    }

    /*while(processes>0){

        for(int i=0;i<processes;i++){

            if (processes<4){
            pendingBatch=1;
            }
            else if (processes==0){
                pendingBatch=0;
            }
            else{
                pendingBatch = ceil(static_cast<double>(processes) / BATCH_SIZE);
            }


    }*/

int main()
{

    bool keepProgramRunning=true;

    while(keepProgramRunning){
        switch(mainMenu()){
        case CAPTURE:
            batchMenu();
            break;
        case EXIT:
            keepProgramRunning=false;
            break;
        default:
            cout << "Opcion no valida..." << "\n";
        }
        //(keepProgramRunning != false) ? pause() : void();
    }
    return 0;
}
