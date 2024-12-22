#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;

    int res = 0;
    int num = n;
    while (num > 0)
    {
        res += num / 5;
        num /= 5;
    }
    cout << res << endl;
}