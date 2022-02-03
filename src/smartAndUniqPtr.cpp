#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>

// A generic smart pointer class
template <class T>
class SmartPtr {
    T* ptr; // Actual pointer
public:
    // Constructor
    explicit SmartPtr(T* p = NULL) { ptr = p; }
 
    // Destructor
    ~SmartPtr() { delete (ptr); ptr = NULL; }
 
    // Overloading dereferencing operator
    T& operator*() { return *ptr; }
 
    // Overloading arrow operator so that
    // members of T can be accessed
    // like a pointer (useful if T represents
    // a class or struct or union type)
    T* operator->() { return ptr; }
};

#include <memory>
 
class Rectangle {
    int length;
    int breadth;
 
public:
    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }
 
    int area(){
        return length * breadth;
    }
};
 
int uniquePtrUsage()
{
 
    unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << "\n" << P1->area() << endl; // This'll print 50
 
    // unique_ptr<Rectangle> P2(P1);
    unique_ptr<Rectangle> P2;
    P2 = move(P1);
 
    // This'll also print 50
    cout << P2->area() << "\n";
 
    // cout<<P1->area()<<endl;
    return 0;
}

typedef enum {
    what_int,
    what_float,
    what_string
} what_t;

void print_it(what_t what, void *value)
{
    switch (what) {
        case what_int:
            printf("It is an int: %d\n", * (int*) value);
            break;
        case what_float:
            printf("It is a float: %f\n", * (float*) value);
            break;
        case what_string:
            printf("It is a string: %s\n", (char*) value);
            break;
        default:
            printf("I don't understand what it is\n");
    }
}

int voidPtrUsage()
{
    float x = 12.34;
    void *vd_ptr = (void *)&x;
    // int y =  (int)*vd_ptr;
    int y =  *(int*)vd_ptr;
    float z =  *(float*)vd_ptr;
    int a = (int)x;
    cout << x << "\t" << vd_ptr << "\t" << y << "\t" << z << "\t" << a << "\n";

    int b = 2;
    // void *vd_ptr2 = (void *)&b;
    void *vd_ptr2 = &b;
    float c =  *(float*)vd_ptr2;
    int d =  *(int*)vd_ptr2;
    cout << c << "\t" << d << "\n";

        int i = 5;
    print_it(what_int, &i);

    float f = 3.1415;
    print_it(what_float, &f);

    char *s = "Hello world";
    print_it(what_string, s);

    return 0;
}

int smartPtrUsage()
{
    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr;
    uniquePtrUsage();
    voidPtrUsage();

    return 0;
}