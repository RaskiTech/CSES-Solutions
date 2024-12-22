#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            res ^= a;
        }
        cout << (res == 0 ? "second" : "first") << '\n';
    }
}