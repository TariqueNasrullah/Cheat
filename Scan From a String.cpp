/* This program reads input from a String */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);        // Sample "a 10 20"

    char ch; int a, b;

    sscanf(s.c_str(), "%c %d %d", &ch, &a, &b);

    printf("%d %d %c\n", a, b, ch);

    return 0;
}
