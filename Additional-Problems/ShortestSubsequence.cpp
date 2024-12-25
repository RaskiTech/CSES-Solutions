#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string s;
    cin >> s;

    set<char> chars;
    for (int i = 0; i < s.size(); i++)
    {
        chars.insert(s[i]);
        if (chars.size() == 4)
        {
            cout << s[i];
            chars.clear();
        }
    }

    for (char c : {'A', 'T', 'C', 'G'})
    {
        if (chars.find(c) == chars.end())
        {
            cout << c;
            break;
        }
    }
}