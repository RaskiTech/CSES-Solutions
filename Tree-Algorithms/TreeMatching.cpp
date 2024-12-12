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
 
//#define int long long
using namespace std;
 
vector<pair<int, int>> dp;
int dfs(vector<vector<int>>& adj, bool included, int node, int parent)
{
    if (included && dp[node].second != 0)
        return dp[node].second-1;
    if (!included && dp[node].first != 0)
        return dp[node].first-1;
 
    int sum = 0;
    for (auto neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;
        sum += dfs(adj, false, neighbor, node);
    }
    dp[node].second = sum + 1;
 
    if (included)
    {
        return sum;
    }
    else
    {
        int maxVal = 0;
        for (auto neighbor : adj[node])
        {
            if (neighbor == parent)
                continue;
            
            maxVal = max<int>(maxVal, sum - dfs(adj, false, neighbor, node) + dfs(adj, true, neighbor, node) + 1);
        }
        dp[node].first = maxVal+1;
        return maxVal;
    }
 
}
 
void solve() {
    int n;
    cin >> n;
 
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dp.resize(n);
    cout << dfs(adj, false, 0, -1);    
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