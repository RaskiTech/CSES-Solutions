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
    int n, m;
    cin >> n;
 
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    vector<int> dp = {INT_MIN};
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > dp.back())
            dp.push_back(nums[i]);
        else
            dp[lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin()] = nums[i];
    }
 
    cout << dp.size()-1;
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