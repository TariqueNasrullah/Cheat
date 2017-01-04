#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(a == 0) return b;

    return gcd(b%a, a);
}

int main()
{
    int a = 888, b = 54;

    printf("GDC(%d %d) = %d\n", a, b, gcd(a, b));
    a = 10, b = 35;

    printf("GDC(%d %d) = %d\n", a, b, gcd(a, b));

    return 0;
}
