#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxN = 1e5+2;

int nextLowlinkValue = 0;
array<int, maxN> lowlink;
array<int, maxN> ids;
array<bool, maxN> onStack;
vector<int> oneNodePerComponent;
void CalculateStronglyConnectedness(int node, vector<vector<int>>& adj, stack<int>& nodeStack)
{
    onStack[node] = true;
    nodeStack.push(node);
    ids[node] = lowlink[node] = nextLowlinkValue;
    nextLowlinkValue++;
 
    for (int neighbor : adj[node])
    {
        if (ids[neighbor] == -1)
            CalculateStronglyConnectedness(neighbor, adj, nodeStack);
        if (onStack[neighbor])
            lowlink[node] = min(lowlink[node], lowlink[neighbor]);
    }
    if (ids[node] == lowlink[node])
    {
        oneNodePerComponent.push_back(node);
        while (!nodeStack.empty())
        {
            int popped = nodeStack.top();
            nodeStack.pop();
            onStack[popped] = false;
            ids[popped] = ids[node];
            if (popped == node)
            {
                break;
            }
        }
    }
}

bool canReach(int node, int destination, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[node] = true;
    if (node == destination)
        return true;
    bool yes = false;
    for (int n : adj[node])
    {
        if (!visited[n])
            yes |= canReach(n, destination, adj, visited);
    }
    return yes;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    fill(lowlink.begin(), lowlink.end(), -1);
    fill(ids.begin(), ids.end(), -1);
    fill(onStack.begin(), onStack.end(), false);

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
    }
    stack<int> s;
    for (int i = 0; i < n; i++)
        if (ids[i] == -1)
            CalculateStronglyConnectedness(i, adj, s);
    
    if (oneNodePerComponent.size() < 2)
    {
        cout << "YES";
        return;
    }
    cout << "NO\n";

    vector<bool> vis(n, false);
    if (canReach(oneNodePerComponent[0], oneNodePerComponent[1], adj, vis))
        cout << oneNodePerComponent[1]+1 << ' ' << oneNodePerComponent[0]+1;
    else
        cout << oneNodePerComponent[0]+1 << ' ' << oneNodePerComponent[1]+1;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}