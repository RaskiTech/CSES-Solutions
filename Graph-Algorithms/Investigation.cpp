#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9+7;

struct Elem {
    int weight;
    int node;

    bool operator>(const Elem& other) const {
        return weight > other.weight;
    }
};
struct Ans {
    int weight = LLONG_MAX/2;
    int count = 0;
    int minC = LLONG_MAX/2;
    int maxC = 0;
};

signed main() {
    priority_queue<Elem, vector<Elem>, greater<Elem>> elements;

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        adj[a].push_back({b, c});
    }

    vector<Ans> ans(n, Ans{});
    ans[0] = {0, 1, 0, 0};

    elements.push({0, 0});

    while (!elements.empty()) {
        auto [weight, node] = elements.top();
        elements.pop();
        if (weight > ans[node].weight)
            continue;

        for (auto [neigh, edge] : adj[node]) {
            if (edge + weight < ans[neigh].weight)
            {
                ans[neigh].weight = edge + weight;
                ans[neigh].count = ans[node].count;
                ans[neigh].maxC = ans[node].maxC + 1;
                ans[neigh].minC = ans[node].minC + 1;
                elements.push({edge + weight, neigh});
            }
            else if (edge + weight == ans[neigh].weight)
            {
                ans[neigh].count += ans[node].count;
                ans[neigh].count %= mod;
                ans[neigh].maxC = max(ans[neigh].maxC, ans[node].maxC + 1);
                ans[neigh].minC = min(ans[neigh].minC, ans[node].minC + 1);
            }
        }
    }

    cout << ans.back().weight << " " << ans.back().count << " " << ans.back().minC << " " << ans.back().maxC;
}