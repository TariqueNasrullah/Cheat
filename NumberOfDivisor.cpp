/*
   NUMBER OF DIVISORS

*/

#include <bits/stdc++.h>
using namespace std;

int countDivisors(int n);

int main()
{

}

int countDivisors(int n){
    int divisors = 0;

    for(int i = 1; i*i <= n; i++){
        if(i*i == n) divisors += 1;
        else if(n%i == 0) divisors += 2;
    }
    return divisors;
}
