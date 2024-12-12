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
    int n, x;
    cin >> n >> x;
 
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
 
    int l = 0, r = n-1;
 
    while (l <= r)
    {
        if (nums[l] + nums[r] <= x)
        {
            l++;
            r--;
        }
        else
            r--;
    }
 
    cout << (n-1) - r;
 
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