#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000

bool marked[M];
int bitPrime[M/64 + 2];

#define on(x) (bitPrime[x/64] & (1<<((x%64)/2)))
#define mark(x)  bitPrime[x/64] |= (1<<((x%64)/2))

/*
====== Normal Sieve ========= */
void sieve(int n){
    for(int i = 3; i*i < n; i += 2){
        if(marked[i] == false) { // i is a prime
            for(int j = i*i ; j <= n; j += i + i){
                marked[j] = true;
            }
        }
    }
}

bool isPrime(int n)
{
    if(n < 2) return false;
    else if(n == 2) return true;
    else if(!(n&1)) return false;
    return marked[n] == false;
}

/* =========== Bit Wise Sieve =============== */

void bitSieve(int n){
    for(int i = 3; i*i <= n; i += 2){
        if(!on(i)){
            for(int j = i*i; j <= n; j+= i + i){
                mark(j);
            }
        }
    }
}

bool isBitPrime(int num)
{
    return num > 1 && (num == 2 || ( (num&1) && !on(num)));
}

/* ============ Sieve for small Value ================
    const int = 35000;
    int sieve[200000];

    sieve[0] = sieve[1] = 1;
    for(int i = 2; i <= MAX; i++){

        if(sieve[i]) continue;
        primes.push_back(i);

        for(int j = i + i; j <= MAX; j += i) sieve[j] = 1;

    }
====================================================*/

int main()
{
    bitSieve(1000);

    for(int i = 2; i <= 100 ; i++)
        if(isBitPrime(i)) cout << i << " ";
    return 0;
}
