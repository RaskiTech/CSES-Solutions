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
    string s;
    cin >> s;
 
    vector<int> zArr(s.size());
    vector<int> res;
 
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
                zArr[i] = zArr[i-l];
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
        if (zArr[i] + i == s.size())
            res.push_back(zArr[i]);
    }
 
    for (int i = res.size()-1; i >= 0; i--)
    {
        cout << res[i] << " ";
    }
    
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