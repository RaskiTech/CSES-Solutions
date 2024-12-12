#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
int mod = 1e9+7;
 
void solve()
{
    int n;
    cin >> n;
 
    vector<pair<int, pair<int, int>>> events(2*n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        events[2*i] = {a, {0, i}};
        events[2*i+1] = {b, {1, i}};
    }
    sort(events.begin(), events.end());
 
    int c = 0;
    int resCount = 0;
 
    vector<int> res(n);
    set<int> rooms;
 
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].second.first)
        {
            rooms.insert(res[events[i].second.second]);
        }
        else
        {
            if (rooms.empty())
            {
                resCount++;
                rooms.insert(resCount);
            }
            res[events[i].second.second] = *rooms.begin();
            rooms.erase(*rooms.begin());
        }
    }
    cout << resCount << '\n';
    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';
} 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    //std::ifstream file("testcase.txt"); std::cin.rdbuf(file.rdbuf());
 
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}