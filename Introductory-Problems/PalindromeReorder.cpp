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
 
#define int long long
using namespace std;
 
void solve() {
    //int n, x;
    //cin >> n >> x;
 
    array<int, 26> freq;
    for (int i = 0; i < freq.size(); i++)
        freq[i] = 0;
 
    string s;
    cin >> s;
    for (char c : s)
        freq[c - 'A']++;
    
    char middle = 0;
 
    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i] % 2 == 1)
        {
            if (middle != 0)
            {
                cout << "NO SOLUTION";
                return;
            }
            middle = i + 'A';
            freq[i]--;
        }
    }
 
    int strIdx = 0;
    int freqIdx = 0;
    while (freqIdx < freq.size())
    {
        for (int i = 0; i < freq[freqIdx] / 2; i++)
        {
            s[strIdx + i] = freqIdx + 'A';
        }
        strIdx += freq[freqIdx] / 2;
        freqIdx++;
        int insertAmount = freq[freqIdx] / 2;
    }
    if (middle != 0)
    {
        s[strIdx] = middle;
        strIdx++;
    }
    freqIdx--;
    while (freqIdx >= 0)
    {
        for (int i = 0; i < freq[freqIdx] / 2; i++)
        {
            s[strIdx + i] = freqIdx + 'A';
        }
        strIdx += freq[freqIdx] / 2;
        freqIdx--;
        int insertAmount = freq[freqIdx] / 2;
    }
 
    cout << s;
 
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