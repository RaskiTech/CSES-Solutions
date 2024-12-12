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
 
unordered_map<int, int> m;
int n, x;
 
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<int> peeps(n);
    for (int i = 0; i < n; i++)
        cin >> peeps[i];
    
    vector<int> apartments(m);
    for (int i = 0; i < m; i++)
        cin >> apartments[i];
    
    sort(peeps.begin(), peeps.end());
    sort(apartments.begin(), apartments.end());
 
    int i = 0;
    int c = 0;
    int aIdx = 0;
    for (; i < n; i++)
    {
 
        while (aIdx < apartments.size() && apartments[aIdx] < peeps[i] - k)
            aIdx++;
        if (aIdx == apartments.size())
            break;
        if (peeps[i] + k >= apartments[aIdx])
        {
            aIdx++;
            c++;
        }
    }
 
    cout << c;
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