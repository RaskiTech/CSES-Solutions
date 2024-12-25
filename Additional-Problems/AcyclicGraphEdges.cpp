#include <bits/stdc++.h>
#define int long long
using namespace std;
 
 
void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj, vector<int>& res, vector<pair<int, int>>& original)
{
    vector<int> visit;
    for (int i = 0; i < adj[node].size(); i++)
    {
        auto [neigh, idx] = adj[node][i];
        if (res[idx] != -1)
            continue;
        res[idx] = node == original[idx].first;
        visit.push_back(neigh);
    }
    for (int neighbor : visit)
        dfs(neighbor, node, adj, res, original);
}
 
signed main() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    vector<int> res(m, -1);
    vector<pair<int, int>> original(m);
    for (int i = 0; i < m; i++)
    {
        cin >> original[i].first >> original[i].second;
        original[i].first--;
        original[i].second--;
        adj[original[i].first].push_back({original[i].second, i});
        adj[original[i].second].push_back({original[i].first, i});
    }
 
    for (int i = 0; i < original.size(); i++)
    {
        if (res[i] == -1)
            dfs(original[i].first, -1, adj, res, original);
 
        if (res[i])
        {
            cout << original[i].first+1 << ' ' << original[i].second+1;
        }
        else
        {
            cout << original[i].second+1 << ' ' << original[i].first+1;
        }
        cout << '\n';
    }
}