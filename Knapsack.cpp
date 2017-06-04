#include <bits/stdc++.h>
using namespace std;

int W[] = {1, 3, 4, 5};
int val[] = {1, 4, 5, 7};

// Recursive
/*
int recur(int i, int s)
{
    if(s == 0)
        return 0;
    if(i >= n) return 0;

    if(coin[i] > s)
      return recur(i+1, s);
    return max(recur(i+1, s), coin[i] + recur(i+1, s - coin[i]));
}
*/

// Top-Down Method

int knapsack(int n, int w)
{
    int table[n+1][w+1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            if(i == 0 || j == 0)
                table[i][j] = 0;

            else if(j >= W[i-1]) table[i][j] = max(table[i-1][j], val[i-1]+table[i-1][j - W[i-1]]);

            else table[i][j] = table[i-1][j];
        }
    }

    return table[n][w];
}

// This is for "coin-change" can take one coin exactly
// and gives the maximum value can be made by those coin
/*
int table[25000+5];
coin[] = {1, 3, 4, 7};

int knapsack(int n, int w)
{
    for(int i = 0; i <= w; i++) table[i] = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = w; j > 0; j--)
        {
            if(coin[i] <= j) table[j] = max(table[j], coin[i] + table[j - coin[i]]);
        }
    }
    return table[w];
}
*/


int main()
{
    int ans = knapsack(4, 7);

    cout << ans << endl;
}
