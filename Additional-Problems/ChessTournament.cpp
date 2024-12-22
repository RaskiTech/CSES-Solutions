#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;

    set<pair<int, int>, greater<pair<int, int>>> people;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        if (a != 0)
            people.insert(pair<int, int>{a, i+1});
    }

    vector<pair<int, int>> res;
    res.reserve(sum/2);

    vector<pair<int, int>> toDelete;
    toDelete.reserve(n);
    while (!people.empty())
    {
        auto [fCount, fPerson] = *people.begin();
        people.erase(people.begin());

        for (auto it = people.begin(); it != people.end() && fCount > 0; it++)
        {
            res.push_back({(*it).second, fPerson});
            toDelete.push_back(*it);
            fCount--;
        }

        for (int i = 0; i < toDelete.size(); i++)
        {
            people.erase(toDelete[i]);
            if (toDelete[i].first > 1)
                people.insert({toDelete[i].first-1, toDelete[i].second});
        }
        toDelete.clear();

        if (fCount > 0)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++)
        cout << res[i].first << " " << res[i].second << '\n';
}