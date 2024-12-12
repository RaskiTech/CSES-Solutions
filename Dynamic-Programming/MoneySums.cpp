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
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
 
    vector<bool> doable(sum+1);
    doable[0] = 1;
    
    for (auto num : nums)
    {
        for (int i = sum; i >= num; i--)
        {
            doable[i] = doable[i] || doable[i-num];
        }
    }
 
    int amount = 0;
    for (int i = 1; i < doable.size(); i++)
        amount += doable[i];
    
    cout << amount << '\n';
    for (int i = 1; i < doable.size(); i++)
        if (doable[i])
        cout << i << ' ';
 
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