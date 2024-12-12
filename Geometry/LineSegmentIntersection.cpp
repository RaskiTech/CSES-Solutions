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
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
 
    complex<int> v1 = {x1, y1};
    complex<int> v2 = {x2, y2};
    complex<int> v3 = {x3, y3};
    complex<int> v4 = {x4, y4};
 
    // Case: end point
    if (v1 == v3 || v2 == v3 || v1 == v4 || v2 == v4)
    {
        cout << "YES\n";
        return;
    }
 
    // Case: The same line
    if (cross(v2-v1, v3-v2) == 0 && cross(v3-v2, v4-v3) == 0)
    {
        vector<complex<int>> ps = {v1, v2, v3, v4};
        sort(ps.begin(), ps.end(), [](auto v1, auto v2){ if (v1.real() == v2.real()) return v1.imag() < v2.imag(); else return v1.real() < v2.real(); });
        if ((ps[0] == v1 || ps[0] == v2) == (ps[1] == v1 || ps[1] == v2))
        {
            cout << "NO\n";
            return;
        }
        else
        {
            cout << "YES\n";
            return;
        }
    }
 
 
    // Other on the left side and other on the right side
    int r1 = sign(cross(v2-v1, v3-v1));
    int r2 = sign(cross(v2-v1, v4-v1));
    int r3 = sign(cross(v4-v3, v1-v3));
    int r4 = sign(cross(v4-v3, v2-v3));
    if (r1 != r2 && r3 != r4)
    {
        cout << "YES\n";
        return;
    }
 
    cout << "NO\n";
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