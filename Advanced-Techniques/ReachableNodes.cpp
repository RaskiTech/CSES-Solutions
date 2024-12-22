#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // gcc only
 
#define int long long
using namespace std;

void calcTopological(vector<vector<int>>& adj, vector<int>& out)
{
    vector<int> dependencies(adj.size(), 0);
    for (int i = 0; i < adj.size(); i++)
    {
        for (int con = 0; con < adj[i].size(); con++)
        {
            dependencies[adj[i][con]]++;
        }
    }
    queue<int> frees;
    for (int i = 0; i < dependencies.size(); i++)
        if (dependencies[i] == 0)
            frees.push(i);
        
    while (!frees.empty())
    {
        out.push_back(frees.front());
        for (int i = 0; i < adj[frees.front()].size(); i++)
        {
            dependencies[adj[frees.front()][i]]--;
            if (dependencies[adj[frees.front()][i]] == 0)
                frees.push(adj[frees.front()][i]);
        }
        frees.pop();
    }
}

const int MAX_N = 5*1e4+1;

signed main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> forward(n, vector<int>());
    vector<vector<int>> reverse(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        forward[a].push_back(b);
        reverse[b].push_back(a);
    }

    vector<int> order;
    order.reserve(n);
    calcTopological(reverse, order);

    vector<bitset<MAX_N>> dp(n, 0);
    for (int num : order)
    {
        dp[num].set(num, 1);
        for (int i = 0; i < forward[num].size(); i++)
        {
            dp[num] |= dp[forward[num][i]];
        }
    }

    for (int i = 0; i < n; i++)
        cout << dp[i].count() << ' ';

}