#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int, int>> dp;
vector<int> weights;
int maxWeight;

signed main() {
    int n;
    cin >> n >> maxWeight;

    weights = vector<int>(n);
    dp = vector<pair<int, int>>(1 << n, {INT_MAX, INT_MAX});
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    
    dp[0] = {1, 0};

    for (int mask = 1; mask < 1 << weights.size(); mask++)
    {
        for (int idx = 0; idx < weights.size(); idx++)
        {
            int without = mask & ~(1 << idx);
            if (without != mask)
            {
                bool isOver = dp[without].second + weights[idx] > maxWeight;
                pair<int, int> candidate = {dp[without].first + isOver, isOver ? weights[idx] : dp[without].second + weights[idx] };
                dp[mask] = min(dp[mask], candidate);
            }
        }
    }
    cout << dp[(1 << n) - 1].first << endl;
}