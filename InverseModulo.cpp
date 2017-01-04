#include <bits/stdc++.h>
using namespace std;

// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y);

// Function to find modulo inverse of a
void modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if(g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
        int res = (x%m + m) % m;
        cout << "Modular multiplicative inverse is " << res << endl;
    }
}

int gcdExtended(int a, int b, int *x, int *y)
{
    //base case
    if(a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;  // To store of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive call
    *x = y1 - (b/a)*x1;
    *y = x1;

    return gcd;
}

int main()
{
    int a = 3, m = 6;

    modInverse(a, m);
}
