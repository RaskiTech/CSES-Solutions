#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // gcc only
 
#define int long long
using namespace std;
 
signed main() {
 
    cin.tie(0);
    ios_base::sync_with_stdio(false);
 
    int n, q;
    cin >> n >> q;
 
    vector<vector<int>> parents(31, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> parents[0][i];
        parents[0][i]--;
    }
 
    for (int i = 1; i < parents.size(); i++)
    {
        for (int j = 0; j < parents[i].size(); j++)
        {
            parents[i][j] = parents[i-1][parents[i-1][j]];
        }
    }
 
    for (int i = 0; i < q; i++)
    {
        int node, k;
        cin >> node >> k;
        node--;
 
        for (int h = 30; h >= 0; h--)
        {
            if (k >= (1 << h))
            {
                node = parents[h][node];
                k -= (1 << h);
            }
 
        }
        cout << node+1 << '\n';
    }
}