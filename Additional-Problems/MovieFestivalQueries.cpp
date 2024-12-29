#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    // Binary lifting on the movies

    int n, q;
    cin >> n >> q;

    vector<vector<int>> parents = vector<vector<int>>(30, vector<int>(n, -1));
    vector<pair<int, int>> movies(n);
    vector<pair<int, int>> sortedMovies(n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        movies[i] = {a, b};
        sortedMovies[i] = {b, i};
    }
    sort(sortedMovies.begin(), sortedMovies.end());

    multiset<pair<int, int>> movieEnds;
    for (int i = 0; i < sortedMovies.size(); i++) {
        auto [start, end] = movies[sortedMovies[i].second];
        auto it = movieEnds.upper_bound({start, INT_MAX});
        vector<pair<int, int>> clears;
        while (it != movieEnds.begin())
        {
            it--;
            parents[0][(*it).second] = sortedMovies[i].second;
            clears.push_back(*it);
        }
        for (auto& p : clears)
            movieEnds.erase(p);
        movieEnds.insert(sortedMovies[i]);
    }

    for (int i = 1; i < parents.size(); i++)
        for (int j = 0; j < parents[i].size(); j++)
            parents[i][j] = parents[i-1][j] == -1 ? -1 : parents[i-1][parents[i-1][j]];

    vector<int> results(q, -1);
    vector<tuple<int, int, int>> queries(q);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        queries[i] = {a, b, i};
    }
    sort(queries.begin(), queries.end());
    int qIdx = 0;
    for (int i = 0; i < sortedMovies.size(); i++)
    {
        int movieIdx = sortedMovies[i].second;
        while (qIdx < queries.size() && get<0>(queries[qIdx]) <= movies[movieIdx].first)
        {
            auto [qStart, qEnd, qArrIdx] = queries[qIdx];
            if (movies[movieIdx].second > qEnd)
            {
                results[qArrIdx] = 0;
                qIdx++;
                continue;
            }

            int count = 1;
            int nextMovie = movieIdx;
            for (int hop = parents.size()-1; hop >= 0; hop--)
            {
                if (parents[hop][nextMovie] == -1)
                    continue;
                if (movies[parents[hop][nextMovie]].second <= qEnd)
                {
                    count += 1 << hop;
                    nextMovie = parents[hop][nextMovie];
                }
            }
            results[qArrIdx] = count;
            qIdx++;
        }
    }
    for (int i = 0; i < results.size(); i++)
        cout << results[i] << '\n';
}

signed main()
{
    solve();
}