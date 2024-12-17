#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> links;
vector<int> siz;

int find(int x) {
    while (x != links[x]) x = links[x];
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (siz[a] < siz[b]) swap(a,b);
    siz[a] += siz[b];
    links[b] = a;
}
signed main() {
    int n, m;
    cin >> n >> m;

    links = vector<int>(n);
    siz = vector<int>(n+1, 1);
    for (int i = 0; i < n; i++) links[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        unite(a, b);
    }

    int one = find(0);
    unordered_set<int> connected;
    connected.insert(one);
    vector<int> res;
    for (int i = 1; i < n; i++)
    {
        int c = find(i);
        if (connected.find(c) == connected.end())
        {
            res.push_back(c);
            connected.insert(c);
        }
    }

    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++)
        cout << one+1 << ' ' << res[i]+1 << '\n';

}