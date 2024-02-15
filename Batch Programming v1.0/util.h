#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED
#include <iostream>
#include <cstring>

//para preguntar por Unix se usa __unix__
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void pause(){
    std::cout << "Presione entrar para continuar...\n";
    cin.get();
}

#endif // UTIL_H_INCLUDED
