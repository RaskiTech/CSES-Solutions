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
 
    vector<pair<int, int>> sticks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sticks[i].first;
        sticks[i].second = i;
    }
 
    sort(sticks.begin(), sticks.end());
 
    int rounds = 1;
    int maxVal = sticks[0].second;
    for (int i = 1; i < sticks.size(); i++)
    {
        if (sticks[i].second < maxVal)
        {
            rounds++;
        }
        maxVal = sticks[i].second;
    }
    
    cout << rounds;
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