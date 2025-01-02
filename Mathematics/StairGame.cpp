#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (i % 2 == 1)
                sum ^= a;
        }
        cout << (sum ? "first" : "second") << '\n';
    }
}