#include <bits/stdc++.h>
using namespace std;
#define int long long

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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    set<pair<int, int>> removeSet;
    vector<pair<int, int>> removeList(k);

    vector<pair<int, int>> connections(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        if (a > b)
            swap(a, b);
        connections[i] = {a, b};
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        if (a > b)
            swap(a, b);
        removeSet.insert({a, b});
        removeList[i] = {a, b};
    }

    UnionFind uf(n);
    for (auto& connection : connections)
        if (removeSet.find(connection) == removeSet.end())
            uf.Union(connection.first, connection.second);
    
    vector<int> ans(removeList.size());

    for (int i = removeList.size()-1; i >= 0; i--)
    {
        ans[i] = uf.count;
        uf.Union(removeList[i].first, removeList[i].second);
    }

    for (int a : ans)
        cout << a << ' ';
}


signed main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}