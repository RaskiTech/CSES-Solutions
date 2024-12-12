#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <climits>
#include <cmath>
#include <functional>
 
//#define int long long
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    int res = 1;
 
    for (int i = 0; i < n; i++)
    {
        res = (res * 2) % 1000000007;
    }
    cout << res;
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
