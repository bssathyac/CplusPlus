#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>

class Data
{
    public:
    int a;
    void print() 
    { 
        cout << "\n a is "<< a << "\n" ; 
    }

    int f(float num) 
    { 
        return (10 + num); 
    }

    int sub(int m, int b)
    {
        return (m - b);
    }

    int div(int m, int b) 
    {
        return (m / b);
    }
};

//using function pointer
int res1(int m, int n, Data* obj, int(Data::*fp)(int,int))
{
   return (obj->*fp)(m,n);
}

//using function pointer
int res2(int m, int n, Data* obj, int(Data::*fp2)(int,int))
{
   return (obj->*fp2)(m,n);
}

int functorExmple(void)
{
   Data ob;
   cout << "\nSubtraction is = " << res1(8,5, &ob, &Data::sub) << "\n";
   cout << "\nDivision is = " << res2(4,2, &ob, &Data::div) << "\n";

   return 0;
}

int (Data::*fp1) (float) = &Data::f;   // Declaration and assignment of func ptr
int (Data::*fp2) (float);        // Only Declaration of func ptr

typedef int Data::*my_pointer_to_member;
typedef int (Data::*my_pointer_to_function) (float);

int typedefUsedForReadbilty(void)
{
  my_pointer_to_member ptiptr = &Data::a;
  my_pointer_to_function ptfptr = &Data::f;
  Data xobject;
  xobject.*ptiptr = 10;
  cout << "The value of a is " << xobject.*ptiptr << "\n";
  (xobject.*ptfptr) (20);

  return 101;
}

int illustratePtrToClassMembrs(void)
{
    Data d, *dp;
    dp = &d;     // pointer to object
 
    int Data::*ptr=&Data::a;   // pointer to data member 'a'
    fp2 = &Data::f;   // Assignment of func ptr inside main() also possible

    d.*ptr=10;
    d.print(); // a is 10

    dp->*ptr=20;
    dp->print();

    cout <<
    (d.*fp1)(8.5)
    << "\n" <<
    (dp->*fp2)(10.5)
    << "\n" <<
    d.f(11.2)
    << "\n" <<
    typedefUsedForReadbilty();
    functorExmple();

    return 0;
}
