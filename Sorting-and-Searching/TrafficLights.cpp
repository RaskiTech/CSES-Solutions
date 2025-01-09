#include <bits/stdc++.h>
#define int long long
using namespace std;

#define cross(x, y) (((x)*conj(y)).imag())

void solve()
{
    int x, n;
    cin >> x >> n;

    multiset<int, greater<int>> lens;
    lens.insert(x);
    set<int> lightPos;
    lightPos.insert(0);
    lightPos.insert(x);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        lightPos.insert(a);
        auto it = lightPos.lower_bound(a);
        it--;
        int len1 = a - *it;
        it++;it++;
        int len2 = *it - a;
        lens.extract(len1+len2);
        lens.insert(len1);
        lens.insert(len2);

        cout << *lens.begin() << ' ';
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}