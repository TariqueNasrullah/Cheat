#include <bits/stdc++.h>
using namespace std;

#define lli long long
lli m;

lli big_mod(lli n, lli p)
{
    if(p == 0) return 1;
    if(p%2 == 0)
    {
        lli ret = big_mod(n, p/2);
        return ((ret%m) * (ret%m))%m;
    }
    else return ((n%m) * (big_mod(n, p-1)%m))%m;
}

int main()
{
    m = 4;
    cout << big_mod(34, 1) << endl;;
}
