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
 
 
void dfs(vector<bool>& visited, vector<vector<int>>& adj, int node)
{
    if (visited[node])
        return;
    visited[node] = true;
    
    for (int i = 0; i < adj[node].size(); i++)
    {
        dfs(visited, adj, adj[node][i]);
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> connections(m);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;b--;
        connections[i] = {a, b, w};
    }
 
    vector<int> values(n, LLONG_MIN / 2);
    values[0] = 0;
 
    for (int loopCount = 0; loopCount < n; loopCount++)
    {
        for (int i = 0; i < connections.size(); i++)
        {
            if (values[connections[i][0]] + connections[i][2] > values[connections[i][1]])
            {
                values[connections[i][1]] = values[connections[i][0]] + connections[i][2];
            }
        }
    }
 
    vector<int> flagged;
    for (int i = 0; i < connections.size(); i++)
    {
        if (values[connections[i][0]] + connections[i][2] > values[connections[i][1]])
        {
            flagged.push_back(connections[i][0]);
            values[connections[i][1]] = values[connections[i][0]] + connections[i][2];
        }
    }
 
    vector<vector<int>> adj(n);
    for (int i = 0; i < connections.size(); i++)
    {
        adj[connections[i][1]].push_back(connections[i][0]);
    }
    vector<bool> visited(n);
    dfs(visited, adj, n-1);
    for (int i = 0; i < flagged.size(); i++)
    {
        if (visited[flagged[i]] && values[flagged[i]] >= LLONG_MIN / 3)
        {
            cout << "-1";
            return;
        }
    }
 
    cout << values[n-1];
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