#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
int mod = 1e9+7;
 
void solve()
{
    int n, k;
    cin >> n >> k;
 
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
 
    int notValid = 0;
    int distinct = 0;
    unordered_map<int, int> contents;
    int r = 0;
 
    for (int l = 0; l < n; l++)
    {
        while (distinct <= k && r < n)
        {
            contents[nums[r]]++;
            if (contents[nums[r]] == 1)
                distinct++;
            r++;
        }
        if (distinct > k)
        {
            notValid += n - r+1;
        }
        contents[nums[l]]--;
        if (contents[nums[l]] == 0)
            distinct--;
    }
 
    cout << (n*(n+1)) / 2 - notValid << endl;
} 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    //std::ifstream file("testcase.txt"); std::cin.rdbuf(file.rdbuf());
 
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}