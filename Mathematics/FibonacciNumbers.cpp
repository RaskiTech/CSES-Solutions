#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int mod = 1e9+7;
struct Mat {
    int a=0, b=1;
    int c=1, d=1;
    
};
Mat mult(const Mat& f, const Mat& s)
{
    return Mat{(f.a*s.a+f.b*s.c) % mod,
        (f.a*s.b+f.b*s.d) % mod,
        (f.c*s.a+f.d*s.c) % mod,
        (f.c*s.b+f.d*s.d) % mod
    };
}
Mat p(const Mat& base, int power)
{
    if (power == 1)
        return Mat();
    if (power % 2 == 1)
    {
        Mat res = p(base, power/2);
        return mult(mult(res, res), Mat());
    }
    else
    {
        Mat res = p(base, power/2);
        return mult(res, res);
    }
}
 
void solve() {
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return;
    }
    if (n <= 2)
    {
        cout << 1;
        return;
    }
    
    Mat m = p(Mat(), n-2);
    cout << (m.c+m.d) % mod;
}
 
signed main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    for (int i = 0; i < t; i++)
        solve();
}