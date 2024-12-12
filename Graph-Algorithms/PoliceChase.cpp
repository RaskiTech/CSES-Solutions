#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <functional>
 
//#define int long long
using namespace std;
 
vector<vector<tuple<int, int, int>>> adj;
 
int flow(vector<bool>& visited, int node) 
{
    visited[node] = true;
    if (node == visited.size()-1)
        return 1;
 
    for (auto& data : adj[node])
    {
        if (get<1>(data) == 0 || visited[get<0>(data)])
            continue;
        
        int res = flow(visited, get<0>(data));
        if (res > 0)
        {
            get<1>(data) -= res;
            get<1>(adj[get<0>(data)][get<2>(data)]) += res;
            return res;
        }
    }
 
    return 0;
}
void findSet(unordered_set<int>& set, int node)
{
    set.insert(node);
    for (auto& data : adj[node])
    {
        if (set.find(get<0>(data)) == set.end() && get<1>(data) != 0)
        {
            findSet(set, get<0>(data));
        }
    }
}
void FindOutsideSet(unordered_set<int>& set, int node, unordered_set<int>& visited)
{
    visited.insert(node);
    for (auto& data : adj[node])
    {
        if (set.find(get<0>(data)) == set.end())
        {
            if (get<1>(data) == 0)
            {
                cout << node + 1 << " " << get<0>(data) + 1 << '\n';
            }
        }
        else if (visited.find(get<0>(data)) == visited.end())
            FindOutsideSet(set, get<0>(data), visited);
    }
}
 
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    adj = vector<vector<tuple<int, int, int>>>(n, vector<tuple<int, int, int>>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back({b, 1, adj[b].size()});
        adj[b].push_back({a, 1, adj[a].size()-1});
    }
 
    vector<bool> visited(n);
 
    int total = 0;
    int cur = 0;
    do
    {
        for (int i = 0; i < visited.size(); i++)
            visited[i] = false;
 
        cur = flow(visited, 0);
 
        total += cur;
    } while (cur != 0);
 
    cout << total << '\n';
 
    unordered_set<int> A;
    findSet(A, 0);
    unordered_set<int> B;
    FindOutsideSet(A, 0, B);
 
 
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
        solve();
 
    return 0;
}