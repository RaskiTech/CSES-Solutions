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
 
//#define int long long
using namespace std;
 
int flow(vector<vector<tuple<int, int, int>>>& adj, vector<bool>& visited, int node) 
{
    visited[node] = true;
    if (node == visited.size()-1)
        return 1;
 
    for (auto& data : adj[node])
    {
        if (get<1>(data) == 0 || visited[get<0>(data)])
            continue;
        
        int res = flow(adj, visited, get<0>(data));
        if (res > 0)
        {
            get<1>(data) -= res;
            get<1>(adj[get<0>(data)][get<2>(data)]) += res;
            return res;
        }
    }
 
    return 0;
}
 
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<vector<tuple<int, int, int>>> adj(n+m+2, vector<tuple<int, int, int>>());
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({n+b, 1, adj[n+b].size()});
        adj[n+b].push_back({a, 0, adj[a].size()-1});
    }
    for (int i = 1; i <= n; i++)
    {
        adj[0].push_back({i, 1, adj[i].size()});
        adj[i].push_back({0, 0, adj[0].size()-1});
    }
    for (int i = 1; i <= m; i++)
    {
        adj[n+i].push_back({n+m+1, 1, adj[n+m+1].size()});
        adj[n+m+1].push_back({n+i, 0, adj[n+1].size()-1});
    }
 
    vector<bool> visited(n+m+2);
 
    int total = 0;
    int cur = 0;
    do
    {
        for (int i = 0; i < visited.size(); i++)
            visited[i] = false;
 
        cur = flow(adj, visited, 0);
 
        total += cur;
    } while (cur != 0);
 
    cout << total << '\n';
 
    for (int i = 1; i <= n; i++)
    {
        for (auto& neighbor : adj[i])
        {
            if (get<0>(neighbor) != 0 && get<1>(neighbor) == 0)
                cout << i << " " << get<0>(neighbor) - n << '\n';
        }
    }
 
    /*
    for (int i = 0; i < adj.size(); i++)
    {
        cout << "Adj for " << i << ": ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << get<0>(adj[i][j]) << "-" << get<1>(adj[i][j]) << " ";
        }
        cout << '\n';
    }
    //*/
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