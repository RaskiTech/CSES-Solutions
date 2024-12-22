#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int mod = 1e9+7;
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
    factorial[0] = 1;
    for (int i = 1; i < factorial.size(); i++)
        factorial[i] = (factorial[i-1] * i) % mod;
 
    string s;
    cin >> s;
 
    array<int, 26> chars;
    for (int i = 0; i < chars.size(); i++)
        chars[i] = 0;
    
    for (int i = 0; i < s.size(); i++)
    {
        chars[s[i]-'a']++;
    }
 
    int remaining = s.size();
    int res = 1;
    for (int amount : chars)
    {
        int mult = nCr(remaining, amount);
        res *= mult;
        res %= mod;
        remaining -= amount;
    }
 
    cout << res;
}
 
signed main() {
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}