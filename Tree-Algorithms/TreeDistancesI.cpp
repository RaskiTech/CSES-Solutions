#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> depths;
vector<int> res;
int calcDepths(int node, int parent, vector<vector<int>>& adj)
{
    int depth = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i] != parent)
            depth = max(depth, calcDepths(adj[node][i], node, adj)+1);
    }
    return depths[node] = depth;
}

void traversal(int node, int parent, int parentLength, vector<vector<int>>& adj)
{
    int maxChildDist = 0;
    int child = -1;
    int secondMax = 0;
    for (int neigh : adj[node])
    {
        if (neigh == parent)
            continue;

        if (maxChildDist < depths[neigh])
        {
            child = neigh;
            secondMax = maxChildDist;
            maxChildDist = depths[neigh];
        }
        else {
            secondMax = max(secondMax, depths[neigh]);
        }
    }

    res[node] = max<int>(parentLength, maxChildDist);
    for (int neigh : adj[node])
    {
        if (neigh == parent) continue;
        int len = child == neigh ? secondMax : maxChildDist;
        traversal(neigh, node, max(parentLength+1, len+1), adj);
    }
}

signed main() {
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

    depths = vector<int>(n);
    res = vector<int>(n);
    calcDepths(0, -1, adj);
    traversal(0, -1, 0, adj);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
}