//#include <iostream> not necessary until a built in header func is required to be used in this main.cpp file
#include "D:\TrialProjects\VSCode\InitCPP\header\cppFileHeaders.h"

int main(int argc, char *argv[])
{
    int n(10);
    double a[n][5];
    varArgfuncUsage();
    letterCountInString();
    swapStringfromMiddle();
    swapStringwithInBuiltReverseMethod(); // #include <bits/stdc++.h>
    reversePrintStringFunc();
    revStrPassedAsConst();
    mrevStrByConstructrUsage();
    revStrUsingTempStrPushBack();
    getTheStringLength();

   // callShapes3dInmain(argc, &argv[0]);
}
