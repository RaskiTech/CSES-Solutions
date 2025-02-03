#include <bits/stdc++.h>
using namespace std;
//#define int long long

map<vector<int>, int> maps;
long long hash_(int first, int second) { return (long long)first * 1e6 + second; }
int stringify(vector<vector<int>>& adj, int node, int parent)
{
    vector<int> childs;
    for (int neighbor : adj[node])
        if (neighbor != parent)
            childs.push_back(stringify(adj, neighbor, node));
    sort(childs.begin(), childs.end());
    if (maps.find(childs) == maps.end())
        maps[childs] = maps.size();
    return maps[childs];
}

void solve() {
    int n;
    cin >> n;
 
    vector<vector<int>> adj1(n, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj1[a].push_back(b);
        adj1[b].push_back(a);
    }
    vector<vector<int>> adj2(n, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj2[a].push_back(b);
        adj2[b].push_back(a);
    }
 
    bool possible = stringify(adj1, 0, -1) == stringify(adj2, 0, -1);
    cout << (possible ? "YES\n" : "NO\n");
}


signed main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}