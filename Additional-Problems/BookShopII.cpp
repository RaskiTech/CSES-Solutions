#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> bookClusts(n);
    vector<pair<int, int>> books;
    books.reserve(10*n);

    for (int i = 0; i < n; i++)
        cin >> bookClusts[i].first;
    for (int i = 0; i < n; i++)
        cin >> bookClusts[i].second;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        // Add the counts of books as powers of two, so we don't waste as many books in duplicates
        int addC = 1;
        while (a > 0)
        {
            while (addC > a)
                addC>>=1;
            
            books.push_back({bookClusts[i].first * addC, bookClusts[i].second * addC});
            a -= addC;
            addC <<= 1;
        }
    }

    // Standard knapsack
    vector<int> dp(x+1, 0);
    for (auto [price, pages] : books)
    {
        for (int i = x; i >= price; i--)
            dp[i] = max(dp[i], pages + dp[i-price]);
    }
    cout << *max_element(dp.begin(), dp.end());
}


signed main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}