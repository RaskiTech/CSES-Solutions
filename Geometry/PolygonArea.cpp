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
 
//#define cross(x, y) ((x).real()*(y).imag()-(x).imag()*(y).real()) 
#define cross(x, y) (((x)*conj(y)).imag())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
void solve()
{
    int n;
    cin >> n;
 
    int px, py;
    cin >> px >> py;
 
    complex<int> prev = {px, py};
    complex<int> first = prev;
 
    int res = 0;
 
    for (int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        complex<int> v = {x, y};
        res += cross(prev, v);
        prev = v;
    }
    res += cross(prev, first);
 
    cout << abs(res);
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
    //ifstream f("testcase.txt");
    //cin.rdbuf(f.rdbuf());
 
    for (int i = 0; i < t; i++)
        solve();
}