#include <bits/stdc++.h>
using namespace std;
int coin[] = {1, 2, 3};
int n = 3;
int make = 5;

//Recursive Solution
/*

int dp[3+1][5+1];
int coin_change(int i, int m)
{
    if(i >= n)
    {
        if(m == make)
            return 1;
        else
            return 0;
    }

    int r1 = 0, r2 = 0;

    if(m+coin[i] <= make) r1 = coin_change(i, m+coin[i]);
    r2 = coin_change(i+1, m);

    return r1 + r2;
}
*/

// Top Down Method

/*
int coin_change(int n, int m)
{
    int table[n+1][m+1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0) table[i][j] = 0;
            else if(j == 0) table[i][j] = 1;

            else if(j < coin[i-1]) table[i][j] = table[i-1][j];

            else table[i][j] = table[i-1][j] + table[i][j - coin[i-1]];
        }
    }

    return table[n][m];
}
*/

int main()
{
    //memset(dp, -1, sizeof(dp));

    //cout << coin_change(0, 0) << endl;
    //cout << coin_change(3, 5) << endl;
    return 0;
}
