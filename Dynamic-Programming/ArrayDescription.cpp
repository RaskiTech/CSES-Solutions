#include <bits/stdc++.h> 
#define int long long
using namespace std;
 
int mod = 1e9+7;

void solve()
{
    int n, m;
    cin >> n >> m;

    int x;
    cin >> x;
    array<int, 102> curr;
    for (int i = 0; i < curr.size(); i++)
        curr[i] = 0;

    if (x != 0)
    {
        curr[x] = 1;
    }
    else
    {
        for (int i = 1; i <= m; i++)
            curr[i] = 1;
    }

    array<int, 102> next;
    for (int i = 0; i < next.size(); i++)
        next[i] = 0;

    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        if (x != 0)
        {
            for (int i = 1; i <= m; i++)
                next[i] = 0;
            next[x] = (curr[x-1] + curr[x] + curr[x+1]) % mod;
        }
        else
        {
            for (int i = 1; i <= m; i++)
            {
                next[i] = curr[i-1] + curr[i] + curr[i+1];
                next[i] %= mod;
            }
        }

        swap(next, curr);
    }

    int res = 0;
    for (int i = 1; i <= m; i++)
    {
        res += curr[i];
        res %= mod;
    }

    cout << res;
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(15);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}