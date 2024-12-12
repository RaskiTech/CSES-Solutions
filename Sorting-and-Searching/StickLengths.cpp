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
    int n, m, h;
    cin >> n;
 
    vector<int> sticks(n);
    for (int i = 0; i < n; i++)
        cin >> sticks[i];
 
    sort(sticks.begin(), sticks.end());
    int target = sticks[n/2];
 
    int cost = 0;
    for (int i = 0; i < sticks.size(); i++)
        cost += abs(sticks[i] - target);
    cout << cost;
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