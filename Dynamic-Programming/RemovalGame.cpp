#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <functional>
#include <type_traits>
 
#define int long long
using namespace std;
 
 
void solve() {
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++)
        cin >> nums[i];
 
    vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(n+1, {0, 0}));
 
    //for (int i = 0; i < dp.size(); i++)
    //    dp[i][dp[i].size() - i - 1] = 
 
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = n-1; j >= 0; j--)
        {
            if (i + j >= n)
                continue;
            
            if ((i + j) % 2 == 0)
                dp[i][j] = (dp[i+1][j].first + nums[i] > dp[i][j+1].first + nums[nums.size()-1-j]) ? pair<int, int>{dp[i+1][j].first + nums[i], dp[i+1][j].second} : pair<int, int>{dp[i][j+1].first + nums[nums.size()-1-j], dp[i][j+1].second};
            else
                dp[i][j] = (dp[i+1][j].second + nums[i] > dp[i][j+1].second + nums[nums.size()-1-j]) ? pair<int, int>{dp[i+1][j].first, dp[i+1][j].second + nums[i]} : pair<int, int>{dp[i][j+1].first, dp[i][j+1].second + nums[nums.size()-1-j]};
 
        }
    }
 
    cout << dp[0][0].first;
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
        solve();
 
    return 0;
}