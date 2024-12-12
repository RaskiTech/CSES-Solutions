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
    int n, q;
    cin >> n >> q;
    
    int sum = 0;
    vector<int> vec(n+1);
    vec[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        vec[i] = sum;
    }
 
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << vec[b] - vec[a-1] << '\n';
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