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
    int n, x;
    cin >> n >> x;
 
    unordered_map<int, int> ints(n);
 
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (ints.find(x - a) != ints.end())
        {
            cout << i + 1 << " " << ints[x-a] + 1;
            return;
        }
        ints[a] = i;
    }
    cout << "IMPOSSIBLE";
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