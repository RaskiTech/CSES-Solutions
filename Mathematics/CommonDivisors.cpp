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
 
int maxRes = 1;
void addTo(vector<int>& gcds, vector<pair<int, int>>& factors, int idx, int val)
{
    if (idx == factors.size())
    {
        // cout << "Coming with val " << val << endl;
        if (gcds[val])
            maxRes = max(maxRes, val);
        gcds[val] = 1;
    }
    else
    {
        for (int i = 0; i <= factors[idx].second; i++)
        {
            addTo(gcds, factors, idx+1, val);
            val *= factors[idx].first;
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> sieve(1e6+2);
    for (int i = 2; i < sieve.size(); i++)
    {
        if (sieve[i])
            continue;
        for (int k = 2*i; k < sieve.size(); k += i)
            if (!sieve[k])
                sieve[k] = i;
    }

    vector<pair<int, int>> factors;
    vector<int> gdcs(1e6+2, 0);
    for (int t = 0; t < n; t++)
    {
        factors.clear();
        int x;
        cin >> x;

        while (sieve[x])
        {
            if (!factors.empty() && factors.back().first == sieve[x])
                factors.back().second++;
            else
                factors.push_back({sieve[x], 1});
            x /= sieve[x];
        }
        if (x > 1)
        {
            if (!factors.empty() && factors.back().first == x)
                factors.back().second++;
            else
                factors.push_back({x, 1});
        }
        
        addTo(gdcs, factors, 0, 1);
    }
    cout << maxRes;
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