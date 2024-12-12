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
 
#define int long long
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> prev(n+1, 0);
    vector<int> curr(n+1, 0);
    prev[1] = 1;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int cIdx = 0; cIdx < s.size(); cIdx++)
        {
            if (s[cIdx] == '*')
                curr[cIdx+1] = 0;
            else
                curr[cIdx+1] = (prev[cIdx+1] + curr[cIdx]) % 1000000007;
        }
        swap(prev, curr);
    }
 
    cout << prev[n];
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