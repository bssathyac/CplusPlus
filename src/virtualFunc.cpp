#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>
 
class vBase
{
public:
    virtual void show() { cout<<" In vBase \n"; }
};
 
class vDerived: public vBase
{
public:
    void show() { cout<<"In vDerived \n"; }
};
 
int virtualFuncUsage1(void)
{
    cout<<"==============================> In Func virtualFuncUsage1 A \n";
    vBase *bp = new vDerived;
    bp->show();
 
    vBase &br = *bp;
    br.show();
    cout<<"==============================> In Func virtualFuncUsage1 B \n";

    vBase *bptr, b;
    vDerived d, *dptr;
    bptr = &d;
    bptr->show();
    bptr = &b;
    bptr->show();
    d.show();
    b.show();
    
    cout<<"==============================> In Func virtualFuncUsage1 C \n";
    //dptr = &b;  compilation error and first of All, this is meaningless since dptr can access base already with scope resolution operator
    //dptr = &d; exclude this line to cause invalid pointer access from next line
    //dptr->show(); crashes the prog exec abruptly and does not execute any further func calls in main
    //if (dptr == NULL) { cout << "unassigned pointer dptr \n"; }
    // dptr = dynamic_cast<vDerived*>(bptr); // base class does not have a derived class func imp in usual case since a new member will added with the base functionality
    dptr->vBase::show();

 
    return 0;
}

// CPP program to illustrate
// calling virtual methods in
// constructor/destructor
#include<iostream>
using namespace std;
 
class dog
{
public:
    dog()
    {
        cout<< "Constructor called" <<"\n";
        bark() ;
    }
 
    ~dog()
    {
        bark();
    }
 
    virtual void bark()
    {
        cout<< "Virtual method called" <<"\n";
    }
 
    void seeCat()
    {
        bark();
    }
};
 
class Yellowdog : public dog
{
public:
        Yellowdog()
        {
            cout<< "Derived class Constructor called" <<"\n";
        }
        void bark()
        {
            cout<< "Derived class Virtual method called" <<"\n";
        }
};
 
int virtualMethodCtorDtor()
{
    cout<<"==============================> In Func virtualMethodCtorDtor \n";
    Yellowdog d;
    d.seeCat();

    return 0;
}

class Base
{
public:
    Base() {cout << "baseClass ctor called \n"; }
    ~Base() {cout << "baseClass dtor called \n"; }
    void show() { cout<<" In Base \n"; }
};
 
class Derived: public Base
{
public:
    Derived() {cout << "derivedClass ctor called \n"; }
    ~Derived() {cout << "derivedClass dtor called \n"; }
    void show() { cout<<"In Derived \n"; }
};
 
int ctorDtorCallSeq(void)
{
    cout<<"==============================> In Func ctorDtorCallSeqA \n";
    Base *bp = new Derived;
    bp->show();
 
    Base &br = *bp;
    br.show();
    delete bp; 

    cout<<"==============================> In Func ctorDtorCallSeqB \n";
    Derived *dp = new Derived;
    delete dp;

    return 0;
}