#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // gcc only
 
 
#define int long long
using namespace std;
 
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
int mod = 1e9+7;
 
void solve()
{
    int n;
    cin >> n;
 
    vector<pair<int, int>> nums(n);
    
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums[i] = {a, n-i};
    }
    sort(nums.begin(), nums.end());
 
    ordered_set<int> tree;
    vector<int> res(n);
 
    for (int i = 0; i < nums.size(); i++)
    {
        int idx = n-nums[i].second;
        auto ptr = tree.lower_bound(idx);
        if (ptr == tree.begin())
            res[idx] = 0;
        else
        {
            ptr--;
            res[idx] = *(ptr) + 1;
        }
 
        tree.insert(idx);
    }
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
} 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    //std::ifstream file("testcase.txt"); std::cin.rdbuf(file.rdbuf());
 
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}