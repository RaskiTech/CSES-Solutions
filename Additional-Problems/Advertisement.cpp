#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> data;
    int maxVal = 0;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int startPos = i;
        while (!data.empty() && data.back().first > a)
        {
            maxVal = max(maxVal, (i - data.back().second) * data.back().first);
            startPos = data.back().second;
            data.pop_back();
        }
        if (data.empty() || data.back().first != a)
            data.push_back({a, startPos});
    }
    while (!data.empty())
    {
        maxVal = max(maxVal, (n - data.back().second) * data.back().first);
        data.pop_back();
    }

    cout << maxVal;
}