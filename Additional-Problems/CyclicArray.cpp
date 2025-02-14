#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    // Rounds, leftOver
    vector<pair<int, int>> table(n);

    int l = n-1;
    int r = n-1;
    int count = nums[l];
    while (l >= 0)
    {
        while (count > k)
        {
            count -= nums[r];
            r--;
        }
        if (r == n-1)
            table[l] = {0, count};
        else
            table[l] = {table[r+1].first+1, table[r+1].second};
        l--;
        count += nums[l];
    }

    int minRes = INT_MAX;

    if (table[0].first == 0)
    {
        cout << 1;
        return;
    }

    int startSum = 0;
    int idx = 0;
    while (startSum <= k)
    {
        auto [rounds, leftOver] = table[idx];
        if (leftOver + startSum <= k)
            rounds += 1;
        else
            rounds += 2;
        minRes = min(minRes, rounds);
        startSum += nums[idx];
        idx++;
    }
    cout << minRes;
}
 
 
signed main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    for (int i = 0; i < t; i++)
        solve();
}