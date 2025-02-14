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
    int x, n;
    cin >> x >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pq.push(a);
    }

    int cost = 0;
    while (true)
    {
        int val1 = pq.top();
        pq.pop();
        if (pq.empty())
            break;
        
        int val2 = pq.top();
        pq.pop();
        cost += val1 + val2;
        pq.push(val1 + val2);
    }
    cout << cost;
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