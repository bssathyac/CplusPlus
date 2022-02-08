// An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).
// The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.
// Write a function:
// vector<int> solution(vector<int> &A, int K);
// that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.
// For example, given
//     A = [3, 8, 9, 7, 6]
//     K = 3
// the function should return [9, 7, 6, 3, 8]. Three rotations were made:
//     [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
//     [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
//     [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
// For another example, given
//     A = [0, 0, 0]
//     K = 1
// the function should return [0, 0, 0]
// Given
//     A = [1, 2, 3, 4]
//     K = 4
// the function should return [1, 2, 3, 4]
// Assume that:
// N and K are integers within the range [0..100];
// each element of array A is an integer within the range [−1,000..1,000].

#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>

vector<int> solution1(vector<int> &A, int K)
{
    int sizeOfVec = A.size();
    int rotates = K % sizeOfVec;
    int idx;

    if (rotates != 0)
    {
        for (int i = 0; i < sizeOfVec;i++)
        {
            idx = (((sizeOfVec - rotates) + i) % sizeOfVec);
            A.push_back(A[idx]); // temporarily extending memory allocated for the vector
        }
        vector<int>::iterator it = A.begin();
        for (int k = 0; k < sizeOfVec; k++)
        {
            it = A.erase(it);
        }
    }

    return A;
}

vector<int> solution2(vector<int> &A, int K)
{
    int sizeOfVec = A.size();
    int rotates = K % sizeOfVec;
    int idx;

    if (rotates != 0)
    {
        for (int i = 1; i <= rotates;i++)
        {
            idx = (sizeOfVec - i);
            for (int j = (sizeOfVec -1); j > 0; j--)
            {
                swap(A[j],A[j-1]); // swap multiple times until the required num reaches the final pos
            }
        }
    }

    return A;
}

int checkRotateVec(void)
{
    vector<int> vecObj1 = {3,8,9,7,6};
    int K = 3;

    cout << "[ ";
    for (auto &it:vecObj1)
    {
        cout << it << " ";
    }
    cout << "] -"<< K << "-> ";

    cout << "[ ";
    for (auto &it:solution2(vecObj1, K))
    {
        cout << it << " ";
    }
    cout << "] -"<< K << "-> ";

    cout << "[ ";
    for (auto &it:solution1(vecObj1, K))
    {
        cout << it << " ";
    }
    cout << "]";

    return 0;
}

