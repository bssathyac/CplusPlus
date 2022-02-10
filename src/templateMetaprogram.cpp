
#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>

// A C++ program to demonstrate working of non-type
// parameters to templates in C++.
#include <iostream>
using namespace std;

template <class T, int max>
int arrMin(T arr[], int n)
{
    int m = max;
    for (int i = 0; i < n; i++)
        if (arr[i] < m)
            m = arr[i];

    return m;
}

int checkNonTypeTemplate(void)
{
    int arr1[] = {10, 20, 15, 12};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    char arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    // Second template parameter to arrMin must be a constant
    cout << arrMin<int, 10000>(arr1, n1) << "\n";
    cout << arrMin<char, 256>(arr2, n2);
    return 0;
}


template<int n> struct powStrct
{
    enum { val = 2*powStrct<n-1>::val };
};
 
template<> struct powStrct<0>
{
    enum { val = 1 };
};

/* same as above */
template<int n> struct PowStrct2
{
    static const int val = 2*PowStrct2<n-1>::val;
};
  
template<> struct PowStrct2<0>
{
    static const int val = 1 ;
};

 
int checkTemplateMetaProg(void)
{
    cout << powStrct<8>::val << "\n";
    cout << powStrct<0>::val << "\n";
    cout << powStrct<10>::val << "\n";
    // int var = 2; COMPILER ERROR: expression must have a constant value : for next two lines
    // cout << powStrct<int>::val << "\n";
    // cout << powStrct<var>::val << "\n";
    checkNonTypeTemplate();

    return 0;
}
// Output:  256
// The program calculates “2 raise to the power 8 (or 2^8)”. In fact, the structure powStrct can be used to calculate 2^n for any known n (or constant n). The special thing about above program is: calculation is done at compile time. So, it is compiler that calculates 2^8. To understand how compiler does this, let us consider the following facts about templates and enums:
// 1) We can pass nontype parameters (parameters that are not data types) to class/function templates. 
// 2) Like other const expressions, values of enumeration constants are evaluated at compile time. 
// 3) When compiler sees a new argument to a template, compiler creates a new instance of the template.
// Let us take a closer look at the original program. When compiler sees powStrct<8>::val, 
// it tries to create an instance of powStrct with parameter as 8, it turns out 
// that powStrct<7> must also be created as enumeration constant val must be evaluated at 
// compile time. For powStrct<7>, compiler need powStrct<6> and so on. 
// Finally, compiler uses powStrct<1>::val and compile time recursion terminates. 
// So, using templates, we can write programs that do computation at compile time, 
// such programs are called template metaprograms. Template metaprogramming is in fact Turing-complete, 
// meaning that any computation expressible by a computer program can be computed, in some form, 
// by a template metaprogram. Template Metaprogramming is generally not used in practical programs, 
// it is an interesting concept though.
/*
1) Template is a feature of C++ that allows us to write one code for different data types.
2) We can write one function that can be used for all data types including user defined types. Like sort(), max(), min(), ..etc.
3) We can write one class or struct that can be used for all data types including user defined types. Like Linked List, Stack, Queue ..etc.
4) Template is an example of compile time polymorphism.
*/
template <typename T>
void fun(const T&x)
{
    static int count = 0;
    cout << "x = " << x << " count = " << count << "\n";
    ++count;
    return;
}
 
int tmpl1()
{
    fun<int> (1); 
    cout << "\n";
    fun<int>(1); 
    cout << "\n";
    fun<double>(1.1);
    cout << "\n";
    return 0;

    /* Compiler creates a new instance of a template function for every data type. So compiler creates two functions in the above example, one for int and other for double. Every instance has its own copy of static variable. The int instance of function is called twice, so count is incremented for the second call.
    */
}

template <typename T>
T max1(T x, T y)
{
    return (x > y)? x : y;
}
int tmpl2()
{
    cout << max1(3, 7) << "\n";
    cout << max1(3.0, 7.0) << "\n";
    // cout << max(3, 7.0) << "\n";  The first and second call to max function is a valid call as both the arguments passed are of same data type (i.e int and float respectively). 
    /* But the third call to max function has arguments of different data type and hence it will generate Compiler Error in last cout statement as call to max is ambiguous.  */
    return 0;
}

template <class T>
class Test
{
private:
    T val;
public:
    static int count;
    Test()  {   count++;   }
};
 
template<class T>
int Test<T>::count = 0;
 
int templ3()
{
    Test<int> a;
    Test<int> b;
    Test<double> c;
    cout << Test<int>::count   << "\n";
    cout << Test<double>::count << "\n";
/*There are two classes created by the template: Test and Test. Since count is a static member, every class has its own copy of it. Also, count gets incremented in constructor.*/

    return 0;
}

template<class T, class U>
class A  {
    T x;
    U y;
    static int count;
};
 
int templ4()  {
   A<char, char> a;
   A<int, int> b;
   cout << sizeof(a) << "\n";
   cout << sizeof(b) << "\n"; /* Since count is static, it is not counted in sizeof. */
   return 0;
}

/*templates can also have default parameters. The rule is same all default values must be on the rightmost side. Since count is static, it is not counted in sizeof.*/
template<class T, class U, class V=double>
class A1  {
    T x;
    U y;
    V z;
    static int count;
};
 
int templ5()
{
   A1<int, int> a;
   A1<double, double> b;
   cout << sizeof(a) << "\n";
   cout << sizeof(b) << "\n";
   return 0;
}

template <class T, int max>
int arrMin1(T arr[], int n)
{
   int m = max;
   for (int i = 0; i < n; i++)
      if (arr[i] < m)
         m = arr[i];
 
   return m;
}
 
int templ6()
{
   int arr1[]  = {10, 20, 15, 12};
   int n1 = sizeof(arr1)/sizeof(arr1[0]);
 
   char arr2[] = {1, 2, 3};
   int n2 = sizeof(arr2)/sizeof(arr2[0]);
 
   cout << arrMin1<int, 10000>(arr1, n1) << "\n";
   cout << arrMin1<char, 256>(arr2, n2);
   return 0;
}


// We can pass non-type arguments to templates. Non-type parameters are mainly used for specifying max or min values or any other constant value for a particular instance of template. The important thing to note about non-type parameters is, they must be const. Compiler must know the value of non-type parameters at compile time. Because compiler needs to create functions/classes for a specified non-type value at compile time. Following is another example of non-type parameters.


template < class T, int N >
 T fun (T arr[], int size)
{
    if (size > N)
      cout << "Not possible";
    T max = arr[0];
   for (int i = 1; i < size; i++)
      if (max < arr[i])
          max = arr[i];
   return max;
}

int templ7 ()
{
    int arr[] = {12, 3, 14};
    cout << fun<int,5>  (arr, 3);
    return 0;
}

template <int i>
void fun1()
{
   i = 20;
   cout << i;
}
 
int templ8()
{
//    fun<10>(); Compiler error in line "i = 20;" Non-type parameters must be const, so they cannot be modified.

   return 0;
}

template <class T>
T max2 (T &a, T &b)
{
    return (a > b)? a : b;
}
 
template <>
int max2 <int> (int &a, int &b)
{
    cout << "Called ";
    return (a > b)? a : b;
}
 
int templ9 ()
{
    int a = 10, b = 20;
    cout << max2 <int> (a, b);
    /*  template specialization. Sometime we want a different behaviour of a function/class template for a particular data type. For this, we can create a specialized version for that particular data type. */
    return 0;
}

