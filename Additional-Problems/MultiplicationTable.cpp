#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    int l = 1, h = n*n;
    int requiredAmountLower = n * n / 2;

    while (l <= h)
    {
        int mid = (l+h)/2;

        int count = 0;
        for (int i = 1; i <= n; i++)
            count += min<int>(n, mid/i);
        if (count <= requiredAmountLower)
            l = mid+1;
        else
            h = mid-1;
    }
    cout << l;

}

signed main()
{
    //cin.tie(0);
    //ios_base::sync_with_stdio(false);
    //freopen("testcase.txt", "r", stdin);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}