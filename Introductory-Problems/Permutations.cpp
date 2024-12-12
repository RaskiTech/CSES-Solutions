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
    int n;
    cin >> n;
 
    if (n == 1)
    {
        cout << "1";
        return;
    }
    else if (n == 4)
    {
        cout << "2 4 1 3";
        return;
    }
    else if (n < 4)
    {
        cout << "NO SOLUTION";
        return;
    }
 
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            cout << i / 2 + 1 << " ";
        else
            cout << (n+1) / 2 + i / 2 + 1 << " ";
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