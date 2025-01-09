#include <bits/stdc++.h>
#include <complex>
#define int long long
using namespace std;

#define cross(x, y) (((x)*conj(y)).imag())

void solve()
{
    int n;
    cin >> n;

    vector<complex<int>> points(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        points[i] = {a, b};
    }
    sort(points.begin(), points.end(), [](auto& f, auto& s) { if (f.real() == s.real()) return f.imag() < s.imag(); return f.real() < s.real(); });

    vector<complex<int>> res;
    // Up hull
    for (int i = 0; i < points.size(); i++)
    {
        complex<int>& p = points[i];
        while (res.size() >= 2 && cross(res[res.size()-1] - res[res.size()-2], points[i] - res[res.size()-1]) < 0)
            res.pop_back();
        res.push_back(points[i]);
    }

    vector<complex<int>> res2;

    // Down hull
    for (int i = 0; i < points.size(); i++)
    {
        while (res2.size() >= 2 && cross(res2[res2.size()-1] - res2[res2.size()-2], points[i] - res2[res2.size()-1]) > 0)
            res2.pop_back();
        res2.push_back(points[i]);
    }

    cout << res.size()+res2.size()-2 << '\n';
    for (int i = 0; i < res.size(); i++)
        cout << res[i].real() << ' ' << res[i].imag() << '\n';
    for (int i = 1; i < res2.size()-1; i++)
        cout << res2[i].real() << ' ' << res2[i].imag() << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}