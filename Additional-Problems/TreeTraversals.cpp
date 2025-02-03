#include <bits/stdc++.h>
#define int long long
using namespace std;

void recurse(int l, int r, int inLeft, vector<int>& preOrd, vector<int>& inOrd, vector<int>& idxToInOrd)
{
    if (r < l)
        return;
    int num = preOrd[l];
    int idx = idxToInOrd[num];
    int leftCount = idx - inLeft;

    recurse(l+1, l+1 + leftCount-1, inLeft, preOrd, inOrd, idxToInOrd);
    recurse(l+1 + leftCount, r, idx+1, preOrd, inOrd, idxToInOrd);
    cout << num+1 << ' ';
}

void solve()
{
    int n;
    cin >> n;

    vector<int> preOrd(n);
    vector<int> inOrd(n);
    vector<int> idxToInOrd(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> preOrd[i];
        preOrd[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inOrd[i];
        inOrd[i]--;
        idxToInOrd[inOrd[i]] = i;
    }

    recurse(0, n-1, 0, preOrd, inOrd, idxToInOrd);
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}