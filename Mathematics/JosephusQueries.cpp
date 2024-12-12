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
 
 
int Get(int n, int k)
{
    if (n <= 1)
        return n;
 
    if (2*k <= n)
        return k*2;
    
    if (n % 2 == 0)
    {
        int val = Get(n/2, k-n/2);
        int idx = (val - 1)*2+1;
        return idx;
    }
    else
    {
        int val = Get(n/2+1, k-n/2);
        int idx = (val-1 + (n/2)) % (n/2+1)+1;
        return (idx-1)*2+1;
    }
}
 
void solve()
{
    int n, k;
    cin >> n >> k;
    cout << Get(n, k) << '\n';
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    cout.precision(15);
 
    int t = 1;
 
    cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        solve();
        //cout.flush();
    }
}