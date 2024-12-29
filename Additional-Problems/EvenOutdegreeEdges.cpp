#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int, int>> directedEdges;

// Return: How many more are needed
int dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& depth)
{
    depth[node] = parent == -1 ? 1 : depth[parent]+1;
    int outEdges = 0;
    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;
        if (depth[neighbor] != 0)
        {
            if (depth[neighbor] < depth[node])
            {
                directedEdges.push_back({node, neighbor});
                outEdges++;
            }
            continue;
        }

        int need = dfs(neighbor, node, adj, depth);
        if (need)
            directedEdges.push_back({neighbor, node});
        else
        {
            directedEdges.push_back({node, neighbor});
            outEdges++;
        }
    }
    return outEdges % 2;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    directedEdges.reserve(m);
    vector<int> depth(n, 0);
    bool possible = true;
    for (int i = 0; i < n; i++)
    {
        if (depth[i] == 0)
            if (dfs(i, -1, adj, depth))
                possible = false;
    }
    if (!possible)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (int i = 0; i < directedEdges.size(); i++)
            cout << directedEdges[i].first+1 << " " << directedEdges[i].second+1 << '\n';
    }
}
 
signed main() {
    solve();
}