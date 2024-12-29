#include <bits/stdc++.h>
using namespace std;
//#define int long long

vector<int> backEdges;
vector<int> depth;
bool hasCriticalEdges = false;
int FindCritical(int node, int parent, vector<vector<int>>& adj)
{
    if (depth[node] != -1)
    {
        backEdges[node]++;
        return 1;
    }
 
    depth[node] = parent == -1 ? 0 : depth[parent] + 1;;
    int currentBackEdges = 0;
    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;
 
        // This edge has already been discovered as a back edge
        if (depth[neighbor] > depth[node])
            continue;
 
        int added = FindCritical(neighbor, node, adj);
        if (added == 0)
            hasCriticalEdges = true;

        currentBackEdges += added;
    }
    currentBackEdges -= backEdges[node];
    return currentBackEdges;
}


vector<pair<int, int>> directions;
set<pair<int, int>> visitedEdges;
void CalcDirections(vector<bool>& visited, vector<vector<int>>& adj, int node, int parent)
{
    if (visited[node])
        return;
    visited[node] = true;
    
    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;
        
        pair<int, int> edge = {neighbor, node};
        if (edge.first > edge.second)
            swap(edge.first, edge.second);
        if (visitedEdges.find(edge) == visitedEdges.end())
        {
            visitedEdges.insert(edge);
            directions.push_back({node, neighbor});
        }

        CalcDirections(visited, adj, neighbor, node);
    }
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
        assert(a < n && b < n);
        assert(a >= 0 && b >= 0);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    FindCritical(0, -1, adj);
    if (hasCriticalEdges)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<bool> visited(n, false);
    directions.reserve(m);
    CalcDirections(visited, adj, 0, -1);
    // Not fully connected
    if (directions.size() < m)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int i = 0; i < directions.size(); i++)
        cout << directions[i].first+1 << " " << directions[i].second+1 << '\n';
}
 
signed main() {
    solve();
}