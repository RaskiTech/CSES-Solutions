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
 
#include <ext/pb_ds/assoc_container.hpp> // gcc only
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
#define int long long
using namespace std;
 
#define cross(x, y) (((x)*conj(y)).imag())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
 
int mod = 1e9+7;
 
int p(int a, int b, int m)
{
    if (b == 0) return 1;
    else if (b % 2 == 0) { int r = p(a, b/2, m); return (r*r) % m; }
    else return (p(a, b-1, m)*a) % m; 
}
int gdc(int a, int b)
{
    if (b == 0) return a;
    return gdc(b, a%b);
}
 
int nCr(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        if (res < 0)
        {
            cout << "overflow";
        }
        res = ((res * (n-i)) / (i+1));
    }
    return res;
}
 
void solve()
{
    int n;
    cin >> n;
 
    if (n % 2 == 1)
    {
        cout << 0;
        return;
    }
    n /= 2;
 
    int c = 1;
    for (int i = 2; i <= n; i++)
    {
        c = c * (4*i-2);
        c %= mod;
        int mInv = p(i+1, mod-2, mod);
        c = c * mInv;
        c %= mod;
        //cout << c << '\n';
    }
    
    cout << c;
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(15);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        solve();
        //cout.flush();
    }
}