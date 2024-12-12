#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
 
#define int long long
using namespace std;
 
void solve() {
    
    int x1, y1, x2, y2, pX, pY;
    cin >> x1 >> y1 >> x2 >> y2 >> pX >> pY;
 
    if (x1 == x2)
    {
        if (pX == x1)
            cout << "TOUCH\n";
        else if ((pX < x1) == (y1 < y2))
            cout << "LEFT\n";
        else
            cout << "RIGHT\n";
        return;
    }
 
    bool swapped = false;
    if (x2 < x1)
    {
        swapped = true;
        swap(x1, x2);
        swap(y1, y2);
    }
 
    long double k = (double)(y2-y1) / (double)(x2-x1);
    long double mid = k * (double)x1;
    long double m = (double)y1 - mid;
    long double Y = k * (double)pX + m;
 
    if (abs(Y - pY) < 0.0000000001)
    {
        cout << "TOUCH\n";
    }
    else
    {
        if ((Y < pY) == swapped)
            cout << "RIGHT\n";
        else
            cout << "LEFT\n";
    }
 
}
 
 
 
signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
 
    int t = 1;
 
    cin >> t;
 
    for (int i = 0; i < t; i++)
        solve();
 
    return 0;
}