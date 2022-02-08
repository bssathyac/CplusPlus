#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>
#include<exception>

class A
{
   public:
    //    int y[100];
       int *ptrA;
       A()
       {
           cout << " ctor of A";
           try
           {
               ptrA = new int[100];
           }
           catch (char *e)
           {
               cout << e;
           }
        }
};

class B: public A
{
	public:
        // int x[200];
        int *ptrB;
        B()
        {
            cout << " ctor of B";
            try
            {
                ptrB = new int[200];
            }
            catch (string e)
            {
                cout << e;
            }
        }
        // B(int a){cout << " parameterized ctor of B";}

};

int checkException(void)
{
        // B objB1(0);
        // A obja;
        // B objB3;
        string e;

        try
        {
            B objB;
            int s = sizeof(objB);
            cout << " Object of B created \n";
            throw e = " TRIED and THROWN ";
            cout << s;
        }
	    catch (char* f)
	    {
            cout << "\n1\t" << e << "\n2\t" << f;
        }

    return 0;
}