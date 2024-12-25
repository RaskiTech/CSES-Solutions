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
#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp> // gcc only
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
#define int long long
using namespace std;
 
int p(int base, int power, int mod)
{
    if (power == 0)
        return 1;
    if (power % 2 == 0)
    {
        int r = p(base, power/2, mod);
        return (r*r) % mod;
    }
    else
        return (p(base, power-1, mod)*base) % mod;
}
 
int mod = 998244353;
vector<int> color;
vector<int> res;
 
void dfs(vector<vector<int>>& adj, int node, int parent, set<int>& outSet)
{
    for (auto n : adj[node])
    {
        if (n == parent)
            continue;
        
        set<int> s;
        dfs(adj, n, node, s);
        if (s.size() > outSet.size())
            swap(s, outSet);
        
        outSet.insert(s.begin(), s.end());
    }
 
    outSet.insert(color[node]);
    res[node] = outSet.size();
 
}
 
void solve()
{
    int n;
    cin >> n;
 
    color.resize(n);
    res.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> color[i];
    }
 
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    set<int> s;
    dfs(adj, 0, -1, s);
    
    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';
 
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