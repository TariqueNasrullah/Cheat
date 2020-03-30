Binary search is a very familiar algorithm to most people here. A typical implementation looks like this:

// x = array of numbers
// n = length of the array
// k = search key
// returns "true" if the key is found, "false" otherwise
bool search(int x[], int n, int k) {
    int l = 0, r = n-1;
    while (l <= r) {
        int m = (l+r)/2;
        if (x[m] == k) return true;
        if (x[m] < k) l = m+1; else r = m-1;
    }
    return false;
}
However, even if the idea is straightforward, there are often bugs in binary search implementations. How exactly to update the search bounds and what is the condition when the search should stop?

Here is an alternative binary search implementation that is shorter and should be easier to get correct:

bool search(int x[], int n, int k) {
    int p = 0;
    for (int a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] <= k) p += a;
    }
    return x[p] == k;
}
The idea is to implement binary search like linear search but with larger steps. Variable p contains the current array index, and variable a contains the step length. During the search, the step length is n, n/2, n/4, ..., 1. Finally, p contains the largest index whose value is not larger than the search key.

A similar idea can be applied to binary search variations. For example, the following code counts how many times the key appears in the array. After the search, [p+1..q] is the range with value k.

int count(int x[], int n, int k) {
    int p = -1, q = -1;
    for (int a = n; a >= 1; a /= 2) {
        while (p+a < n && x[p+a] < k) p += a;
        while (q+a < n && x[q+a] <= k) q += a;
    }
    return q-p;
}
