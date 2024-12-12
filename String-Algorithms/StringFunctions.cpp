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
 
#define int long long
using namespace std;
 
 
void solve() {
    string s;
    cin >> s;
 
    vector<int> zArr(s.size());
    vector<int> aArr(s.size());
 
    int l = 0;
    int r = 0;
 
    for (int i = 1; i < s.size(); i++)
    {
        if (i > r)
        {
            l = 0;
            r = i;
            while (r < s.size() && s[r] == s[l])
            {
                //cout << r << " " << l << " " << endl;
                aArr[r] = max(aArr[r], l+1);
                l++;r++;
            }
            r--;
            l = i;
            zArr[i] = r-l+1;
        }
        else
        {
 
            //cout << r << " " << l << " ALERT" << endl;
            if (zArr[i-l] < r-i+1)
                zArr[i] = zArr[i-l];
            else
            {
                l = r-i+1;
                r++;
                int c = 1;
                while (r < s.size() && s[r] == s[l])
                {
                    //cout << r << " " << l << " " << endl;
                    aArr[r] = max(aArr[r], l+1);
                    c++;
                    r++;l++;
                }
                r--;
                l = i;
                zArr[i] = r-l+1;
            }
        }
    }
 
    for (int i = 0; i < s.size(); i++)
        cout << zArr[i] << " ";
    cout << '\n';
    for (int i = 0; i < s.size(); i++)
        cout << aArr[i] << " ";
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
    //ifstream f("testcase.txt");
    //cin.rdbuf(f.rdbuf());
 
    for (int i = 0; i < t; i++)
        solve();
 
    return 0;
}