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
#include <bitset>
#include <fstream>
 
#define int long long
using namespace std;
 
void solve() {
    string n, m;
    cin >> n >> m;
 
    string s = m+ '#' + n;
    vector<int> zArr(s.size());
    int count = 0;
 
    int l = 0, r = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i > r)
        {
            // Use naive
            r = i;
            l = 0;
            while (r < s.size() && s[l] == s[r])
            {
                l++;
                r++;
            }
            r--;
            l = i;
            zArr[i] = r-i+1;
        }
        else
        {
            if (zArr[i-l] < r-i+1)
            {
                zArr[i] = zArr[r-i];
            }
            else
            {
                l = r-i+1;
                r = r+1;
                while (r < s.size() && s[l] == s[r])
                {
                    l++;
                    r++;
                }
                l = i;
                r--;
                zArr[i] = r-l+1;
            }
        }
        if (zArr[i] == m.size())
            count++;
    }
    cout << count;
    
}
 
signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t = 1;
    //ifstream f("testcase.txt");
    //cin.rdbuf(f.rdbuf());
    //cin >> t;
    while (t--) { solve(); }
}