#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
 
#define int long long
using namespace std;
 
vector<int> prefixSum;
 
void rec(vector<int>& write, vector<int>& read, int l, int r, int optL, int optR)
{
    if (l > r)
        return;
 
    int mid = (l + r) / 2;
 
    int minVal = LLONG_MAX / 2;
    int minIdx = 0;
    for (int i = optL; i < min(mid + 1, optR + 1); i++)
    {
        int sum = (prefixSum[mid] - prefixSum[i - 1]);
        if (minVal > read[i-1] + sum * sum)
        {
            minVal = read[i-1] + sum * sum;
            minIdx = i;
        }
    }
 
    write[mid] = minVal;
 
    rec(write, read, l, mid - 1, optL, minIdx);
    rec(write, read, mid + 1, r, minIdx, optR);
}
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    prefixSum.resize(n+1);
    prefixSum[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> prefixSum[i+1];
        prefixSum[i+1] += prefixSum[i];
    }
 
    vector<vector<int>> dp(k+1, vector<int>(n+1, LLONG_MAX / 2));
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
        rec(dp[i], dp[i-1], 1, n, 1, n);
 
    cout << dp.back().back();
}
 
 
signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
        solve();
 
    return 0;
}