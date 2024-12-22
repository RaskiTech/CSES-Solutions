#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
int mod = 998244353;
 
vector<vector<int>> lift;
vector<int> depths;
 
void dfs(vector<vector<int>>& adj, int node, int p, int depth)
{
    depths[node] = depth;
    for (int n : adj[node])
        if (n != p) {
            lift[0][n] = node;
            dfs(adj, n, node, depth+1);
        }
}
 
int lca(int a, int b)
{
    if (depths[a] < depths[b])
        swap(a, b);
    
    int k = depths[a] - depths[b];
    for (int idx = lift.size()-1; idx >= 0; idx--)
    {
        int am = 1 << idx;
        if (k >= am)
        {
            a = lift[idx][a];
            k -= am;
        }
    }
 
    if (a == b)
        return a;
 
    for (int idx = lift.size()-1; idx >= 0; idx--)
    {
        if (lift[idx][a] != lift[idx][b])
        {
            a = lift[idx][a];
            b = lift[idx][b];
        }
    }
    
    return lift[0][a];
}
 
 
void solve()
{
    int n, q;
    cin >> n >> q;
 
    lift = vector<vector<int>>(30, vector<int>(n, 0));
    depths = vector<int>(n);
    vector<vector<int>> adj(n, vector<int>());
 
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    dfs(adj, 0, -1, 0);
    for (int i = 1; i < 30; i++)
    {
        for (int idx = 0; idx < n; idx++)
        {
            lift[i][idx] = lift[i-1][lift[i-1][idx]];
        }
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        cout << depths[a] + depths[b] - 2*depths[lca(a, b)] << '\n';
    }
} 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    //std::ifstream file("testcase.txt"); std::cin.rdbuf(file.rdbuf());
 
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}