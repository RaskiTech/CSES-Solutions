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
 
#define int long long
using namespace std;
 
#define cross(x, y) (((x)*conj(y)).imag())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
 
int mod = 1e9+7;
 
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
 
void solve()
{
    int n, q;
    cin >> n >> q;
 
    vector<int> nums(n);
    ordered_set<pair<int, int>> s;
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
        s.insert({nums[i], i});
    }
 
    for (int i = 0; i < q; i++)
    {
        int a, b;
        char c;
        cin >> c >> a >> b;
        if (c == '!')
        {
            a--;
            s.erase({nums[a], a});
            nums[a] = b;
            s.insert({nums[a], a});
        }
        else
        {
            auto up = s.upper_bound({b, INT_MAX});
            auto lo = s.lower_bound({a, 0});
            if (up != s.end())
                cout << s.order_of_key(*up) - s.order_of_key(*lo) << '\n';
            else
                cout << s.size() - s.order_of_key(*lo) << '\n';
        }
    }
 
 
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
        cout.flush();
    }
}