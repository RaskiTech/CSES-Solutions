#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
int mod = 1e9+7;
 
void solve()
{
    int n;
    cin >> n;
 
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int centroid = -1;
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
            centroid = node;
        return size;
    };
    dfs(0, -1);
    cout << centroid+1 << endl;
 
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