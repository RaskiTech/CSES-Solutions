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
 
    int sum = INT_MIN;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
 
        sum = max(a, sum + a);
        maxSum = max(maxSum, sum);
    }
    cout << maxSum;
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