#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
// Function to reverse a string without any built in methods
void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]); // Swap utility function is available from std namespace
}
 
// Driver program
int swapStringfromMiddle()
{
    string str = "The String reverse by swapping from Mid";
    reverseStr(str); // passed by ref, so reverses the original string data
    cout << str << "\n";
    return 0;
}

int swapStringwithInBuiltReverseMethod() // #include <bits/stdc++.h>
{
    string str = "The String reverse by using InBuilt method from bits/stdc++";
 // Reverse str[begin..end]
    reverse(str.begin(), str.end());
    cout << str << "\n";
    return 0;
}

// Function to print a string in reverse
void reversePrintString(string str)
{
   for (int i=str.length()-1; i>=0; i--)
      cout << str[i];
}

int reversePrintStringFunc()
{
    string str = " <> The String passed is just printed in reverse";
    reversePrintString(str); // passed by ref, so reverses the original string data
    cout << str << "\n";
    return 0;
}

// Function to reverse string and return
// reverse string pointer of that
char* reverseConstString(char const* str)
{
    // find length of string
    int n = strlen(str);
 
    // create a dynamic pointer char array
    char *rev = new char[n+1];
 
    // copy of string to ptr array
    strcpy(rev, str);
 
    // Swap character starting from two
    // corners
    for (int i=0, j=n-1; i<j; i++,j--)
        swap(rev[i], rev[j]);      
     
    // return pointer of the reversed string
    return rev;
}
 
// Driver code
int revStrPassedAsConst(void)
{
    const char *s = "The string passed as const char pointer is reversed";
    printf("%s \n", reverseConstString(s));
    return (0);
}

int mrevStrByConstructrUsage()
{
 
    string str = "Thus the string is reversed with constructors";
 
    //Use of reverse iterators
    string rev = string(str.rbegin(),str.rend());
 
    cout<<rev<<endl;
    return 0;
}

int revStrUsingTempStrPushBack()
{
 
    string str = "Use a temp string and push back method of String class to reverse";
    int n=str.length();
    //Temporary string to store the reverse
    string rev;
    for(int i=n-1;i>=0;i--)
      rev.push_back(str[i]);
   
    cout<<rev<<endl;
    return 0;
}

int getTheStringLength()
{
    // String obj
    string str = "HEllo6";
  
    // 1. size of string object using size() method
    cout << str.size() << " : Method 1 str.size() \n ";
  
    // 2. size of string object using length method
    cout << str.length() << " : Method 2 str.length() \n ";
  
    // 3. size using old style
    // size of string object using strlen function
    cout << strlen(str.c_str()) << " : Method 3 strlen(str.c_str()) \n ";
  
    // The constructor of string will set it to the
    // C-style string,
    // which ends at the '\0'
  
    // 4. size of string object Using while loop
    // while 'NOT NULL'
    int i = 0;
    while (str[i])
        i++;
    cout << i << " : Method 4 count in while loop till \\0 reached \n ";
  
    // 5. size of string object using for loop
    // for(; NOT NULL 😉
    for (i = 0; str[i]; i++)
        ;
    cout << i << " : Method 5 count in for loop till \\0 reached \n ";
  
    return 0;
}