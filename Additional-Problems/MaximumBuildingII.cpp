#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> mappi(n, vector<int>(m));
    vector<vector<int>> sums(n, vector<int>(m));
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
    for (int j = 0; j < m; j++)
    {
        rising.clear();
        for (int i = 0; i < n; i++)
        {
            int len = mappi[i][j];
            int deepestIndex = i;
            while (!rising.empty() && rising.back().first > len)
            {
                pair<int, int> topLenIdx = rising.back();
                deepestIndex = topLenIdx.second;
                rising.pop_back();

                int vLen = i - topLenIdx.second;
                int hIdx = topLenIdx.first - 1;
                sums[vLen-1][hIdx]++;
                if (len == 0 && rising.empty())
                    continue;
                hIdx = len - 1;
                if (!rising.empty())
                    hIdx = max(hIdx, rising.back().first-1);
                sums[vLen-1][hIdx]--;
            }
            if ((rising.empty() || rising.back().first < len) && len != 0)
                rising.push_back({len, deepestIndex});
        }
        while (!rising.empty())
        {
            pair<int, int> topLenIdx = rising.back();
            rising.pop_back();

            int vLen = n - topLenIdx.second;
            int hIdx = topLenIdx.first-1;
            sums[vLen-1][hIdx]++;
            if (rising.empty())
                continue;
            hIdx = rising.back().first-1;
            sums[vLen-1][hIdx]--;
        }
    }


    for (int j = 0; j < m; j++)
        for (int i = n-2; i >= 0; i--)
            sums[i][j] = sums[i][j] + sums[i+1][j];
    for (int j = 0; j < m; j++)
        for (int i = n-2; i >= 0; i--)
            sums[i][j] = sums[i][j] + sums[i+1][j];
    for (int i = 0; i < n; i++)
        for (int j = m-2; j >= 0; j--)
            sums[i][j] = sums[i][j] + sums[i][j+1];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << sums[i][j] << ' ';
        cout << endl;
    }
}