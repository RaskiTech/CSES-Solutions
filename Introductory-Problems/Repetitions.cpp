#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
 
//#define int long long
using namespace std;
 
 
void solve() {
    string s;
    cin >> s;
 
    int maxLength = 1;
    int length = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i-1])
            length++;
        else
            length = 1;
        maxLength = max(maxLength, length);
    }
    cout << maxLength;
 
}
 
 
signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
        solve();
 
    return 0;
}