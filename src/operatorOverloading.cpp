#include<iostream>
using namespace std;
 
class ComplexNum
{
    private:
        int real, img;
    public:
        ComplexNum(int r=0, int i=0):real(r), img(i) 
        {cout<<"ctor invoked with initializer list \n"; }

        void showCmplxNum() { cout<<real << " + i"<< img<<"\n"; }

        // This is automatically called when '+' is used with
    // between two Complex objects
    ComplexNum operator + (ComplexNum const &obj) {
         ComplexNum res;
         res.real = real + obj.real;
         res.img = img + obj.img;
         return res;
    }
    ComplexNum operator - (ComplexNum const &obj) {
         ComplexNum res;
         res.real = real - obj.real;
         res.img = img - obj.img;
         return res;
    }
};

int addComplexNos()
{
    ComplexNum z, x(1,2), y(3,4);
    z = x + y;
    z.showCmplxNum();
    return 0;
}

int subComplexNos()
{
    ComplexNum z, x(-1,-2), y(-3,-4);
    z = x - y;
    z.showCmplxNum();
    return 0;
}