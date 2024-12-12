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
    int t;
    cin >> t;
    vector<int> tests(t);
    for (int i = 0; i < t; i++)
        cin >> tests[i];
    
    int maxN = *max_element(tests.begin(), tests.end());
 
    vector<int> both(maxN+1);
    vector<int> topFull(maxN+1);
    both[0] = 1;
    both[1] = 1;
    topFull[0] = 1;
    topFull[1] = 1;
    for (int i = 2; i < both.size(); i++)
    {
        //topFull[i] = topFull[i-1] + both[i-1];
        //sum += jj
 
        topFull[i] = topFull[i-1] + (both[i-1] + topFull[i-1]);
        topFull[i] %= 1000000007;
        both[i] = topFull[i-1] + 4 * both[i-1];
        both[i] %= 1000000007;
    }
 
    for (auto test : tests)
    {
        cout << (both[test] + topFull[test]) % 1000000007 << '\n';
    }
 
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