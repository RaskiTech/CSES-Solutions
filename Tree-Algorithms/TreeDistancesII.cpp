#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> nodeCount;
vector<int> childSum;
vector<int> res;
void calcDepths(int node, int parent, vector<vector<int>>& adj)
{
    nodeCount[node] = 1;
    childSum[node] = 0;
    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;
        calcDepths(neighbor, node, adj);
        nodeCount[node] += nodeCount[neighbor];
        childSum[node] += childSum[neighbor] + nodeCount[neighbor];
    }
}

void traversal(int node, int parent, int parentSum, int parentNodeCount, vector<vector<int>>& adj)
{
    res[node] = parentSum + childSum[node];
    for (int neigh : adj[node])
    {
        if (neigh == parent) continue;
        int childSums = childSum[node] - childSum[neigh] - nodeCount[neigh];
        int childsNodeCount = nodeCount[node] - nodeCount[neigh];
        traversal(neigh, node, parentSum + parentNodeCount + childSums + childsNodeCount, parentNodeCount + childsNodeCount, adj);
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

    nodeCount = vector<int>(n);
    childSum = vector<int>(n);
    res = vector<int>(n);
    calcDepths(0, -1, adj);
    traversal(0, -1, 0, 0, adj);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
}