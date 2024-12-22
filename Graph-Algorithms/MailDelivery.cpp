#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // gcc only
 
#define int long long
using namespace std;
 
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;


void recurse(int node, vector<int>& iterPoint, vector<int>& outVec, vector<vector<pair<int, int>>>& adj) {
    for (iterPoint[node]++; iterPoint[node] < adj[node].size(); iterPoint[node]++)
    {
        int i = iterPoint[node];
        int neighbor = adj[node][i].first;
        if (neighbor == -1)
            continue;
        adj[adj[node][i].first][adj[node][i].second].first = -1;
        adj[node][i].first = -1;
        recurse(neighbor, iterPoint, outVec, adj);
        outVec.push_back(node);
    }
}

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back({b, adj[b].size()});
        adj[b].push_back({a, adj[a].size()-1});
    }

    bool canDo = true;
    for (int i = 0; i < adj.size(); i++)
        canDo &= adj[i].size() % 2 == 0;
    if (!canDo)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<int> out;
    out.reserve(2*n);
    out.push_back(0);
    vector<int> uSet(n, -1);
    recurse(0, uSet, out, adj);

    bool usedAll = true;
    for (auto& neis : adj)
    {
        for (auto& kv : neis)
        {
            if (kv.first != -1)
                usedAll = false;
        }
    }
    if (!usedAll)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (auto it = out.rbegin(); it < out.rend(); it++)
    {
        cout << *it + 1 << ' ';
    }
}