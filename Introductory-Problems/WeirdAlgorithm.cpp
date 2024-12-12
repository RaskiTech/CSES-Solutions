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
 
    while (n != 1)
    {
        cout << n << " ";
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
            n = 3 * n + 1;
    }
    cout << n;
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