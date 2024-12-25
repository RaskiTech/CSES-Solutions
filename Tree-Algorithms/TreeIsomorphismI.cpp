#include <bits/stdc++.h>
#define int long long
using namespace std;
 
map<vector<int>, int> maps;
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
 
    maps.clear();
    cout << (stringify(adj1, 0, -1) == stringify(adj2, 0, -1) ? "YES\n" : "NO\n");
}
 
signed main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}