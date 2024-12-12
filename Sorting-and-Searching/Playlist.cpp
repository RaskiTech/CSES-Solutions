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
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    unordered_set<int> songs(n);
 
    int maxL = 0;
    int l = 0, r = 0;
    while (r < nums.size())
    {
        if (songs.find(nums[r]) != songs.end())
        {
            while (nums[l] != nums[r])
            {
                songs.erase(nums[l]);
                l++;
            }
            songs.erase(nums[l]);
            l++;
        }
 
        songs.insert(nums[r]);
        r++;
        maxL = max(maxL, r-l);
    }
    cout << maxL;
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