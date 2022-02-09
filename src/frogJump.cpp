// A small frog wants to get to the other side of the road. The frog is currently located at position X and wants to get to a position greater than or equal to Y. The small frog always jumps a fixed distance, D.
// Count the minimal number of jumps that the small frog must perform to reach its target.
// Write a function:
// int solution(int X, int Y, int D);
// that, given three integers X, Y and D, returns the minimal number of jumps from position X to a position equal to or greater than Y.
// For example, given:
//   X = 10
//   Y = 85
//   D = 30
// the function should return 3, because the frog will be positioned as follows:
// after the first jump, at position 10 + 30 = 40
// after the second jump, at position 10 + 30 + 30 = 70
// after the third jump, at position 10 + 30 + 30 + 30 = 100
// Write an efficient algorithm for the following assumptions:
// X, Y and D are integers within the range [1..1,000,000,000];
// X ≤ Y.

#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>

int solution(int X, int Y, int D)
{
    int jumps = ((Y - X) / D);
    int deficit = ((Y - X) % D);
    if (deficit)
    {
        jumps++;
    }

    return jumps;
}

// A small frog wants to get to the other side of a river. The frog is initially located on one bank of the river (position 0) and wants to get to the opposite bank (position X+1). Leaves fall from a tree onto the surface of the river.
// You are given an array A consisting of N integers representing the falling leaves. A[K] represents the position where one leaf falls at time K, measured in seconds.
// The goal is to find the earliest time when the frog can jump to the other side of the river. The frog can cross only when leaves appear at every position across the river from 1 to X (that is, we want to find the earliest moment when all the positions from 1 to X are covered by leaves). You may assume that the speed of the current in the river is negligibly small, i.e. the leaves do not change their positions once they fall in the river.
// For example, you are given integer X = 5 and array A such that:
//   A[0] = 1
//   A[1] = 3
//   A[2] = 1
//   A[3] = 4
//   A[4] = 2
//   A[5] = 3
//   A[6] = 5
//   A[7] = 4
// In second 6, a leaf falls into position 5. This is the earliest time when leaves appear in every position across the river.
// Write a function:
// int solution(int X, vector<int> &A);
// that, given a non-empty array A consisting of N integers and integer X, returns the earliest time when the frog can jump to the other side of the river.
// If the frog is never able to jump to the other side of the river, the function should return −1.
// For example, given X = 5 and array A such that:
//   A[0] = 1
//   A[1] = 3
//   A[2] = 1
//   A[3] = 4
//   A[4] = 2
//   A[5] = 3
//   A[6] = 5
//   A[7] = 4
// the function should return 6, as explained above.
// Write an efficient algorithm for the following assumptions:
// N and X are integers within the range [1..100,000];
// each element of array A is an integer within the range [1..X]

int solution1(int X, vector<int> &A)
{
    int t_idx, strt_idx = 0, newIdx = -1, sum; // , calcSum;
    bool possible = false;
    // MATH HERE ::>> calcSum = ((X - 1) * (X)) / 2; // sum of ArithProg is [n(a+l)/2] here sum for nos from 1 to X-1 is only req

    while (
        (possible == false) &&
        (strt_idx < A.size()) // fail safe for infinite loop
    )
    {
        for (t_idx = strt_idx; t_idx < A.size(); t_idx++ )
        {   // get the index of final leaf
            if (A[t_idx] == X)
            {
                newIdx = t_idx;
                // cout << newIdx << " <nIdx\t";
                break;
            }
            else
            {
                newIdx = A.size(); // fail safe for infinite loop
            }
        }
        strt_idx = newIdx+1;

        sum = 0;
        for (int k = (X-1); k > 0; k--)
        { // check whether all values from 1 to X are present in the array before the last leaf pos idx
            for ( int t_idx = 0; t_idx < newIdx; t_idx++ )
            {
                if (A[t_idx] == k)
                {
                    // cout << A[t_idx] << " <ele\t";
                    // MATH HERE ::>> sum += A[t_idx];
                    sum++;
                    break;
                }
            }
            // cout << sum  << "y\t";
            // cout << k << "\t";
            // cout << sum << " <s\t";
        } // if NOT possible repeat process for next NEW idx
        // MATH HERE ::>> if (sum==calcSum) possible = true;
        if (sum == (X-1)) possible = true;
        // cout << possible << " <p\t";
    }
    
    return newIdx;
}

int checkFrogJmp(void)
{
    int strt = 10, end = 85, step = 30;
    cout <<"jump " << solution(strt, end, step) 
        << " times to reach from "<< strt <<" to " 
        <<end<< " at step size of " <<step<<" per jump \n";

    vector<int> vecObj = {1,3, 1, 3, 4, 3,5, 2, 3, 5, 2,4, 4, 3, 5, 2,1};
    int leaves = 5;
    cout << "Min time required to cross the river is " << solution1(leaves, vecObj)
         << " sec, since " << leaves << " leaves fall into place at that instance \n";

    return 0;
}