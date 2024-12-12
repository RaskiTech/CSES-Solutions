#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
 
#define int long long
using namespace std;
 
void solve() {
    int n, x;
    cin >> n >> x;
 
    vector<int> dp(x+1, LLONG_MAX / 2);
    for (int _n = 0; _n < n; _n++)
    {
        int num = 0;
        cin >> num;
        dp[0] = 0;
        for (int i = num; i <= x; i++)
        {
            dp[i] = min(dp[i], dp[i - num] + 1);
        }
    }
 
/*
    for (int i = 0; i < dp.size(); i++)
        cout << dp[i] << " ";
    cout << endl;
    */
 
    cout << (dp[x] >= LLONG_MAX / 2 ? -1 : dp[x]);
}
 
 
signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
        solve();
 
    return 0;
}