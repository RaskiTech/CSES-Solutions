#include <bits/stdc++.h> 
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    n++;

    int cycle = 2;
    int added = 1;
    int count = 0;
    while (added)
    {
        added = 0;
        int loops = n / cycle;
        added += loops * cycle/2;
        int rem = n - loops * cycle;
        added += max<int>(0, rem - cycle/2);
        count += added;
        cycle *= 2;
    }
    cout << count;
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
        solve();
 
    return 0;
}