#include <bits/stdc++.h>
#define int long long
using namespace std;
 
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
 
vector<int> FindCentroid(vector<vector<int>>& adj, int n) {
    vector<int> result;
    int targetSize = n/2;
    // Start at some random point
    function<int (int, int)> dfs = [&](int node, int p) {
        int size = 1;
        bool isCentroid = true;
        for (int n : adj[node])
        {
            if (n == p)
                continue;
            int val = dfs(n, node);
            size += val;
            if (val > targetSize)
                isCentroid = false;
        }
        if (n - size > targetSize)
            isCentroid = false;
        if (isCentroid)
            result.push_back(node);
        return size;
    };
    dfs(0, -1);
    return result;
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
 
    vector<int> centroids1 = FindCentroid(adj1, n);
    vector<int> centroids2 = FindCentroid(adj2, n);
 
    int other = stringify(adj1, centroids1[0], -1);
    bool possible = false;
    for (int i = 0; i < centroids2.size(); i++)
        possible |= other == stringify(adj2, centroids2[i], -1);
 
    cout << (possible ? "YES\n" : "NO\n");
}
 
signed main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}