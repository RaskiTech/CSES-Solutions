#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int, int>> result;

vector<int> dfs(int node, int parent, vector<vector<int>>& adj)
{
    vector<int> rems;
    if (adj[node].size() == 1)
        rems.push_back(node);

    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;
        
        vector<int> neiRems = dfs(neighbor, node, adj);
        while (rems.size() > 0 && neiRems.size() > 0 && (parent == -1 || rems.size() + neiRems.size() > 2))
        {
            result.push_back({rems.back(), neiRems.back()});
            rems.pop_back();
            neiRems.pop_back();
        }
        for (int leaf : neiRems)
            rems.push_back(leaf);
    }
    return rems;
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n); 
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<int>> vecs;
    for (int neighbor : adj[0])
        vecs.push_back(dfs(neighbor, 0, adj));

    // The root is otherwise the same as other nodes, but we need to make sure to process connections
    // that comes with 2 leafs first
    sort(vecs.begin(), vecs.end(), [](auto& f, auto& s) { return f.size() < s.size(); });

    vector<int> rems;
    if (adj[0].size() == 1)
        rems.push_back(0);
    for (int i = vecs.size()-1; i >= 0; i--)
    {
        while (rems.size() > 0 && vecs[i].size() > 0)
        {
            result.push_back({rems.back(), vecs[i].back()});
            rems.pop_back();
            vecs[i].pop_back();
        }
        for (int leaf : vecs[i])
            rems.push_back(leaf);
    }
    for (int connect : rems)
        result.push_back({connect, 0});

    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++)
        cout << result[i].first+1 << ' ' << result[i].second+1 << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}