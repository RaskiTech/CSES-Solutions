#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7;

// Burnside's lemma

int power(int base, int p)
{
    if (p == 0)
        return 1;
    int res = power(base, p/2);
    if (p % 2 == 1)
        return (res * res % mod * base) % mod;
    else
        return res * res % mod;
}

void solve() {
    int n;
    cin >> n;
    int squares = n * n;

    if (n % 2 == 0)
    {
        int half = n/2;
        int quarter = half * half;
        int afterOne = power(2, quarter);
        int afterTwo = (afterOne * afterOne) % mod;

        int result = (power(2, squares) + 2 * afterOne + afterTwo) % mod;
        cout << (result * power(4, mod-2)) % mod;

    }
    else
    {
        int half = n/2;
        int quarter = half * (half+1);
        int afterOne = power(2, quarter);
        int afterTwo = (2 * afterOne * afterOne) % mod;
        afterOne *= 2;
        afterOne %= mod;

        int result = (power(2, squares) + 2 * afterOne + afterTwo) % mod;
        cout << (result * power(4, mod-2)) % mod;
    }
}
 
 
signed main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}