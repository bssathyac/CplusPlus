#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>
#include <bitset> // not necessary just used for printing number in binary 

/* A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.
Write a function:
int solution(int N);
that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.
For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.
Write an efficient algorithm for the following assumptions:
N is an integer within the range [1..2,147,483,647].
*/
int solution(int N)
{
    int lsb, countGap = 0, tmp_cntGap = 0;
    bool start = false;
    /* Range given in problem is 0x1 to 0x7FFF FFFF  so 31 bits are to be checked */

    for (int bitCount = 0; bitCount < 31 && N > 0; bitCount++)
    {
        lsb = (N & 1); // check the lsb
        if (lsb == 1) 
        {
            start = true;
            if (tmp_cntGap > countGap) // start = false so stop and check
            {
                countGap = tmp_cntGap;
            }
            tmp_cntGap = 0;
        }
        else
        { 
            if(start == true) 
            {
                tmp_cntGap++; 
            }
        }
        N = N >> 1; // bitwise RightShift by 1
    }

    return countGap;
}

int checkBinaryGapSln(void)
{
    vector<int> vint_nums = {9, 529, 20, 15, 32, 1041};
    for (auto &it:vint_nums)
    {
        std::bitset<32> x(it);
        cout << solution(it) << "\t[" << it << "=\t"
             << x << "]\n";
    }

    return 0;
}