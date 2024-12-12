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
    int n, x;
    cin >> n >> x;
 
    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; i++)
        cin >> books[i].first;
    for (int i = 0; i < n; i++)
        cin >> books[i].second;
    
    vector<int> prices(x + 1);
    for (auto& book : books)
    {
        for (int i = x; i >= book.first; i--)
        {
            prices[i] = max(prices[i], prices[i - book.first] + book.second);
        }
    }
    //for (auto p : prices)
    //    cout << p << " ";
 
    cout << *max_element(prices.begin(), prices.end());
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