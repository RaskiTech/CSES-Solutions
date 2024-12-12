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
    int n, m;
    cin >> n >> m;
 
    vector<pair<complex<int>, complex<int>>> lines(n);
 
    int x1, y1;
    cin >> x1 >> y1;
    complex<int> first = {x1, y1};
    complex<int> prev = first;
 
    for (int i = 0; i < n-1; i++)
    {
        int x, y;
        cin >> x >> y;
        complex<int> t = {x, y};
 
        lines[i] = {prev, t};
 
        prev = t;
    }
    lines[n-1] = {prev, first};
    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i].first.imag() > lines[i].second.imag())
            swap(lines[i].first, lines[i].second);
    }
 
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        complex<int> test = {x, y};
 
        bool boundary = false;
        int intersections = 0;
 
        for (int i = 0; i < lines.size(); i++)
        {
            if (lines[i].first.imag() == lines[i].second.imag())
            {
                if (lines[i].first.real() > lines[i].second.real())
                    swap(lines[i].first, lines[i].second);
 
                if (lines[i].first.imag() == test.imag() && lines[i].first.real() <= x && lines[i].second.real() >= x)
                {
                    boundary = true;
                    break;
                }
                continue;
            }
 
            if (lines[i].first.imag() > test.imag() || lines[i].second.imag() < test.imag())
                continue;
 
            int c = cross(lines[i].second - lines[i].first, test - lines[i].first);
            if (c == 0)
            {
                boundary = true;
                break;
            }
 
            if (lines[i].first.imag() == test.imag())
                continue;
 
            
            if (c > 0)
                intersections++;
        }
 
        if (boundary)
        {
            cout << "BOUNDARY\n";
            continue;
        }
 
        if (intersections % 2 == 0)
        {
            cout << "OUTSIDE\n";
        }
        else
        {
            cout << "INSIDE\n";
        }
    }
 
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