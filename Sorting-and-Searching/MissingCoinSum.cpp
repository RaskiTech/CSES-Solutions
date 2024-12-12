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
 
    int total = 0;
    int i = 0;
    while (i < sticks.size())
    {
        if (sticks[i] > total + 1)
        {
            cout << total + 1;
            return;
        }
 
        total += sticks[i];
        i++;
    }
 
    cout << total+1;
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