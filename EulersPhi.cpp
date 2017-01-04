#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

// C program to calculate Euler's Totient function
// Using Euler''s product formula

int phi(int n)
{
    float result = n;  // Initialize result as n

    // consider all prime factor of n and for every prime
    // factor p, multiply result with (1-1/p)

    for(int p = 2; p*p <= n; ++p)
    {
        // Check if p is a prime factor
        if(n % p == 0)
        {
            // If yes then update n and result
            while(n % p == 0)
                n /= p;
            result *= (1.0 - (1.0 / (float) p));
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (there can be at-most one such prime factor)
    if(n > 1)
        result *= (1.0 - (1.0/(float) n));

    return (int)result;
}
int phiTry(int n)
{
    float result = n;

    for(int p = 2; p*p <= n; p++)
    {
        if(n%p == 0)
        {
            while(n%p == 0)
                n /= p;
            result *= (1.0 - (1.0/(float) p));
        }
    }
    if(n > 1)
        result *= (1.0 - (1.0/(float)n));

    return (int)result;
}

int main()
{
    for(int n = 1; n <= 10; n++)
    {
        printf("Phi(%d) = %d  ", n, phi(n));
        printf("Phi(%d) = %d\n", n, phiTry(n));
    }


    return 0;
}
