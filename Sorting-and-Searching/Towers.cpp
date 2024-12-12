#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <functional>
#include <type_traits>
#include <bitset>
 
#define int long long
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> tops(1);
 
    cin >> tops[0];
 
    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        int b = lower_bound(tops.begin(), tops.end(), a+1) - tops.begin();
        if (b == tops.size())
            tops.push_back(a);
        else
            tops[b] = a;
    }
 
    cout << tops.size();
 
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
        solve();
 
    return 0;
}