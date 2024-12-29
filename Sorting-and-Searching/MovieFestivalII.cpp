#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        movies[i] = {b, a};
    }
    sort(movies.begin(), movies.end());

    multiset<int> freeTimes;
    for (int i = 0; i < k; i++)
        freeTimes.insert(0);
    
    int watchable = 0;
    for (int i = 0; i < movies.size(); i++)
    {
        int startTime = movies[i].second;
        auto it = freeTimes.upper_bound(startTime);
        if (it == freeTimes.begin())
            continue;
        it--;
        freeTimes.erase(it);
        freeTimes.insert(movies[i].first);
        watchable++;
    }
    cout << watchable;
}

signed main()
{
    solve();
}