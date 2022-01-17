#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>
 
//// LIBRARY START
class Base
{
public:
  
    // The "Virtual Constructor"
    static Base *Create(int id);
  
    Base() 
    { 
        cout << "Action from Base" << endl;
    }
  
    virtual // Ensures to invoke actual object destructor
    ~Base() 
    {
        cout << "Base destroyed" << endl;
    }
  
    // An interface
    virtual void DisplayAction() = 0;
};
  
class Derived1 : public Base
{
public:
    Derived1()
    {
        cout << "Derived1 created" << endl;
    }
  
    ~Derived1()
    {
        cout << "Derived1 destroyed" << endl;
    }
  
    void DisplayAction()
    {
        cout << "Action from Derived1" << endl;
    }
};
  
class Derived2 : public Base
{
public:
    Derived2()
    {
        cout << "Derived2 created" << endl;
    }
  
    ~Derived2()
    {
        cout << "Derived2 destroyed" << endl;
    }
  
    void DisplayAction()
    {
        cout << "Action from Derived2" << endl;
    }
};
  
class Derived3 : public Base
{
public:
    Derived3()
    {
        cout << "Derived3 created" << endl;
    }
  
    ~Derived3()
    {
        cout << "Derived3 destroyed" << endl;
    }
  
    void DisplayAction()
    {
        cout << "Action from Derived3" << endl;
    }
};
  
// We can also declare "Create" outside Base
// But it is more relevant to limit it's scope to Base
Base *Base::Create(int id)
{
    // Just expand the if-else ladder, if new Derived class is created
    // User code need not be recompiled to create newly added class objects
  
    if( id == 1 )
    {
        return new Derived1;
    }
    else if( id == 2 )
    {
        return new Derived2;
    }
    else
    {
        return new Derived3;
    }
}
//// LIBRARY END
  
//// UTILITY START
class User
{
public:
    User() : pBase(nullptr)
    {
        // Receives an object of Base hierarchy at runtime
  
        int input;
  
        cout << "Enter ID (1, 2 or 3): ";
        cin >> input;
  
        while( (input !=  1) && (input !=  2) && (input !=  3) )
        {
            cout << "Enter ID (1, 2 or 3 only): ";
            cin >> input;
        }
  
        // Get object from the "Virtual Constructor"
        pBase = Base::Create(input);
    }
  
    ~User()
    {
        if( pBase )
        {
            delete pBase;
            pBase = nullptr;
        }
    }
  
    // Delegates to actual object
    void Action()
    {
        pBase->DisplayAction();
    }
  
private:
    Base *pBase;
};
  
//// UTILITY END
  
//// Consumer of User (UTILITY) class
int factoryCreateMethodDemo()
{
    cout << ">> Calling new operator \n";

    User *user = new User();

    cout << ">> Calling Action func with class obj \n";
    // Action required on any of Derived objects
    user->Action();

    cout << ">> obj declarations \n";
    // Derived1 der1;
    // Derived2 der2;
    // Derived3 der3;
    User usr;
  
    delete user;

    return 0;
}

class Singleton
{
    private:
        /* Here will be the static instance stored. */
        static Singleton* instance;
        int myobj;
        /* Private constructor to prevent instancing. */
        Singleton();
        Singleton(Singleton const&);
        void operator=(Singleton const&);

    public:
        /* Static access method. */
        static Singleton* getInstance();
        void updateMyObj(int arg=0){ myobj = arg;}
        void printMyObj() { cout << myobj;}
};

/* Null, because instance will be initialized on demand. */
Singleton* Singleton::instance = NULL;

Singleton* Singleton::getInstance()
{
    if (instance == NULL)
    {
        instance = new Singleton();
    }

    return instance;
}

Singleton::Singleton()
{}

//// Consumer of S (UTILITY) class
int singletonMethodDemo()
{
    //new Singleton(); // Won't work
    Singleton* s = Singleton::getInstance(); // Ok
    Singleton* r = Singleton::getInstance();

    /* The addresses will be the same. */
    std::cout << s << "\t: ptr s addr" <<sizeof(s) << "\n";
    std::cout << r << "\t: ptr t addr" <<sizeof(r) << "\n";

    s->updateMyObj(10);
    s->printMyObj();
    std::cout << std::endl;
    r->updateMyObj(22);
    r->printMyObj();
    std::cout << " = ";
    s->printMyObj();
    std::cout << std::endl;

    return 0;
}

class A {
public:
    virtual void show()
    {
        cout << "Hello form A \n";
    }
};
  
class B : virtual public A {
//
    public:
    void show()
    {
        cout << "Hello form B \n";
    }
//
};
  
class C : virtual public A {
};
  
class D : public B, public C {
};
  
A* f(B* b) { return b; }
A* g(C* c) { return c; }

int diamondInheritanceCase() // code will not compile when B  and  C class are not virtual Derived of A class
{
    D object, dobj;
    B bObj;
    object.B::show();
    object.C::show();
    object.A::show();
    object.show();
    bObj.A::show();
    bObj.show();

    cout << "vTable mechanism importance \n";
    A *aptr; C cobj;
    cout << " Func f with dobj\n";
    aptr = f(&dobj);
    aptr->show();

    cout << " Func g \n";
    aptr = g(&cobj);
    aptr->show();

    cout << " Func f with bObj\n";
    aptr = f(&bObj);
    aptr->show();
    // derived class pointer casted to base which is not allowed without vTable inheritance
    A* A_ptr, a_Obj2;
    // B* B_ptr, b_Obj2;
    // C* C_ptr, c_Obj2;
    D* D_ptr, d_Obj2;
    cout << " Derived class D_ptr assigned with addr_of aObj causes compiler error if show Func is not Virtual \n";
    A_ptr = dynamic_cast<A*>(&d_Obj2);
    cout << "Late Binding / Dynamic binding with explicitly dynamic_cast operator \t"; A_ptr->show();
    D_ptr = dynamic_cast<D*>(A_ptr);// error
    D_ptr->show();

    return 0;
}

