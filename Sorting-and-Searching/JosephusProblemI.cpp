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
#include <fstream>
#include <bitset>
#include <complex>
 
#define int long long
using namespace std;
 
#define cross(x, y) (((x)*conj(y)).imag())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
void solve()
{
    int n;
    cin >> n;
 
    bitset<(int)(2e5)> bs;
    for (int i = 0; i < n; i++)
        bs[i] = true;
    
 
    bool next = false;
    while (n > 0)
    {
        for (int i = 0; i < bs.size(); i++)
        {
            if (bs[i])
            {
                if (next)
                {
                    bs[i] = false;
                    cout << i+1 << ' ';
                    n--;
                }
                next = !next;
            }
        }
    }
 
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
    //ifstream f("testcase.txt");
    //cin.rdbuf(f.rdbuf());
 
    for (int i = 0; i < t; i++)
        solve();
}
