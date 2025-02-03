#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> color;
bool possible = true;
void dfs(int node, vector<vector<int>>& adj)
{
    for (int neighbor : adj[node])
    {
        if (color[neighbor] != 0)
        {
            if (color[neighbor] == color[node])
                possible = false;
            continue;
        }

        color[neighbor] = color[node] == 1 ? 2 : 1;
        dfs(neighbor, adj);
    }
}

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

    color = vector<int>(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0)
        {
            color[i] = 1;
            dfs(i, adj);
        }
    }
    if (!possible)
        cout << "IMPOSSIBLE";
    else
    {
        for (int col : color)
            cout << col << ' ';
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}