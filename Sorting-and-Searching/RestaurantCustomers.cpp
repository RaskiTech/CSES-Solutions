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
 
    vector<pair<int, int>> vec;
    vec.reserve(2*n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, 1});
        vec.push_back({b, 0});
    }
 
    sort(vec.begin(), vec.end());
 
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].second == 1)
            count++;
        else
            count--;
 
        maxCount = max(maxCount, count);
    }
    cout << maxCount;
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