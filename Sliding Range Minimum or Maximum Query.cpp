/*
Sliding Window maximum and minimum Query

*/


#include <bits/stdc++.h>
using namespace std;
int maxD;

void best(vector<int> & arr, int k)
{
    deque< pair<int, int> > q;
    vector<int> m;
    vector<int> h;
    for(int i = 0; i < arr.size(); i++){
        while(!q.empty() && q.back().first >= arr[i])
            q.pop_back();
        q.push_back(make_pair(arr[i], i));

        while(q.front().second <= i-k)
            q.pop_front();

        m.push_back(q.front().first);
    }

    q.clear();
    for(int i = 0; i < arr.size(); i++){
        while(!q.empty() && q.back().first <= arr[i])
            q.pop_back();
        q.push_back(make_pair(arr[i], i));

        while(q.front().second <= i-k)
            q.pop_front();

        h.push_back(q.front().first);
    }

    maxD = arr[0]-arr[1];

    for(int i = 0; i < h.size(); i++){
//        cout << m[i] << " " << h[i] << endl;
        maxD = max(maxD, abs(m[i] -h[i]));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, n, k;
    cin >> tc;

    for(int t = 1; t <= tc; t++){
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        best(arr, k);

        cout << "Case " << t << ": " << maxD << endl;
    }

    return 0;
}

