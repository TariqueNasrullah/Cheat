#include <bits/stdc++.h>
using namespace std;

int n = 10;
int cost[10][3];
int maxi = -1;
int recur(int row, int prev)
{
    if(row >= n) return 0;

    int maxi = -1;

    for(int i = 0; i < 3; i++)
    {
        if(i != prev)
           maxi = max(maxi, cost[row][i] + recur(row+1, i));
    }
    return maxi;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> cost[i][j];
    int x = recur(0, -1);
    cout << x << endl;
}
