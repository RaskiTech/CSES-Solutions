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
 
    vector<int> dp(x+1);
    dp[0] = 1;
    vector<int> coins(n);
    for (int coinIdx = 0; coinIdx < n; coinIdx++)
    {
        int coin;
        cin >> coin;
        coins[coinIdx] = coin;
    }
    for (int i = 1; i < dp.size(); i++)
    {
        for (auto coin : coins)
        {
            if (i >= coin)
                dp[i] += dp[i-coin];
        }
        dp[i] %= 1000000007;
    }
    //for (int i = 0; i < dp.size(); i++)
    //    cout << dp[i] << " ";
    cout << dp[x];
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