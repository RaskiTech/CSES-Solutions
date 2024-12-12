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
#include <bitset>
 
#define int long long
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> nums(n);
    int reward = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        reward += b;
        nums[i] = a;
    }
    sort(nums.begin(), nums.end());
 
    for (int i = 0; i < nums.size(); i++)
    {
        reward -= nums[i] * (n-i);
    }
    cout << reward;
 
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