// A non-empty array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.
// For example, in array A such that:
//   A[0] = 9  A[1] = 3  A[2] = 9
//   A[3] = 3  A[4] = 9  A[5] = 7
//   A[6] = 9
// the elements at indexes 0 and 2 have value 9,
// the elements at indexes 1 and 3 have value 3,
// the elements at indexes 4 and 6 have value 9,
// the element at index 5 has value 7 and is unpaired.
// Write a function:
// int solution(vector<int> &A);
// that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.
// For example, given array A such that:
//   A[0] = 9  A[1] = 3  A[2] = 9
//   A[3] = 3  A[4] = 9  A[5] = 7
//   A[6] = 9
// the function should return 7, as explained in the example above.
// Write an efficient algorithm for the following assumptions:
// N is an odd integer within the range [1..1,000,000];
// each element of array A is an integer within the range [1..1,000,000,000];
// all but one of the values in A occur an even number of times.
#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>

int solution(vector<int> &A)
{
    vector<int>::iterator start_it, matched_it;
    int idx,passes = 0;
    bool match_not_found = false;

    start_it = A.begin();
    while (
        (A.size() > 1) &&
        (match_not_found != true)
        )
    {
        matched_it = A.begin();
        for (idx = 1; idx < A.size(); idx++)
        {
            // cout << A[0] <<" " << A[idx] <<" siz " << A.size()<<"\n"; 
            if (
                (A[0] == A[idx]) &&
                (A.size() > 1)
            )
            {
                A.erase(matched_it+idx);
                start_it = A.erase(start_it);
                passes = 0; // reset when match found while searching
            }
            else
            {   // complete the search until all the elements are touched
                passes++;
                if (
                    (A.size() > 1) &&
                    // (passes > A.size())
                    (passes >= (A.size() - 1))
                )
                {
                    match_not_found = true; // this will be true for multiple times after the last element was crossed and search restarted from begin
                    break;
                    // cout << passes << "\n";
                }
            }
        }
    }

    return A.at(0);
}

int checkOddOccurenceInVec(void)
{
    vector<int> vec1 = {100,97,52,15,51,9,3,256,1000,1000,65535,8,3,8,7,9,7,4,52,4,15,11,34,12,11,12,34,51,100,65535,256};
    cout << solution(vec1) << "\n";
    return 0;
}