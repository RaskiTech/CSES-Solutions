#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
 
#define int long long
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    int steps = 0;
    while (n > 0)
    {
        string num = to_string(n);
        n -= *max_element(num.begin(), num.end()) - '0';
        steps++;
    }
 
    cout << steps;
}
 
 
 
signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
        solve();
 
    return 0;
}