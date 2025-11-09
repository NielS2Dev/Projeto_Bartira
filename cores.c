#include <stdio.h>
#include <windows.h>

void mudarCor(int cor){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);

}


