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
#include <type_traits>
#include <fstream>
#include <bitset>
#include <complex>
#include <iomanip>
 
#include <ext/pb_ds/assoc_container.hpp> // gcc only
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
#define int long long
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
 
    vector<pair<int, pair<int, int>>> projects(n);
 
    for (int i = 0; i < n; i++)
    {
        int a, b, p;
        cin >> a >> b >> p;
        projects[i] = {b, {a, p}};
    }
    sort(projects.begin(), projects.end());
 
    vector<int> totalSum(n);
    totalSum[0] = projects[0].second.second;
 
    for (int i = 1; i < n; i++)
    {
        int beforeIdx = (upper_bound(projects.begin(), projects.end(), pair<int, pair<int, int>>{projects[i].second.first, {0, 0}}) - projects.begin());
        int val = beforeIdx == 0 ? 0 : totalSum[beforeIdx-1];
        totalSum[i] = max(totalSum[i-1], val + projects[i].second.second);
    }
    cout << totalSum.back();
 
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        solve();
        //cout.flush();
    }
}