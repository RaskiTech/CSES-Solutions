#include <bits/stdc++.h>
#define int long long
using namespace std;

int countDFS(int node, vector<vector<int>>& adj, vector<bool>& vis)
{
    vis[node] = true;
    int sum = 1;
    for (int n : adj[node])
    {
        if (!vis[n])
            sum += countDFS(n, adj, vis);
    }
    return sum;
}

const int maxN = 1e5+2;

void solve()
{
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
    vector<int> sets;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i])
            sets.push_back(countDFS(i, adj, visited));
    
    bitset<maxN> result;
    result[0] = 1;
    for (int num : sets)
        result |= result << num;
    for (int i = 1; i <= n; i++)
        cout << (result[i] ? 1 : 0);
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}