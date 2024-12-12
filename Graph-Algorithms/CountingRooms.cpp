#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <functional>
#include <type_traits>
#include <bitset>
 
#define int long long
using namespace std;
 
int N;
int M;
 
void dfs(vector<string>& map, vector<vector<bool>>& visited, int x, int y)
{
    if (x < 0 || y < 0 || x >= M || y >= N || visited[y][x] || map[y][x] == '#')
        return;
    visited[y][x] = true;
    
    dfs(map, visited, x-1, y);
    dfs(map, visited, x+1, y);
    dfs(map, visited, x, y+1);
    dfs(map, visited, x, y-1);
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    N = n;
    M = m;
 
    vector<string> dungeon(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dungeon[i];
    }
 
    vector<vector<bool>> visited(n, vector<bool>(m));
    int rooms = 0;
    for (int i = 0; i < visited.size(); i++)
    {
        for (int j = 0; j < visited[i].size(); j++)
        {
            if (!visited[i][j] && dungeon[i][j] == '.')
            {
                dfs(dungeon, visited, j, i);
                rooms++;
            }
        }
    }
    cout << rooms;
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
        solve();
 
    return 0;
}