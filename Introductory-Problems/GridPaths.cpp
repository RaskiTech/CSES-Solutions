
// Optimisations include:
// Terminate if we reach the final square early
// Terminate if we split the board into two halfs
// Use dp for the first few moves to maximise the effectiveness

#include <bits/stdc++.h> 
#define int long long
using namespace std;
 
bool visOrOutside(int& visited, int x, int y)
{
    if (x < 0 || y < 0 || x >= 7 || y >= 7)
        return true;
    if (visited & (1LL << (x + 7*y)))
        return true;
    return false;
}

unordered_map<int, int> cache;
int backtrack(const string& s, int idx, int x, int y, int visited)
{
    if (idx == s.size())
        return x == 0 && y == 6;
    if (visOrOutside(visited, x, y))
        return 0;
    if (x == 0 && y == 6)
        return 0;
    if ( visOrOutside(visited, x-1, y) &&  visOrOutside(visited, x+1, y) &&
        !visOrOutside(visited, x, y+1) && !visOrOutside(visited, x, y-1))
        return 0;
    if (!visOrOutside(visited, x-1, y) && !visOrOutside(visited, x+1, y) &&
         visOrOutside(visited, x, y+1) &&  visOrOutside(visited, x, y-1))
        return 0;
    
    visited |= (1LL << (x + 7*y));
    int key = visited | ((x+7*y) << 49);
    if (idx < 15 && cache.find(key) != cache.end())
    {
        return cache[key];
    }

    int res = 0;
    switch (s[idx])
    {
        case '?': {
            res += backtrack(s, idx+1, x, y+1, visited);
            res += backtrack(s, idx+1, x, y-1, visited);
            res += backtrack(s, idx+1, x+1, y, visited);
            res += backtrack(s, idx+1, x-1, y, visited);
            break;
        }
        case 'R': {
            res += backtrack(s, idx+1, x+1, y, visited);
            break;
        }
        case 'L': {
            res += backtrack(s, idx+1, x-1, y, visited);
            break;
        }
        case 'U': {
            res += backtrack(s, idx+1, x, y-1, visited);
            break;
        }
        case 'D': {
            res += backtrack(s, idx+1, x, y+1, visited);
            break;
        }
        default: {
        }
    }

    if (idx < 15)
        cache[key] = res;
    return res;
}

void solve()
{
    string s;
    cin >> s;

    cache.reserve(1e5);
    int vis = 0;
    vector<vector<bool>> visGrid(7, vector<bool>(7, false));
    int res = backtrack(s, 0, 0, 0, vis);
    cout << res;
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(15);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        solve();
        cout.flush();
    }
}