#include <bits/stdc++.h>
using namespace std;
#define M 1000000
set<int> result;
/*
DONT USE UNTILL IF VALUES ARE SMALL

*/

void sieve(int n, vector<int> &prime){
    bool mk[n+1];
    memset(mk, false, sizeof(mk));

    for(int i = 2; i*i < n; i ++){
        if(mk[i] == false) { // i is a prime
            for(int j = i*2 ; j <= n; j += i){
                mk[j] = true;
            }
        }
    }

    for(int i = 2; i < n; i++){
        if(mk[i] == false){
            prime.push_back(i);
            result.insert(i);
        }
    }
}

void segmentedSieve(int low, int high){
    vector<int> prime;
    int limit = floor(sqrt(high)) + 1;
    sieve(limit, prime);

    int currentLow = low;
    if(low == 1) low = 2;
    int currentHigh = low+limit;
    if(currentHigh > high) currentHigh = high;

    while(currentLow <= high){
        bool marked[limit+1];
        memset(marked, false, sizeof(marked));

        for(int i = 0; i < prime.size(); i++){
            int loLim = floor(currentLow/prime[i] * prime[i]);
            if(loLim < currentLow) loLim += prime[i];

            for(int j = loLim; j <= currentHigh; j += prime[i])
                marked[j-currentLow] = true;
        }

        for(int i = currentLow; i <= currentHigh; i++)
        {
            if(i&1 && marked[i-currentLow] == false) result.insert(i);
        }

        currentLow = currentLow + limit;
        currentHigh = currentHigh + limit;

        if(currentHigh > high) currentHigh = high;
    }
}

int main()
{
    int t, low, high;
    long long ans;

    cin >> t;

    while(t--){
        cin >> low >> high;
        if(low = 1) low = 2;
        segmentedSieve(low, high);

        set<int>::iterator it;

        for(it = result.begin(); it != result.end(); it++)
            if((*it) >= low) break;

        for(; it != result.end(); it++)
            cout << *it << " ";

        result.clear();
    }
    return 0;
}
