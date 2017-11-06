#include <bits/stdc++.h>
using namespace std;

const int MAX = 35000;
int sieve[2000000];
vector<int> primes;

int countDivisors(int n);

int main()
{
    int n;
    cin >> n;

    sieve[0] = sieve[1] = 1;

    for(int i = 2; i <= n+1; i++){
        if(sieve[i]) continue;

        primes.push_back(i);
        for(int j = i + i; j <= n+1; j += i) sieve[j] = 1;
    }

    cout << countDivisors(n) << endl;

    return 0;
}

int countDivisors(int n){
    int divisors = 1;

    for(int i = 0; i < primes.size(); i++){
        if(n%primes[i] == 0){
            //cout << primes[i] << endl;
            int cnt = 1;
            while(n%primes[i] == 0){
                n /= primes[i];
                cnt++;
            }
            divisors *= cnt;
        }
    }
    return divisors;
}
