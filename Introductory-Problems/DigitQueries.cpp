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
    int k;
    cin >> k;
    k--;
 
    int n = 1;
    int length = 1;
    while (true)
    {
        int amount = pow(10, length) - pow(10, length - 1);
        int indexAmount = amount * length;
        if (k < indexAmount)
            break;
        k -= indexAmount;
        length++;
        n += amount;
    }
 
    n += k / length;
    cout << to_string(n)[k % length] << '\n';
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
 
    cin >> t;
 
    for (int i = 0; i < t; i++)
        solve();
 
    return 0;
}