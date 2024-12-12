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
    int n;
    cin >> n;
 
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++)
        cin >> nums[i];
 
    int curr = nums[0];
    int cost = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        curr = max(curr, nums[i]);
        cost += curr - nums[i];
    }
    cout << cost;
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