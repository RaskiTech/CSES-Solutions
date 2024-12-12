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
 
class STree {
public:
    vector<pair<int, int>> data;
    vector<int> sizes;
    int offset;
    STree(int size, vector<pair<int, int>>& startVals)
    {
        offset = 1;
        while (size > offset) offset <<= 1;
        data = vector<pair<int, int>>(2*offset, {INT_MAX, INT_MAX});
        sizes = vector<int>(2*offset, 1);
 
        for (int i = 0; i < startVals.size(); i++)
            data[offset+i] = startVals[i];
        
        for (int i = offset-1; i > 0; i--)
        {
            sizes[i] = sizes[2*i] + sizes[2*i+1];
            data[i].first = min(data[2*i].first, data[2*i+1].first + sizes[2*i]);
            data[i].second = min(data[2*i+1].second, data[2*i].second + sizes[2*i]);
        }
    }
 
    void Set(int i, int val) {
        i += offset;
        data[i] = {val, val};
        i /= 2;
        while (i > 0)
        {
            data[i].first = min(data[2*i].first, data[2*i+1].first + sizes[2*i]);
            data[i].second = min(data[2*i+1].second, data[2*i].second + sizes[2*i]);
            i /= 2;
        }
    }
    int Range(int pos) {
        pos += offset;
        int lRange = 1;
        int rRange = 1;
        int minVal = data[pos].first;
        while (pos > 1)
        {
            if (pos % 2 == 0)
            {
                minVal = min(minVal, data[pos+1].first + rRange);
                rRange += sizes[pos];
            }
            else
            {
                minVal = min(minVal, data[pos-1].second + lRange);
                lRange += sizes[pos];
            }
 
            pos /= 2;
        }
        return minVal;
    }
};
 
void solve()
{
    int n, q;
    cin >> n >> q;
 
    vector<pair<int, int>> in(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        in[i] = {a, a};
    }
 
    STree tree = STree(n, in);
 
    for (int i = 0; i < q; i++)
    {
        int a; int b, c;
        cin >> a;
 
        if (a == 1)
        {
            cin >> b >> c;
            tree.Set(b-1, c);
        }
        else
        {
            cin >> b;
            cout << tree.Range(b-1) << '\n';
        }
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