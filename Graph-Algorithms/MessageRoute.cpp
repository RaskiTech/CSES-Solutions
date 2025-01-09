#include <bits/stdc++.h>
#define int long long
using namespace std;

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

    queue<pair<int, int>> next;
    vector<int> prev(n, -1);
    next.push({0, 0});
    int res = -1;
    while (!next.empty())
    {
        auto [node, weight] = next.front();
        next.pop();
        if (node == n-1)
        {
            res = weight;
            break;
        }

        for (int neigh : adj[node])
        {
            if (prev[neigh] != -1)
                continue;
            next.push({neigh, weight+1});
            prev[neigh] = node;
        }
    }
    if (res == -1)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    vector<int> nodes;
    nodes.push_back(n-1);
    while (nodes.back() != 0)
        nodes.push_back(prev[nodes.back()]);

    cout << nodes.size() << '\n';
    for (int i = nodes.size()-1; i >= 0; i--)
        cout << nodes[i]+1 << ' ';
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}