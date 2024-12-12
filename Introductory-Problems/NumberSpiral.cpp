#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <functional>
#include <type_traits>
#include <fstream>
#include <bitset>
#include <complex>
 
#define int long long
using namespace std;
 
#define cross(x, y) (((x)*conj(y)).imag())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
void solve()
{
    int x, y;
    cin >> x >> y;
 
    if (x == 1 && y == 1)
    {
        cout << 1 << '\n';
        return;
    }
 
    int n = max(x, y) - 1;
 
    int res = n * n;
    if (n % 2 == 0)
    {
        if (y < x)
            res += y;
        else
            res += n + ((n+1)-x) + 1;
    }
    else
    {
        if (x < y)
            res += x;
        else
            res += n + ((n+1)-y) + 1;
    }
    cout << res << '\n';
 
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
 
    int t = 1;
 
    cin >> t;
    //ifstream f("testcase.txt");
    //cin.rdbuf(f.rdbuf());
 
    for (int i = 0; i < t; i++)
        solve();
}