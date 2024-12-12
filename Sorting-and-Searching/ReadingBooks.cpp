#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
 
    vector<int> v(n);
    int maxVal = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        maxVal = max(maxVal, v[i]*2);
        sum += v[i];
        maxVal = max(maxVal, sum);
    }
    cout << maxVal;
 
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