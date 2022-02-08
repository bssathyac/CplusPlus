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

int getRemainder(int arg1, int arg2)
{
    int i_t_rmdr, t1, t2;
    if (arg1 > arg2)
    {
        t1 = arg1;
        t2 = arg2;
    }
    else
    {
        t2 = arg1;
        t1 = arg2;
    }

    i_t_rmdr = t1 % t2;

    return i_t_rmdr;
}

int checkGCD(int num1, int num2)
{
    int t_rmndr;
    static int t_min;

    t_rmndr = getRemainder(num1, num2);
    t_min = num1 < num2 ? num1 : num2;

    if (t_rmndr != 0)
    {
        checkGCD(t_rmndr, t_min);
    }

    return t_min;
}

int checkRecursion(void)
{
    checkFactorial();
    cout << checkGCD(18,48) << "\n";

    return 0;
}