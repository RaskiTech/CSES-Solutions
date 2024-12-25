#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> diffs(n);
    for (int i = 0; i < n; i++)
        cin >> diffs[i];
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        diffs[i] = diffs[i] - a;
    }
    
    vector<int> nums(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += diffs[i];
        nums[i] = sum;
    }

    sort(nums.begin(), nums.end());

    int cost = 0;
    int target = nums[n/2];
    for (int i = 0; i < nums.size(); i++)
    {
        cost += abs(nums[i] - target);
    }
    cout << cost;
}

signed main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    //freopen("testcase.txt", "r", stdin);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}