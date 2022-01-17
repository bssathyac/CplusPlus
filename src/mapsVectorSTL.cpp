#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>
#include <vector>
#include <map>
#include "D:\TrialProjects\VSCode\InitCPP\header\linkedList.h" // ====HEADER .h file======// 

void checkVectorProps()
{
    vector<double> vec_t_tmp1, vec_t_tmp2;
    double dbl_t_tmpVar1;
    double *dbl_tp_tmp1;
    vector<double>::iterator itr_t_tmp1;
    vector<double>::iterator itr_t_tmp2;
    // vector<double>::reverse_iterator rev_itr_t_tmp1;
    // vector<double>::reverse_iterator rev_itr_t_tmp2;

    vec_t_tmp1.clear(); // Erases all the elements, user is responsible for deleting pointers if added to vector
    auto rev_itr_t_tmp1 = vec_t_tmp1.crbegin(); // const rev iterator
    auto rev_itr_t_tmp2 = vec_t_tmp1.crend(); // iterator that points to one before the last element
    // dbl_tp_tmp1 = vec_t_tmp1.data(); // Returns a pointer such that [data(), data() + size()) is a valid range
    // vec_t_tmp1.emplace(itr_t_tmp1, (double)100.55); // Inserts an object in %vector before specified iterator
    // vec_t_tmp1.emplace_back(rev_itr_t_tmp2, (double)100.55); // Inserts an object in %vector before specified rev iterator
    // vec_t_tmp1.empty(); // Returns true if the %vector is empty. (Thus begin() would equal end()
    // itr_t_tmp1 = vec_t_tmp1.end(); // Returns a read/write iterator that points one past the last element in the %vector. Iteration is done in ordinary element order.
    // vec_t_tmp1.erase(itr_t_tmp2); // erases element pointed by the iterator
    // vec_t_tmp2.assign(3, 100.66); // This function fills a %vector with __n copies of the given value. the original vector is lost
    // dbl_t_tmpVar1 = vec_t_tmp2.at(2); // the index of the element for which data should be accessed
    // dbl_t_tmpVar1 = vec_t_tmp2.back(); // Returns a read/write reference to the data at the last element of the %vecto
}

void spaceShipOperator()
{
    int c, a=10, b=20;
    c =  a < b;
    cout << c <<"/n";
}

void checkSTLvmProps()
{
    checkVectorProps();
    spaceShipOperator();
}

