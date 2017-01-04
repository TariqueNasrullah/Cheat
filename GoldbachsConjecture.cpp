#include <bits/stdc++.h>
using namespace std;

int MAX = 32768;
int prime[32769];

void gen_primes() // Using Sieve
{
    memset(prime, 1, sizeof(prime));

    for(int i = 2; i <= sqrt(MAX); i++)
        if(prime[i])
            for(int j = i; j*i <= MAX; j++)
                prime[i*j] = 0;
}

int FindSol(int n)
{
    int res = 0;

    for(int i = 2; i <= n/2; i++)
    {
        if(prime[i] && prime[n-i])
        {
            printf("(%d %d)\n", i, n-i);
            res++;
        }
    }
    cout << endl;
    return res;
}
int main()
{
    gen_primes();

    cout << FindSol(10);
}
