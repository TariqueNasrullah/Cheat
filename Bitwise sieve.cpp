#include <bits/stdc++.h>
using namespace std;

bool check(int n, int pos) { return (bool)(n & (1<<pos)); }
int Set(int n, int pos) { return n = n | (1<<pos);}

int n = 100;
int prime[100];
int status[100/32];
/*
void sieve()
{
    for(int i = 3; i <= sqrt(n); i += 2)
    {
        if(check(status[i/32], i%32) == 0)
        {
            for(int j = i*i; j <= n; j += i*2)
                status[j/32] = Set(status[j/32], j%32);
        }
    }
    puts("2");
    for(int i = 3; i <= n; i+= 2)
        if(check(status[i/32], i%32) == 0)
            cout << i << endl;
} */
void sieve()
{
    for(int i = 3; i <= sqrt(n); i += 2)
    {
        if(check(status[i>>5], i&32) == 0)
        {
            for(int j = i*i; j <= n; j += (i << 1))
                status[j>>5] = Set(status[j>>5], j&31);
        }
    }
    puts("2");
    for(int i = 3; i <= n; i += 2)
    {
        if(check(status[i>>5], i&31) == 0)
            cout << i << endl;
    }
}
int main()
{
    sieve();
    return 0;
}
