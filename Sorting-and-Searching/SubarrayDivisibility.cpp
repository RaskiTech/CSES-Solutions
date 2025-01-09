#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    cin >> n;

    vector<int> times(n, 0);
    times[0] = 1;

    int sum = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum = ((sum + a) % n + n) % n;
        result += times[sum];
        times[sum]++;
    }
    cout << result;
}