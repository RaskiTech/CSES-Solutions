#include <bits/stdc++.h>
using namespace std;
#define int long long
 
 
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> nums(n);
 
    for (int i = 0; i < n; i++)
        cin >> nums[i].first;
    for (int i = 0; i < n; i++)
        cin >> nums[i].second;
    
    int topA = 0;
    int botA = 0;
    int cost = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        cost += abs(topA);
        cost += abs(botA);
 
        topA += nums[i].first - 1;
        botA += nums[i].second - 1;
 
        while (topA < 0 && botA > 0)
            topA++, botA--, cost++;
        while (topA > 0 && botA < 0)
            topA--, botA++, cost++;
    }
    cout << cost;
}
 
 
signed main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}