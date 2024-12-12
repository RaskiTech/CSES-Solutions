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
 
vector<vector<int>> dp;
unordered_map<int, int> cached;
int moves(int a, int b)
{
    if (a == b || (a < 2 && b < 2))
        return 0;
    if (cached.find(a * 1000 + b) != cached.end())
        return cached[a * 1000 + b];
    
    int minMoves = LLONG_MAX;
    for (int i = 1; i < a; i++)
        minMoves = min(minMoves, 1 + moves(i, b) + moves(a-i, b));
    for (int i = 1; i < b; i++)
        minMoves = min(minMoves, 1 + moves(a, i) + moves(a, b-i));
    
    cached[a * 1000 + b] = minMoves;
    return minMoves;
}
 
void solve() {
    int a, b;
    cin >> a >> b;
    dp = vector<vector<int>>(a, vector<int>(b));
    dp[0][0] = 0;
    for (int i = 1; i < a; i++)
        dp[i][0] = i;
    for (int i = 1; i < b; i++)
        dp[0][i] = i;
    for (int x = 1; x < a; x++)
    {
        for (int y = 1; y < b; y++)
        {
            if (x == y)
                dp[x][y] == 0;
            else
            {
                dp[x][y] = LLONG_MAX;
                for (int i = 0; i <= x/2; i++)
                    dp[x][y] = min(dp[x][y], dp[i][y] + dp[x-i-1][y] + 1);
                for (int i = 0; i <= y/2; i++)
                    dp[x][y] = min(dp[x][y], dp[x][i] + dp[x][y-i-1] + 1);
            }
        }
    }
 
/*
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    */
 
    cout << dp[a-1][b-1];
    
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