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
 
//#define int long long
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    unordered_set<int, function<size_t(int)>> S(n, [](int value){return hash<int>()(value ^ (0b0101010110111101 << 2)); });
 
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (S.insert(a).second)
            count++;
    }
    cout << count << '\n';
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