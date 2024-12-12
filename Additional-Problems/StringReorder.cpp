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
    string s;
    cin >> s;
 
    array<int, 26> arr;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        arr[i] = 0;
    for (int i = 0; i < s.size(); i++)
    {
        arr[s[i]-'A']++;
        sum++;
    }
 
    int l = 0;
    while (arr[l] == 0)
        l++;
    int r = l+1;
    while (r < arr.size() && arr[r] == 0)
        r++;
    if (r == arr.size())
    {
        if (arr[l] == 1)
            cout << (char)(l+'A');
        else
            cout << -1;
        
        return;
    }
 
    int biggest = 0;
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] > arr[biggest])
            biggest = i;
    
    if (arr[biggest] > sum - arr[biggest] + 1)
    {
        cout << -1;
        return;
    }
 
    int lastIdx = -1;
    while (sum > 0)
    {
        if (arr[biggest] > sum - arr[biggest])
        {
            cout << (char)(biggest+'A');
            arr[biggest]--;
            sum--;
            lastIdx = biggest;
 
            for (int i = l; i < arr.size(); i++)
                if (arr[i] > arr[biggest])
                    biggest = i;
            continue;
        }
 
        if (lastIdx != l)
        {
            cout << (char)(l+'A');
            arr[l]--;
            sum--;
            lastIdx = l;
            if (arr[l] == 0)
            {
                l = r;
                r++;
                while (r < arr.size() && arr[r] == 0)
                    r++;
            }
            if (biggest == l)
            {
                for (int i = l; i < arr.size(); i++)
                    if (arr[i] > arr[biggest])
                        biggest = i;
            }
            continue;
        }
        if (lastIdx != r)
        {
            cout << (char)(r+'A');
            arr[r]--;
            sum--;
            lastIdx = r;
            if (arr[r] == 0)
            {
                r++;
                while (r < arr.size() && arr[r] == 0)
                    r++;
            }
            if (biggest == r)
            {
                for (int i = l; i < arr.size(); i++)
                    if (arr[i] > arr[biggest])
                        biggest = i;
            }
            continue;
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