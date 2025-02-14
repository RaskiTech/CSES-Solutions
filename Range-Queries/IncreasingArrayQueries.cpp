#include <bits/stdc++.h>
using namespace std;
#define int long long

// For each element we find the next element bigger, and the cost to flatten to that element.
// We use binary lifting on this array

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    vector<int> pref(n+1);
    pref[0] = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
        pref[i+1] = pref[i] + nums[i];
    }

    // idx, cost
    vector<vector<pair<int, int>>> nextBiggest(20, vector<pair<int, int>>(n));

    stack<int> idxs;
    for (int i = n-1; i >= 0; i--)
    {
        while (!idxs.empty() && nums[idxs.top()] <= nums[i])
            idxs.pop();
        if (idxs.empty())
            nextBiggest[0][i] = {n, (n-i) * nums[i] - (pref[n] - pref[i])};
        else
            nextBiggest[0][i] = {idxs.top(), (idxs.top()-i) * nums[i] - (pref[idxs.top()] - pref[i])};
        idxs.push(i);
    }

    for (int i = 1; i < nextBiggest.size(); i++)
    {
        for (int j = 0; j < nextBiggest[i].size(); j++)
        {
            auto& inter = nextBiggest[i-1][j];
            if (inter.first == n)
                nextBiggest[i][j] = inter;
            else
                nextBiggest[i][j] = {nextBiggest[i-1][inter.first].first, nextBiggest[i-1][inter.first].second + inter.second};
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;

        int cost = 0;
        while (nextBiggest[0][a].first <= b)
        {
            int idx = 1;
            while (nextBiggest[idx][a].first < b)
            {
                int _ = nextBiggest[idx][a].first;
                idx++;
            }
            cost += nextBiggest[idx-1][a].second;
            a = nextBiggest[idx-1][a].first;
        }
        cost += (b-a+1) * nums[a] - (pref[b+1] - pref[a]);
        cout << cost << '\n';
    }
}
 
 
signed main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    for (int i = 0; i < t; i++)
        solve();
}