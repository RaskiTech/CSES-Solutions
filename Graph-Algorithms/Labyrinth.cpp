#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
void solve()
{
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> map(n, vector<int>(m));
    int sI;
    int sJ;
    int eI;
    int eJ;
 
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            map[i][j] = s[j] == '#';
            if (s[j] == 'A')
            {
                sI = i;
                sJ = j;
            }
            if (s[j] == 'B')
            {
                eI = i;
                eJ = j;
            }
        }
    }
 
    queue<pair<int, int>> path;
    path.push({sI, sJ});
    while (!path.empty())
    {
        auto [i, j] = path.front();
        if (i > 0 && map[i-1][j] == 0)
        {
            map[i-1][j] = 1;
            path.push({i-1, j});
        }
        if (j > 0 && map[i][j-1] == 0)
        {
            map[i][j-1] = 2;
            path.push({i, j-1});
        }
        if (i < n-1 && map[i+1][j] == 0)
        {
            map[i+1][j] = 3;
            path.push({i+1, j});
        }
        if (j < m-1 && map[i][j+1] == 0)
        {
            map[i][j+1] = 4;
            path.push({i, j+1});
        }
        path.pop();
    }
 
    if (map[eI][eJ] == 0)
    {
        cout << "NO";
        return;
    }
    string rev;
    while (eI != sI || eJ != sJ)
    {
        switch (map[eI][eJ])
        {
            case 1: { rev.push_back('U'); eI++; break; }
            case 2: { rev.push_back('L'); eJ++; break; }
            case 3: { rev.push_back('D'); eI--; break; }
            case 4: { rev.push_back('R'); eJ--; break; }
        }
    }
 
    cout << "YES\n";
    cout << rev.size() << '\n';
    reverse(rev.begin(), rev.end());
    cout << rev << endl;
 
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