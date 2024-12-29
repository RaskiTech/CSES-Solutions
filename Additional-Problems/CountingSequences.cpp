#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int mod = 1e9+7;
int p(int base, int power)
{
    if (power == 0)
        return 1;
    int res = p(base, power/2);
    if (power % 2 == 1)
        return (res * res % mod * base) % mod;
    else
        return (res * res) % mod;
}
vector<int> factorial(2e6+1);
 
int nCr(int a, int b)
{
    int ax = factorial[a];
    int bx = p((factorial[b] * factorial[a-b]) % mod, mod-2);
    return (ax * bx) % mod;
}
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    int total = p(k, n);
 
    int notApplicable = 0;
    int mult = 1;
    for (int i = 1; i <= k; i++)
    {
        notApplicable += mult * nCr(k, i) * p(k-i, n);
        notApplicable %= mod;
        mult *= -1;
    }
    cout << (total - notApplicable + mod) % mod << '\n';
 
}
 
signed main() {
    cin.tie(0);
 
    factorial[0] = 1;
    for (int i = 1; i < factorial.size(); i++)
        factorial[i] = (factorial[i-1] * i) % mod;
 
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}