#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> queriesByNode;
vector<tuple<int, int, int, bool>> queries;
vector<bool> querieAnswers;
vector<vector<pair<int, int>>> notifyChangeTo;
vector<vector<int>> notifiedQueries;

vector<int> backEdges;
vector<int> depth;
bool hasVisited(int node) { return depth[node] != -1; }
int dfs(int node, int parent, vector<vector<int>>& adj)
{
    if (depth[node] != -1)
    {
        backEdges[node]++;
        return 1;
    }
 
    depth[node] = parent == -1 ? 0 : depth[parent] + 1;;
    int currentBackEdges = 0;
    int childCount = 0;
    bool addNode = false;

    for (auto& [criticalNode, queryIndex] : notifyChangeTo[node])
    {
        notifiedQueries[criticalNode].push_back(queryIndex);
    }

    unordered_map<int, bool> wasOriginallyVisited;
    for (int i = 0; i < queriesByNode[node].size(); i++)
    {
        wasOriginallyVisited[queriesByNode[node][i].first] = hasVisited(queriesByNode[node][i].first);
        wasOriginallyVisited[queriesByNode[node][i].second] = hasVisited(queriesByNode[node][i].second);
    }

    for (int neighbor : adj[node])
    {
        if (neighbor == parent)
            continue;
 
        // This edge has already been discovered as a back edge
        if (depth[neighbor] > depth[node])
            continue;
 
        childCount++;
        int prevBackEdges = backEdges[node];
        int added = dfs(neighbor, node, adj);
        int diff = backEdges[node]-prevBackEdges;
        if (added-diff == 0 || parent == -1)
        {
            // This is a critical edge. Consider changing queries to off

            for (int queryIndex : notifiedQueries[node])
            {
                auto& [a, b, c, possible] = queries[queryIndex];
                if ((hasVisited(a) == wasOriginallyVisited[a]) != (hasVisited(b) == wasOriginallyVisited[b]))
                    possible = false;
            }

            addNode = true;
        }
        for (int queryIndex : notifiedQueries[node])
        {
            auto& [a, b, c, possible] = queries[queryIndex];
            wasOriginallyVisited[a] = hasVisited(a);
            wasOriginallyVisited[b] = hasVisited(b);
        }

        notifiedQueries[node].clear();
        currentBackEdges += added;
    }
    currentBackEdges -= backEdges[node];
    return currentBackEdges;
}


signed main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queriesByNode = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
    notifyChangeTo = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
    notifiedQueries = vector<vector<int>>(n, vector<int>());
    queries = vector<tuple<int, int, int, bool>>(q);
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;c--;
        queriesByNode[c].push_back({a, b});
        queries[i] = {a, b, c, true};
        if (a == c || b == c)
            get<3>(queries[i]) = false;

        notifyChangeTo[a].push_back({c, i});
        notifyChangeTo[b].push_back({c, i});
    }

    depth = vector<int>(n, -1);
    backEdges = vector<int>(n, 0);
    dfs(0, -1, adj);
    for (int i = 0; i < queries.size(); i++)
    {
        cout << (get<3>(queries[i]) ? "YES" : "NO") << '\n';
    }    
}