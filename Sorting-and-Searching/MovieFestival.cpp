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
 
 
void solve() {
    int n;
    cin >> n;
 
    vector<pair<int, int>> times(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        times[i] = {b, a};
    }
    sort(times.begin(), times.end());
 
    int l = 0;
    int count = 0;
    for (int i = 0; i < times.size(); i++)
    {
        if (times[i].second < l)
            continue;
        l = times[i].first;
        count++;
    }
    cout << count;
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