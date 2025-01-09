#include <bits/stdc++.h>
#define int long long
using namespace std;

class UnionFind {
public:
    vector<int> data;
    vector<int> length;
    int count;
    UnionFind(int n) : data(vector<int>(n)), length(vector<int>(n, 1)), count(n) {
        for (int i = 0; i < data.size(); i++)
            data[i] = i;
    }
    int Find(int a) {
        while (a != data[a])
            a = data[a];
        return a;
    }
    bool Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a == b)
            return false;
        if (length[a] < length[b])
            swap(a, b);
        length[a] += length[b];
        data[b] = a;
        count--;
        return true;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);

    UnionFind uf = UnionFind(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;

        edges[i] = {c, a, b};
    }
    sort(edges.begin(), edges.end());

    int cost = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        auto [c, a, b] = edges[i];
        if (uf.Find(a) == uf.Find(b))
            continue;
        uf.Union(a, b);
        cost += c;
        if (uf.count == 1)
            break;
    }
    if (uf.count == 1)
        cout << cost;
    else
        cout << "IMPOSSIBLE";
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}