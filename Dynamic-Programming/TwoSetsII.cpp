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
    
 
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    if (sum % 2 == 1)
    {
        cout << 0;
        return;
    }
 
    vector<int> ways(sum / 2 + 1);
    ways[0] = 1;
    for (int num = 1; num <= n; num++)
    {
        for (int i = ways.size()-1; i >= num; i--)
        {
            ways[i] += ways[i-num];
            ways[i] %= 1000000007 * 2;
        }
    }
 
    cout << (ways[sum / 2] / 2) % 1000000007;
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