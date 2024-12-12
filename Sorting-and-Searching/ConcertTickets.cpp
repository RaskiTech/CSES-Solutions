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
    int n, m;
    cin >> n >> m;
 
    multiset<int> S;
 
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        S.insert(a);
    }
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        //auto it = upper_bound(S.begin(), S.end(), a);
        auto it = S.upper_bound(a);
        if (it == S.begin())
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << (*(--it)) << '\n';
            S.erase(it);
        }
    }
 
 
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