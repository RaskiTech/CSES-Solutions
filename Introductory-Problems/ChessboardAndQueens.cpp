#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <climits>
#include <cmath>
#include <functional>
#include <type_traits>
#include <fstream>
#include <bitset>
#include <complex>
#include <iomanip>
 
#define int long long
using namespace std;
 
#define cross(x, y) (((x)*conj(y)).imag())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
int mod = 1e9+7;
 
int counts(vector<bool>& l, vector<bool>& r, vector<bool>& s, int level, vector<string>& board)
{
    if (level == board.size())
        return 1;
 
    int sum = 0;
    for (int i = 0; i < board[level].size(); i++)
    {
        if (board[level][i] == '*')
            continue;
        
        int li = i + level;
        int ri = (board[level].size()-i-1) + level;
        if (l[li] == false && r[ri] == false && s[i] == false)
        {
            l[li] = true;
            r[ri] = true;
            s[i] = true;
            sum += counts(l, r, s, level+1, board);
            l[li] = false;
            s[i] = false;
            r[ri] = false;
        }
    }
 
    return sum;
}
 
void solve()
{
    vector<string> board(8);
    for (int i = 0; i < board.size(); i++)
    {
        cin >> board[i];
    }
 
    vector<bool> l(16);
    vector<bool> r(16);
    vector<bool> s(16);
    cout << counts(l, r, s, 0, board);
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