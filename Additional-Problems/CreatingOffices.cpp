#include <bits/stdc++.h>
using namespace std;
#define int long long

int D;
vector<int> resultPoints;

tuple<int, int, int> countDist(int node, int parent, vector<vector<int>>& adj)
{
    int total = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> childPoints;
    for (int neigh : adj[node])
    {
        if (neigh == parent) continue;

        auto [add, dist, lastNode] = countDist(neigh, node, adj);
        total += add;
        if (!childPoints.empty() && childPoints.top().first + dist < D)
            childPoints.push({dist, lastNode}), childPoints.pop(), total--;
        else
            childPoints.push({dist, lastNode});
    }

    if (total == 0)
        return {1, 1, node};
    if (childPoints.top().first >= D)
        childPoints.push({0, node}), total++;

    pair<int, int> closest = childPoints.top();
    childPoints.pop();
    while (!childPoints.empty())
        resultPoints.push_back(childPoints.top().second), childPoints.pop();

    return {total, closest.first+1, closest.second};
}

void solve() {
    int n;
    cin >> n >> D;

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    resultPoints.push_back(get<2>(countDist(0, -1, adj)));

    cout << resultPoints.size() << '\n';
    for (int num : resultPoints)
        cout << num+1 << ' ';
}
 
 
signed main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    for (int i = 0; i < t; i++)
        solve();
}