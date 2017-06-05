#include <bits/stdc++.h>
using namespace std;

#define INF 10000
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

// More efficient way

/*
int coin_change(int n, int m)
{
    int table[m+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(j >= coin[i]) table[j] += table[j - coin[i]];
        }
    }
    return table[m];
}
*/

// Minimum Number of coins to make the amount

/*
int tcoin[] = {7, 2, 3, 6};

int coin_change(int n, int m)
{
    int table[m+1];
    int keep_track[m+1]; // This array is for printing the coin combination

    for(int i = 1; i <= m; i++)
    {
        table[i] = INF;
        keep_track[i] = -1;
    }

    table[0] = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(j >= tcoin[i])
            {
                if(table[j - tcoin[i]] + 1 < table[j])
                {
                    table[j] = table[j - tcoin[i]] + 1;
                    keep_track[j] = i;
                }
            }
        }
    }

    // Now Printing the solution

    if(keep_track[m] == -1)
    {
        cout << "No solution" << endl;
        return table[m];
    }

    int start = m;

    while(start != 0)
    {
        cout << tcoin[keep_track[start]] << " ";
        start = start - tcoin[keep_track[start]];
    }

    cout << endl;

    return table[m];
}
*/

int main()
{
    //memset(dp, -1, sizeof(dp));

    //cout << coin_change(0, 0) << endl;
    //cout << coin_change(3, 5) << endl;
    cout << coin_change(4, 13) << endl;
    return 0;
}
