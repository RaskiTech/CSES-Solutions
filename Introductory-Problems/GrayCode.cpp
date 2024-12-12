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
 
void Print(vector<int>& vals)
{
    for (int i = 0; i < vals.size(); i++)
        cout << vals[i];
    cout << '\n';
}
 
void req(vector<int>& vals, int idx)
{
    if (idx == vals.size())
        return;
 
    req(vals, idx+1);
    vals[idx] ^= 1;
    Print(vals);
    req(vals, idx+1);
}
 
void solve() {
    int n;
    cin >> n; 
 
    vector<int> vals(n);
    Print(vals);
    req(vals, 0);
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