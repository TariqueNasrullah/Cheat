#include <bits/stdc++.h>
using namespace std;

const int element = 1e5+2;
int par[element];
int Rank[element];
int nodes[element];

int unionFind(int r){
    if(par[r] == r) return r;
    par[r] = unionFind(par[r]);
    return par[r];
}
void connect(int a, int b){
    int u = unionFind(a);
    int v = unionFind(b);

    if(u != v){
        if(Rank[u] > Rank[v]){par[v] = u; nodes[u] += nodes[v];}
        else {par[u] = v; nodes[v] += nodes[u];}

        if(Rank[u] == Rank[v]) Rank[u]++;
    }
}
void makeSet(){
    for(int i = 0; i < element; i++) {par[i] = i; nodes[i] = 1;}
}
void makeSet(int n){
    for(int i = 0; i <= n; i++) {par[i] = i; nodes[i] = 1;}
}

int main(){

    /*
    * First Call makeSet() to initialize
    * unionFind(a) finds parent of a
    * connect(a,b) connects a and b
    * nodes[a] contains total elements of set
    */

    makeSet();

    connect(1, 2);
    connect(3, 6);
    connect(6, 6);

    if(unionFind(3) == unionFind(4)) cout << "Connected" << endl;
    else cout << "Not Connected" << endl;
}

