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
#include <iomanip>
 
#define int long long
using namespace std;
 
#define cross(x, y) (((x)*conj(y)).imag())
#define mag(x) (sqrt(x.imag() * x.imag() + x.real() * x.real())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
unordered_map<string, long double> mp;
 
int mod = 1e9+7;
 
int p(int a, int b)
{
    if (b == 0) return 1;
    else if (b % 2 == 0) { int r = p(a, b/2); return (r*r) % mod; }
    else return (p(a, b-1)*a) % mod; 
}
 
void solve()
{
    int a, b;
    cin >> a >> b;
    cout << p(a, b) << '\n';
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cout.precision(25);
    //setprecision(10);
    //cin.tie(0);
 
    int t = 1;
 
    cin >> t;
    //ifstream f("testcase.txt");
    //cin.rdbuf(f.rdbuf());
 
    for (int i = 0; i < t; i++)
        solve();
}