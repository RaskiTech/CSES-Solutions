#include <bits/stdc++.h>
using namespace std;

void PrintDP(int n, int from, int to)
{
    if (n)
    {
        int free = from ^ to; // Cool trick
        PrintDP(n-1, from, free);
        cout << from << ' ' << to << '\n';
        PrintDP(n-1, free, to);
    }
}

signed main() {
    int n;
    cin >> n;

    cout << (1 << n) - 1 << '\n';
    PrintDP(n, 1, 3);
}