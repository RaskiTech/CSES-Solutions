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
 
vector<int> arr;
bool checkArr(int a, int t) {
 
    int amountA = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        amountA += a / arr[i];
        if (amountA < 0)
            break;
    }
 
    if (amountA < 0)
        amountA = LLONG_MAX;
 
    return amountA >= t;
}
 
void solve() {
    int n, t;
    cin >> n >> t;
 
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int l = 1;
    int h = LLONG_MAX/2;
    while (l <= h)
    {
        int mid = (l+h) / 2;
 
        if (checkArr(mid, t))
        {
            h = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    cout << l;
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