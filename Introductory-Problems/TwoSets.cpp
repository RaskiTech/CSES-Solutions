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
 
//#define int long long
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    if (n % 2 == 0)
    {
        if ((n / 2) % 2 == 1)
        {
            cout << "NO";
            return;
        }
 
        cout << "YES\n" << n / 2 << '\n';
        for (int i = 0; i < n / 4; i++)
        {
            cout << i*2 + 1 << " ";
            cout << n - i*2 << " ";
        }
        cout << '\n' << n / 2 << '\n';
        for (int i = 0; i < n / 4; i++)
        {
            cout << i*2 + 2 << " ";
            cout << n - i*2 - 1 << " ";
        }
 
        return;
    }
    else
    {
        if ((n / 2) % 2 == 0)
        {
            cout << "NO\n";
            return;
        }
 
        cout << "YES\n";
        cout << (n / 2) + 1 << '\n';
        cout << "1 2 ";
        for (int i = 4; i <= n; i += 2)
        {
            if ((i / 2) % 2 == 0)
                cout << i << ' ';
            else
                cout << i+1 << ' ';
        }
        cout << '\n' << (n / 2) << '\n';
        cout << "3 ";
        for (int i = 4; i <= n; i += 2)
        {
            if ((i / 2) % 2 == 0)
                cout << i+1 << ' ';
            else
                cout << i << ' ';
        }
 
        return;
    }
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