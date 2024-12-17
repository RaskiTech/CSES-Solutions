#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // gcc only
 
#define int long long
using namespace std;
 
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
int mod = 1e9+7;
 
vector<int> nums;
int x;
 
int key(int i1, int i2) { return (i1 << 32) | (i2); }
 
void picks(unordered_map<int, int, function<size_t(int)>>& sums, int i, int endI, int sofar)
{
    if (i == endI) {
        sums[sofar]++;
        return;
    }
 
    picks(sums, i+1, endI, sofar + nums[i]);
    picks(sums, i+1, endI, sofar);
}
 
void solve()
{
    int n;
    cin >> n >> x;
 
    nums = vector<int>(n);
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        totalSum += nums[i];
    }
 
    unordered_map<int, int, function<size_t(int)>> first(pow(2, n/2), [](int value){return hash<int>()(value ^ 0b10101011011110100); });
    unordered_map<int, int, function<size_t(int)>> second(pow(2, n/2), [](int value){return hash<int>()(value ^ 0b10101011011110100); });
    picks(first, 0, nums.size()/2, 0);
    picks(second, nums.size()/2, nums.size(), 0);
 
    int res = 0;
    for (auto [k, v] : first) {
        if (k <= x && second.find(x - k) != second.end())
            res += v * second[x-k];
    }
    cout << res;
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