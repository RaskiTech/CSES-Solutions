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
 
#define int long long
using namespace std;
 
int diff(vector<int>& vals, int idx, int sum, int other)
{
    if (idx == vals.size())
        return abs(other - sum);
    return min(diff(vals, idx + 1, sum, other + vals[idx]), diff(vals, idx + 1, sum + vals[idx], other));
}
 
void solve() {
    int n;
    cin >> n; 
 
    vector<int> vals(n);
    for (int i = 0; i < n; i++)
        cin >> vals[i];
    cout << diff(vals, 0, 0, 0);
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