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
 
int LCM(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}
 
int mod = 1e9+7;
vector<int> facts;
 
int nCr(int n, int r)
{
    return (facts[n] * p((facts[r] * facts[n-r]) % mod, mod-2, mod)) % mod;
}
 
void solve()
{
    int n;
    cin >> n;
 
    facts.resize(n+1);
    facts[0] = 1;
    for (int i = 1; i < facts.size(); i++)
        facts[i] = (facts[i-1] * i) % mod;
    
    int perm = facts[n];
    int sign = -1;
    for (int i = n-1; i >= 0; i--)
    {
        int added = sign * facts[i] * nCr(n, n-i);
        perm += added;
        sign *= -1;
        perm %= mod;
    }
 
    perm = (perm + mod) % mod;
    cout << perm;
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