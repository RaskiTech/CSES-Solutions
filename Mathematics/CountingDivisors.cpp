#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<int, int> cache(10);
signed main() {
    int n;
    cin >> n;

    for (int t = 0; t < n; t++)
    {
        int x;
        cin >> x;
        int org = x;
        if (cache.find(x) != cache.end())
        {
            cout << cache[x] << '\n';
            continue;
        }


        int res = 1;
        for (int i = 2; i * i <= x; i++)
        {
            int c = 1;
            while (x % i == 0)
            {
                c++;
                x /= i;
            }
            res *= c;
        }
        if (x > 1)
            res *= 2;
        
        cache[org] = res;
        cout << (res) << '\n';
    }
}