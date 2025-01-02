#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7;
const int maxN = 500;
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
array<int, maxN> factorial;
 
int nCr(int a, int b)
{
    int ax = factorial[a];
    int bx = p((factorial[b] * factorial[a-b]) % mod, mod-2);
    return (ax * bx) % mod;
}

array<array<int, maxN>, maxN> dp;
array<array<int, maxN>, maxN> nCrs;
int search(int l, int r, const string& s)
{
    if (r <= l+1)
    {
        if (r == l+1)
            return s[l] == s[r];
        if (r == l)
            return 0;
        return 1;
    }
    if (dp[l][r] != LLONG_MAX/2)
        return dp[l][r];
    dp[l][r] = 0;
    for (int i = l+1; i <= r; i++)
    {
        if (s[l] != s[i])
            continue;
        dp[l][r] += search(l+1, i-1, s) * search(i+1, r, s) % mod * nCrs[(r-l+1)/2][(r-i+1)/2];
        dp[l][r] %= mod;
    }
    return dp[l][r];
}

signed main() {
    string s;
    cin >> s;

    factorial[0] = 1;
    for (int i = 1; i < factorial.size(); i++)
        factorial[i] = (factorial[i-1] * i) % mod;
    for (int i = 0; i < nCrs.size(); i++)
        for (int j = 0; j <= i; j++)
            nCrs[i][j] = nCr(i, j);
    for (int i = 0; i < dp.size(); i++)
        for (int j = 0; j < dp[i].size(); j++)
            dp[i][j] = LLONG_MAX/2;

    cout << search(0, s.size()-1, s);
}