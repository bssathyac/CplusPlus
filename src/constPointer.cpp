#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>

int constPtrEg()
{
    
    int value1{ 11 }; // value is not constant
    int *ptr1{ &value1 }; // this is still okay
    *ptr1 = 12;

    int value4{ 44 }; // value is Not constant
    const int *ptr4{ &value4 };
    // *ptr4 = 12; Error since const value cannot be changed

    const int value2{ 22 };
    // int *ptr3{ &value2 }; // Error since const modification is not allowed and ref(used for modify) is contradicting the compiler
    const int* ptr2{ &value2 }; // this is okay, ptr is a non-const pointer that is pointing to a "const int"
    // *ptr2 = 6;  not allowed, we can't change a const value

    cout << value1 << "\n";

    int* ptr5;
    // ptr5 = ptr2; error since const int * cannot be assigned to int *
    
    return 0;
}
// auto, register, static and extern [typedef is also considered as a storage class specifier in C, C++ also]
// In addition to this C++, adds one important storage class specifier whose name is mutable.

// PROGRAM 1
#include <iostream>
using std::cout;
 
class Test {
public:
  int x;
  mutable int y;
  Test() { x = 4; y = 10; }
};

int f1(const int &arg1) //const              // a type qualifier is not allowed on a nonmember functionC/C++(1670)
{
    // arg1++; call of f1(t1.x) will not fail compilation only if const is added to the arg1, now arg1 cannot be modified
    cout <<"in Func f1()\t"<< arg1 << "\t";
    return 0;
}

// mutable is particularly useful if most of the members should be constant but a few need to be updateable. 
// Data members declared as mutable can be modified even though they are the part of object declared as const. 
// cannot use the mutable specifier with names declared as static or const, or reference.

int mutableStorageClassSpecifier()
{
    const Test t1;
    t1.y = 20;
    cout << t1.y << "\t";
    // t1.x = 8; // error: expression must be a modifiable lvalue , member x is const and hence not modifiable
    f1(t1.x); //qualifiers dropped in binding reference of type "int &" to initializer of type "const int"C/C++(433)
    cout << t1.x << "\t";
    
    return 0;
}

