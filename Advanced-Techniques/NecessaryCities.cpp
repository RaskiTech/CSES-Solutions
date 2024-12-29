#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> backEdges;
vector<int> depth;
vector<int> res;
int dfs(int node, int parent, vector<vector<int>>& adj)
{
    if (depth[node] != -1)
    {
        backEdges[node]++;
        return 1;
    }

    depth[node] = parent == -1 ? 0 : depth[parent] + 1;;
    int currentBackEdges = 0;
    int childCount = 0;
    bool addNode = false;
    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;

        // This edge has already been discovered as a back edge
        if (depth[neighbor] > depth[node])
            continue;

        childCount++;
        int prevBackEdges = backEdges[node];
        int added = dfs(neighbor, node, adj);
        int diff = backEdges[node]-prevBackEdges;
        if (added-diff == 0)
        {
            addNode = true;
        }
        currentBackEdges += added;
    }
    currentBackEdges -= backEdges[node];
    if (parent == -1)
    {
        if (childCount > 1)
            res.push_back(node);
    }
    else
    {
        if (addNode)
            res.push_back(node);
    }

    return currentBackEdges;
}

void solve() {
    int n, m;
    cin >> n >> m;

    backEdges = vector<int>(n, 0);
    depth = vector<int>(n, -1);
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, adj);

    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++)
        cout << res[i]+1 << ' ';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}