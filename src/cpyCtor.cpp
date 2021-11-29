
#include<iostream>
#include<cstring>
using namespace std;
 
class myStr
{
private:
    char *s;
    int size;
public:
    myStr(const char *str = NULL); // constructor
    ~myStr() { delete [] s;  }// destructor
    myStr(const myStr&); // copy constructor
    void print() { cout << s << endl; } // Function to print string
    void change(const char *);  // Function to change
};
 
myStr::myStr(const char *str)
{
    size = strlen(str); // cstring header has the strlen()
    s = new char[size+1];
    strcpy(s, str); // cstring header has the strcpy()
}
 
void myStr::change(const char *str)
{
    delete [] s;
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}
 
myStr::myStr(const myStr& old_str)
{
    size = old_str.size;
    s = new char[size+1];
    strcpy(s, old_str.s);
}

void withCpyCtor()
{
    printf( "withCpyCtor(); \n");
    myStr str1("str1 will be copied to str2 when executed str2 = str1");
    myStr str2 = str1;
 
    cout << "Before >> \n";
    str1.print();
    str2.print();
 
    cout << "After calling obj.change()>> \n";

    str2.change("Change the str2 obj and str1 remains unchanged");
    str1.print();
    str2.print();
}

class myStr2
{
private:
    char *s;
    mutable int size;
public:
    myStr2(const char *str = NULL); // constructor
    ~myStr2() { delete [] s;  }// destructor
    // myStr2(const myStr2&); // No explicit copy constructor 
    void print() { cout << s << endl; } // Function to print string
    void change(const char *);  // Function to change
    int getSize() const {return size; } // Function to change
};
 
myStr2::myStr2(const char *str)
{
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}
 
void myStr2::change(const char *str)
{
    delete [] s;
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}


void withOutCpyCtor()
{
    printf( "withOutCpyCtor(); \n");
    myStr2 str1("str1 will be copied to str2 when executed str2 = str1");
    myStr2 str2 = str1;
 
    cout << "Before >> \n";
    str1.print();
    str2.print();
    cout << "After calling obj.change() >> \n";
    str2.change("Str1 also changed! Not good !!");

    str1.print(); 
    str2.print();

    cout << "Notice this as well: if the strlen of latest changed str is more than the original strlen in str1 \n str1's string is corrupted ! not good at all >> ";
    str2.change("This is string is really long and longer than the string in str1");
    cout << "str1 :"; str1.print();
    cout << str1.getSize() << " < " << str2.getSize() << "\n";

    myStr2 str3("str3 will be copied to str4 when executed str4 = str3 as assign ");
    myStr2 str4 = str3;
    cout << "Before >> \n";
    str3.print();
    str4.print();
    cout << "After calling obj.change() >> \n";
    str4.change("This is string is really long and longer than the string in str3 and more chars but still works,\
     so lets see how far can this be taken  : Repeat :This is string is really long and longer than the string \
     in str3 and more chars but still works, so lets see how far can this be taken :: Repeat:: This is string \
     is really long and longer than the string in str3 and more chars but still works, so lets see how far can \
     this be taken  : Repeat :This is string is really long and longer than the string in str3 and more chars \
     but still works, so lets see how far can this be taken :::Repeat:::\
     This is string is really long and longer than the string in str3 and more chars but still works,\
     so lets see how far can this be taken  : Repeat :This is string is really long and longer than the string \
     in str3 and more chars but still works, so lets see how far can this be taken :: Repeat:: This is string \
     is really long and longer than the string>>983");// in str3 and more chars but still works, so lets see how far can \
     //this be taken  : Repeat :This is string is really long and longer than the string in str3 and more chars \
     //but still works, so lets see how far can this be taken"
    str3.print();
    cout << str3.getSize() << " < " << str4.getSize() << "\n";
    cout << sizeof(str3) << " < " << sizeof(str4) << "\n";


}

int copyCtorExplained()
{
    withCpyCtor();
    withOutCpyCtor();
    
    return 0;
}