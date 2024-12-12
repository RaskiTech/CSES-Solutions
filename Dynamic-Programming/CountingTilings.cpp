#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <climits>
#include <cmath>
#include <functional>
#include <type_traits>
#include <fstream>
#include <bitset>
#include <complex>
#include <iomanip>
#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp> // gcc only
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
#define int long long
using namespace std;
 
int p(int base, int power, int mod)
{
    if (power == 0)
        return 1;
    if (power % 2 == 0)
    {
        int r = p(base, power/2, mod);
        return (r*r) % mod;
    }
    else
        return (p(base, power-1, mod)*base) % mod;
}
 
int mod = 1e9+7;
int n, m;
vector<vector<vector<int>>> dp;
 
int ways(int i, int j, int mask)
{
    if (i >= n)
        return ways(0, j+1, mask);
    if (j >= m)
        return mask == 0;
    if (dp[i][j][mask] != -1)
        return dp[i][j][mask];
    
    int filterThis = ((1 << n)-1) - (1 << i);
 
    if (mask & (1 << i))
        return ways(i+1, j, mask & filterThis);
    
    int res = ways(i+1, j, mask | (1 << i));
    if (i < n-1 && !(mask & (1 << i+1)))
        res += ways(i+2, j, mask);
 
    return dp[i][j][mask] = res % mod;
}
 
void solve()
{
    cin >> n >> m;
 
    dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(1 << n, -1)));
    cout << ways(0, 0, 0);
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        solve();
        //cout.flush();
    }
}