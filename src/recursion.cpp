#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>


int getFact(int num=0)
{
    static int globalVar = 1;

    if(num > 0)
    {
        globalVar *= num;
        getFact(num-1);
    }

    return globalVar;
}

void checkFactorial()
{
    int f;
    cout << getFact(5) << "\n";
}