#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>
 
//// LIBRARY START
class Base
{
public:
  
    // The "Virtual Constructor"
    static Base *Create(int id);
  
    Base() 
    { 
        cout << "Action from Base" << "\n";
    }
  
    virtual // Ensures to invoke actual object destructor
    ~Base() 
    {
        cout << "Base destroyed" << "\n";
    }
  
    // An interface
    virtual void DisplayAction() = 0;
};
  
class Derived1 : public Base
{
public:
    Derived1()
    {
        cout << "Derived1 created" << "\n";
    }
  
    ~Derived1()
    {
        cout << "Derived1 destroyed" << "\n";
    }
  
    void DisplayAction()
    {
        cout << "Action from Derived1" << "\n";
    }
};
  
class Derived2 : public Base
{
public:
    Derived2()
    {
        cout << "Derived2 created" << "\n";
    }
  
    ~Derived2()
    {
        cout << "Derived2 destroyed" << "\n";
    }
  
    void DisplayAction()
    {
        cout << "Action from Derived2" << "\n";
    }
};
  
class Derived3 : public Base
{
public:
    Derived3()
    {
        cout << "Derived3 created" << "\n";
    }
  
    ~Derived3()
    {
        cout << "Derived3 destroyed" << "\n";
    }
  
    void DisplayAction()
    {
        cout << "Action from Derived3" << "\n";
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
    std::cout << r << "\t: ptr r addr" <<sizeof(r) << "\n";

    s->updateMyObj(10);
    s->printMyObj();
    std::cout << "\n";
    r->updateMyObj(22);
    r->printMyObj();
    std::cout << " = ";
    s->printMyObj();
    std::cout << "\n";

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

class MyClass1 {
   public:
      virtual void print()const {
         cout << "This is from MyClass1\n";
      }
};
class MyClass2 {
   public:
      virtual void print()const {
         cout << "This is from MyClass2\n";
      }
};
class MyClass3: public MyClass1, public MyClass2 {
   public:
      int myC3int = 10;

      void print()const {
         cout << "This is from MyClass3\n";
      }
};

struct A1 {
  virtual void f() { cout << "Class A1" << "\n"; }
};

struct B2 : public A1 {
  virtual void f() { cout << "Class B2" << "\n"; }
};

struct C3 : public A1 {
  virtual void f() { cout << "Class C3" << "\n"; }
};

void f(A1* arg) {
  B2* bp = dynamic_cast<B2*>(arg);
  C3* cp = dynamic_cast<C3*>(arg);

  if (bp)
    bp->f();
  else if (cp)
    cp->f();
  else
    arg->f();
};

int dynamicCastUsage2() {
  A1 aobj;
  B2 bobj;
  C3 cobj;
  A1* ap = &cobj;
  A1* ap2 = &aobj;
  A1* ap3 = &bobj;
  f(ap);
  f(ap2);
  f(ap3);

  return 0;
}

int dynamicCastUsage()
{
   MyClass1* a = new MyClass1;
   MyClass2* b = new MyClass2;
   MyClass3* c = new MyClass3;
   a -> print();
   b -> print();
   c -> print();
   b = dynamic_cast< MyClass2*>(a); //This cast will be failed
   if (b)
      b->print();
   else
      cout << "no MyClass2\n";
   a = c; // Explanation: A base class pointer can point to a derived class object, but we can only access base class member or virtual functions using the base class pointer because object slicing happens when a derived class object is assigned to a base class object. 
            //    Additional attributes of a derived class object are sliced off to form the base class object.
   a -> print(); //Printing from MyClass3
   b = dynamic_cast< MyClass2*>(a); //Successfully casting is done
   if (b)
      b -> print();
   else
      cout << "no MyClass2\n";
    
    dynamicCastUsage2();

      return 0;
}