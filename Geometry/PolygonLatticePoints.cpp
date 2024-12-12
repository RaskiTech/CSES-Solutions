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
 
int gcd(int a, int b)
{
    if (a > b)
        swap(a, b);
    if (a == 0)
        return b;
    
    return gcd(b % a, a);
}
 
void solve()
{
    int n;
    cin >> n;
 
    // Pick: a = b/2 - 1
 
    vector<pair<complex<int>, complex<int>>> lines(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        lines[i].first = {a, b};
        if (i != 0)
            lines[i].second = lines[i-1].first;
    }
    lines[0].second = lines[n-1].first;
 
    int area = 0;
    int latticePoints = 0;
    for (int i = 0; i < lines.size(); i++)
    {
        area += cross(lines[i].first, lines[i].second);
 
        latticePoints += gcd(abs(lines[i].first.real() - lines[i].second.real()), abs(lines[i].first.imag() - lines[i].second.imag()));
    }
    area = abs(area);
    // Area * 2
    cout << (area + 2 - latticePoints) / 2 << " " << latticePoints;
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