#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7;

signed main()
{
    string s;
    cin >> s;
    array<int, 26> counts;
    fill(counts.begin(), counts.end(), 0);
    int prev = 1;
    for (int i = 0; i < s.size(); i++)
    {
        int last = prev;
        prev = (2 * prev - counts[s[i]-'a']) % mod;
        counts[s[i]-'a'] = last;

    }
    cout << (prev-1 + mod) % mod << '\n';
}