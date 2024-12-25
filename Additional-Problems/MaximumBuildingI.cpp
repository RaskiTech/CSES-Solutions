#include <bits/stdc++.h>
using namespace std;
#define int long long
 
 
signed main() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> mappi(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
 
        mappi[i][0] = s[0] == '.' ? 1 : 0;
        for (int j = 1; j < m; j++)
        {
            if (s[j] == '*')
                mappi[i][j] = 0;
            else
                mappi[i][j] = mappi[i][j-1] + 1;
        }
    }
 
    vector<pair<int, int>> rising;
    rising.reserve(n);
    int maxRes = 0;
    for (int j = 0; j < m; j++)
    {
        rising.clear();
        for (int i = 0; i < n; i++)
        {
            int len = mappi[i][j];
            int deepestIndex = i;
            while (!rising.empty() && rising.back().first > len)
            {
                maxRes = max(maxRes, rising.back().first * (i - rising.back().second));
                deepestIndex = rising.back().second;
                rising.pop_back();
            }
            rising.push_back({len, deepestIndex});
        }
        while (!rising.empty())
        {
            maxRes = max(maxRes, rising.back().first * (n - rising.back().second));
            rising.pop_back();
        }
    }
    cout << maxRes;
}