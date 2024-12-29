#include <bits/stdc++.h>
#define int long long
using namespace std;

// N*logN suffix tree TLEs, we use Lyndon factorization to solve this
string Lyndon(string s) {
    int n = s.size();
    int i = 0;
    int ans = 0;
    while (i < n/2) {
        ans = i;
        int j = i + 1;
        int k = i;
        while (j < n && s[k] <= s[j]) {
            k = s[k] < s[j] ? i : k+1;
            j++;
        }
        while (i <= k)
            i += j - k;
    }
    return s.substr(ans, n/2);
}

void solve() {
    string s;
    cin >> s;
    cout << Lyndon(s+s);
}

signed main()
{
    solve();
}