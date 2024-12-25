#include <bits/stdc++.h> 
//#define int long long
using namespace std;
 
void solve() {
    int n, x;
    cin >> n >> x;
 
    array<pair<uint32_t, uint32_t>, 1001> nums;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums[i] = {a, i+1};
    }
    sort(nums.begin(), nums.begin()+n);
 
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int target = x - nums[j].first - nums[i].first;
            if (target <= 0)
                continue;
            int l = j+1;
            int r = n-1;
            while (l < r)
            {
                if (nums[l].first + nums[r].first > target)
                    r--;
                else if (nums[l].first + nums[r].first < target)
                    l++;
                else
                {
                    cout << nums[i].second << " " << nums[j].second 
                        << " " << nums[l].second << " " << nums[r].second;
                    return;
                }
            }
        }
    }
 
 
    cout << "IMPOSSIBLE";
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