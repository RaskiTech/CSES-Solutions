#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<bool> inCycle;
vector<int> dist;
vector<int> visited;

int GetParent(int node, int count, vector<vector<int>>& lift)
{
    for (int i = lift.size()-1; i >= 0; i--)
    {
        if (count >= 1 << i)
        {
            node = lift[i][node];
            count -= 1 << i;
        }
    }
    return node;
}

// Return: is in cycle
bool Dfs(vector<int>& parents, int node)
{
    if (visited[node])
    {
        if (dist[node] == -1)
        {
            inCycle[node] = true;
            return true;
        }
        else
        {
            return false;
        }
    }
    visited[node] = 1;

    bool prevInCycle = inCycle[node];
    inCycle[node] = Dfs(parents, parents[node]); 
    if (inCycle[node])
    {
        dist[node] = dist[parents[node]]+1;
        if (prevInCycle)
            return false;
        else
            return true;
    }
    else
    {
        dist[node] = inCycle[parents[node]] ? 1 : dist[parents[node]] + 1;
        return false;
    }
}

signed main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> parents(30, vector<int>(n));
    inCycle = vector<bool>(n, false);
    dist = vector<int>(n, -1);
    visited = vector<int>(n, false);

    for (int i = 0; i < n; i++)
    {
        cin >> parents[0][i];
        parents[0][i]--;
    }
    for (int i = 0; i < n; i++)
        Dfs(parents[0], i);
    
    // lift
    for (int i = 1; i < parents.size(); i++)
    {
        for (int j = 0; j < parents[i].size(); j++)
            parents[i][j] = parents[i-1][parents[i-1][j]];
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;

        int add = 0;
        if (!inCycle[a])
        {
            if (inCycle[b])
            {
                add += dist[a];
                a = GetParent(a, dist[a], parents);
            }
            else
            {
                if (dist[b] > dist[a])
                {
                    cout << -1 << '\n';
                    continue;
                }
                add += dist[a] - dist[b];
                a = GetParent(a, add, parents);
                if (a == b)
                    cout << add << '\n';
                else
                    cout << -1 << '\n';
                continue;
            }
        }

        if (inCycle[a] && inCycle[b])
        {
            if (a == b)
            {
                cout << add << '\n';
                continue;
            }

            if (dist[a] > dist[b])
            {
                add += dist[a] - dist[b];
                a = GetParent(a, dist[a] - dist[b], parents);
                cout << (a == b ? add : -1) << '\n';
            }
            else
            {
                int cycleLength = dist[GetParent(b, dist[b]+1, parents)]+1;
                int diff = dist[a] + cycleLength - dist[b];
                add += diff;
                a = GetParent(a, diff, parents);
                cout << (a == b ? add : -1) << '\n';
            }
            continue;
        }

        cout << -1 << '\n';
    }
}