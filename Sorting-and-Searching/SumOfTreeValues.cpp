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
    int n, x;
    cin >> n >> x;
 
    vector<pair<int, int>> nums(n);
    for (int i = 0; i < nums.size(); i++)
    {
        int a;
        cin >> a;
        nums[i] = {a, i+1};
    }
    sort(nums.begin(), nums.end());
 
    for (int i = 0; i < nums.size(); i++)
    {
        int target = x - nums[i].first;
        int l = i+1;
        int r = n-1;
        while (l < r)
        {
            if (nums[l].first + nums[r].first > target)
                r--;
            else if (nums[l].first + nums[r].first < target)
                l++;
            else
            {
                cout << nums[i].second << " " << nums[l].second << " " << nums[r].second;
                return;
            }
        }
    }
 
 
    cout << "IMPOSSIBLE";
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