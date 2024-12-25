#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        double smallest = sqrt(n);
        int minimum = ceil(smallest);
        int inOne = ceil((double)n / minimum);

        if (k < minimum)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }


        int added = 0;
        while (added + (n-added + inOne-1) / inOne < k)
        {
            added++;
            cout << added << ' ';
        }

        for (int start = inOne + added; start - inOne - added <= n; start += inOne)
        {
            for (int i = 0; i < inOne; i++)
            {
                if (start - i <= n)
                    cout << start - i << ' ';
            }
        }
        cout << '\n';
    }
}