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
#include <type_traits>
 
#define int long long
using namespace std;
 
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;b--;
        adj[a].push_back({b, w});
        //adj[b].push_back({a, w});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(adj.size(), false);
    vector<int> dist(adj.size(), LLONG_MAX);
    vector<int> distUsed(adj.size(), LLONG_MAX);
 
    pq.push({0, 0});
    dist[0] = 0;
    distUsed[0] = 0;
 
    while (!pq.empty()) {
        int u = abs(pq.top().second);
        bool onlyPartial = pq.top().second < 0;
 
        //cout << "Consider node " << pq.top().second << " --- ";
 
        pq.pop();
 
        if (onlyPartial)
        {
            //cout << "Trying node " << u << " with " << distUsed[u] << " --- ";
            if (visited[u] & 2)
                continue;
            visited[u] = visited[u] | 2;
 
            for (auto& neighbor : adj[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;
 
                distUsed[v] = min(min(distUsed[v], distUsed[u] + weight), LLONG_MAX/*dist[u] + weight / 2*/);
            }
            continue;
        }
        
        if (visited[u] & 1)
            continue;
        visited[u] = visited[u] | 1;
 
        // Iterate through all adjacent vertices of the current vertex
        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
 
            //cout << dist[v] << " " << dist[u] << " " << weight << "\n";
 
            // If a shorter path to v is found
            if ((dist[v] > dist[u] + weight || distUsed[v] > distUsed[u] + weight || distUsed[v] > dist[u] + weight / 2))
            {
                // Update distance and push new distance to the priority queue
                distUsed[v] = min<int>(min(distUsed[v], distUsed[u] + weight), dist[u] + weight / 2);
                dist[v] = min(dist[v], dist[u] + weight);
 
                int d = dist[v];
                int vu = distUsed[v];
 
                pq.push({dist[v], v});
                pq.push({distUsed[v], -v});
            }
        }
    }
 
    //for (int i = 0; i < adj.size(); i++)
    //    cout << dist[i] << "," << maxCost[i] << " ";
 
    cout << distUsed.back();
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