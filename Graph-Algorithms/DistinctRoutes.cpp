#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <climits>
#include <cmath>
#include <functional>
#include <type_traits>
#include <fstream>
#include <bitset>
#include <complex>
#include <iomanip>
 
#include <ext/pb_ds/assoc_container.hpp> // gcc only
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
#define int long long
using namespace std;
 
#define cross(x, y) (((x)*conj(y)).imag())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
 
 
int p(int a, int b, int m)
{
    if (b == 0) return 1;
    else if (b % 2 == 0) { int r = p(a, b/2, m); return (r*r) % m; }
    else return (p(a, b-1, m)*a) % m; 
}
int gdc(int a, int b)
{
    if (b == 0) return a;
    return gdc(b, a%b);
}
 
int nCr(int n, int r, int mod)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (n-i);
        res *= p(i+1, mod-2, mod);
    }
    return res;
}
int mod = 998244353;
 
int N;
 
bool dfs(vector<vector<pair<pair<int, int>, pair<int, int>>>>& adj, int node, vector<bool>& vis)
{
    if (node == N)
    {
        return true;
    }
 
    if (vis[node])
        return false;
    vis[node] = true;
 
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i].first.first == 1 && dfs(adj, adj[node][i].second.first, vis))
        {
            adj[node][i].first.first = 0;
            adj[node][i].first.second++;
            adj[adj[node][i].second.first][adj[node][i].second.second].first.second++;
            adj[adj[node][i].second.first][adj[node][i].second.second].first.first = 1;
            return true;
        }
    }
    return false;
}
bool dfs2(vector<vector<pair<pair<int, int>, pair<int, int>>>>& adj, int node, vector<int>& out)
{
    if (node == N)
    {
        out.push_back(node);
        return true;
    }
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i].first.first == 0 && adj[node][i].first.second % 2 == 1)
        {
            adj[node][i].first.first = 1;
            if (dfs2(adj, adj[node][i].second.first, out))
            {
                out.push_back(node);
                return true;
            }
        }
    }
    return false;
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
    N = n-1;
 
    vector<vector<pair<pair<int, int>, pair<int, int>>>> adj(n, vector<pair<pair<int, int>, pair<int, int>>>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back({{1, 0}, {b, adj[b].size()}});
        adj[b].push_back({{0, 0}, {a, adj[a].size()-1}});
    }
 
    int c = 0;
    vector<bool> vis(n);
 
    while (dfs(adj, 0, vis))
    {
        std::fill(vis.begin(), vis.end(), 0);
        c++;
    }
 
 
    cout << c << '\n';
    for (int i = 0; i < c; i++)
    {
        vector<int> route;
        while (!dfs2(adj, 0, route)) {}
 
        cout << route.size() << '\n';
        for (int j = route.size()-1; j >= 0; j--)
        {
            cout << route[j]+1 << ' ';
        }
        cout << '\n';
    }
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        solve();
        //cout.flush();
    }
}