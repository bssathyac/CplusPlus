#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>
#include <bits/stdc++.h>

class primesN
{   
    private:
        int nMaxNum;
    public:
        int count;
        bool isPrime;
        typedef vector<int> vi;
        vi arr; vi::iterator it = arr.begin();
        primesN(int n): nMaxNum(n) { findprime(n); }
        int *arrayi =  new int(nMaxNum);
        bool findprime(int chkP)
        {
            isPrime = true;
            for(int i = 2; i <= (chkP/2); i++)
            { 
                if((chkP % i) == 0)
                {  isPrime = false; }
            }
            if(isPrime == true)
            { 
                cout << chkP << "\t";
            }

            return isPrime;
        }

        void printPrimes()
        {
            count = 0;
            cout << "\n";
            for(int k=2; k <= nMaxNum; k++ )
            { 
                if ( findprime(k) == true)
                {
                    arr.push_back(k);
                    count++;
                }
            }
            cout << count << "\n" ;

        }

        void printVec()
        {
            cout << "\n" << count << ">>>>";
            for(it = arr.begin(); it < arr.end(); it++) { cout << "\t" << *it; }
            cout << "\n" << count << ">>>>";
            for(int t = 0; t < arr.size(); t++) { cout << "\t" << arr[t]; }
            cout << "\n";
        }

};

int findPrimesbelowN()
{
    primesN a(311);
    a.printPrimes();
    a.printVec();

    return 0;
}

// C++ program to generate all prime numbers
// less than N in O(N)
#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;
 
// isPrime[] : isPrime[i] is true if number is prime
// prime[] : stores all prime number less than N
// SPF[] that store smallest prime factor of number
// [for Exp : smallest prime factor of '8' and '16'
// is '2' so we put SPF[8] = 2 , SPF[16] = 2 ]
vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);
 
// function generate all prime number less then N in O(n)
void manipulated_seive(int N)
{
    // 0 and 1 are not prime
    isprime[0] = isprime[1] = false ;
 
    // Fill rest of the entries
    for (long long int i=2; i<N ; i++)
    {
        // If isPrime[i] == True then i is
        // prime number
        if (isprime[i])
        {
            // put i into prime[] vector
            prime.push_back(i);
 
            // A prime number is its own smallest
            // prime factor
            SPF[i] = i;
        }
 
        // Remove all multiples of  i*prime[j] which are
        // not prime by making isPrime[i*prime[j]] = false
        // and put smallest prime factor of i*Prime[j] as prime[j]
        // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ]
        // so smallest prime factor of '10' is '2' that is prime[j] ]
        // this loop run only one time for number which are not prime
        for (long long int j=0;
             j < (int)prime.size() &&
             i*prime[j] < N && prime[j] <= SPF[i];
             j++)
        {
            isprime[i*prime[j]]=false;
 
            // put smallest prime factor of i*prime[j]
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}
void SieveOfEratosthenes(int n);
 
// driver  program to test above function
int sieveOFeratosthenes()
{
    int N = 311 ; // Must be less than MAX_SIZE
 
    manipulated_seive(N);
 
    // print all prime number less then N
    for (int i=0; i<prime.size() && prime[i] <= N ; i++)
        cout << prime[i] << " ";
 
        cout << "Following are the prime numbers smaller "
         << " than or equal to " << N << endl;
    SieveOfEratosthenes(N);

    return 0;
}

// C++ program to print all primes
// smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;
 
void SieveOfEratosthenes(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}
