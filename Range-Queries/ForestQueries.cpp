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
 
int mod = 998244353;
 
 
void solve()
{
    int n, q;
    cin >> n >> q;
 
    vector<vector<int>> map(n+1, vector<int>(n+1, 0));
    for (int i = 1; i < map.size(); i++)
    {
        for (int j = 1; j < map.size(); j++)
        {
            char a;
            cin >> a;
            if (a == '*')
                map[i][j] = 1;
            
            map[i][j] += map[i][j-1];
        }
    }
 
    for (int i = 1; i < map.size(); i++)
    {
        for (int j = 1; j < map.size(); j++)
        {
            map[i][j] += map[i-1][j];
        }
    }
 
    for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
 
        cout << map[c][d] - map[a-1][d] - map[c][b-1] + map[a-1][b-1] << '\n';
    }
 
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