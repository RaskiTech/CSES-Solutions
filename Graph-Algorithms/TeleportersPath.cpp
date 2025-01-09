#include <bits/stdc++.h>
#define int long long
using namespace std;

void recurse(int node, vector<vector<int>>& adj, vector<int>& outNums)
{
    while (!adj[node].empty())
    {
        int neighbor = adj[node].back();
        adj[node].pop_back();
        
        recurse(neighbor, adj, outNums);
        outNums.push_back(node);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<int> inCount(n, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        inCount[b]++;
    }

    bool possible = true;
    for (int i = 1; i < n-1; i++)
        if (adj[i].size() != inCount[i])
            possible = false;
    if (!(adj[0].size() == inCount[0]+1 && adj[n-1].size()+1 == inCount[n-1]))
        possible = false;
    
    if (!possible)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    vector<int> nums;
    nums.push_back(n-1);
    recurse(0, adj, nums);

    if (nums.size() <= m)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    for (int i = nums.size()-1; i >= 0; i--)
        cout << nums[i]+1 << ' ';
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}