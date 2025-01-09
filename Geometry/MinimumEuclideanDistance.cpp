#include <bits/stdc++.h>
#define int long long
using namespace std;

#define cross(x, y) (((x)*conj(y)).imag())

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        points[i] = {a, b};
    }
    sort(points.begin(), points.end());

    set<pair<int, int>> close;
    vector<pair<int, int>> rem;
    rem.reserve(50);
    int minDist = LLONG_MAX-INT_MAX;
    int minRes = minDist;
    for (auto& point : points)
    {
        auto it = close.lower_bound({point.second-minDist, LLONG_MIN/2});
        auto end = close.upper_bound({point.second+minDist, LLONG_MAX/2});

        for (; it != end; it++)
        {
            if ((*it).second < point.first - minDist)
            {
                rem.push_back(*it);
                continue;
            }
            int diffX = point.first - (*it).second;
            int diffY = point.second - (*it).first;
            int distSquared = diffX*diffX+diffY*diffY;
            if (distSquared < minRes)
            {
                minRes = distSquared;
                minDist = ceil(sqrt(minRes));
            }
        }
        for (auto& p : rem)
            close.erase(p);
        rem.clear();

        close.insert({point.second, point.first});
    }
    cout << minRes << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}