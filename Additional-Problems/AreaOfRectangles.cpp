#include <bits/stdc++.h>
using namespace std;
#define int long long

class DynamicSTree {
public:
    vector<int> data;
    vector<pair<int, int>> mins;
    vector<int> sizes;
    int offset;
    DynamicSTree(int size) {
        offset = 1;
        while (offset < size) offset <<= 1;
        data = vector<int>(2*offset, 0);
        mins = vector<pair<int, int>>(2*offset, {0, 0});

        sizes = vector<int>(2*offset);
        for (int i = offset; i < sizes.size(); i++)
        {
            mins[i] = {1, 0};
            sizes[i] = 1;
        }
        for (int i = offset-1; i > 0; i--)
        {
            mins[i] = {mins[2*i].first + mins[2*i+1].first, 0};
            sizes[i] = sizes[2*i] + sizes[2*i+1];
        }
    }

    void UpdateMins(int offsetIdx)
    {
        if (mins[2*offsetIdx].second == mins[2*offsetIdx+1].second)
        {
            mins[offsetIdx] = {mins[2*offsetIdx].first + mins[2*offsetIdx+1].first, mins[2*offsetIdx].second};
            return;
        }
        
        auto& p1 = mins[2*offsetIdx];
        auto& p2 = mins[2*offsetIdx+1];
        if (p1.second < p2.second)
            mins[offsetIdx] = p1;
        else
            mins[offsetIdx] = p2;
    }

    void Add(int lInc, int rInc, int value, int offsetIdx = 1)
    {
        if (lInc >= sizes[offsetIdx] || rInc < 0)
            return;
        if (lInc <= 0 && rInc >= sizes[offsetIdx]-1)
        {
            data[offsetIdx] = data[offsetIdx] + value;
            mins[offsetIdx].second += value;
            return;
        }

        PropagateNode(offsetIdx);
        Add(lInc, min(rInc, sizes[2*offsetIdx]), value, 2*offsetIdx);
        Add(max<int>(lInc - sizes[2*offsetIdx], 0), rInc - sizes[2*offsetIdx], value, 2*offsetIdx+1);
        data[offsetIdx] = 0;
        UpdateMins(offsetIdx);
    }
    void PropagateNode(int offsetIdx)
    {
        int value = data[offsetIdx];
        if (value == 0 || offsetIdx >= offset)
            return;
        data[2*offsetIdx] = data[2*offsetIdx] + value;
        data[2*offsetIdx+1] = data[2*offsetIdx+1] + value;
        data[offsetIdx] = 0;
        mins[2*offsetIdx].second += value;
        mins[2*offsetIdx+1].second += value;
    }
    pair<int, int> FullRange() { return Range(0, offset); }
    pair<int, int> Range(int lInc, int rInc, int offsetIdx = 1)
    {
        PropagateNode(offsetIdx);
        if (lInc <= 0 && rInc >= sizes[offsetIdx]-1)
            return mins[offsetIdx];

        pair<int, int> result = {INT_MAX, INT_MAX};
        if (lInc < sizes[2*offsetIdx]) result = Range(lInc, min(rInc, sizes[2*offsetIdx]), 2*offsetIdx);
        if (rInc >= sizes[2*offsetIdx]) {
            auto cand = Range(max<int>(0, lInc - sizes[2*offsetIdx]), rInc - sizes[2*offsetIdx], 2*offsetIdx+1);
            if (cand.second == result.second)
                result.first += cand.first;
            else if (cand.second < result.second)
                result = cand;
        }
        return result;
    }
};

const int COORD_MAX = 2e6+2;

void solve() {

    int n;
    cin >> n;

    vector<tuple<int, int, int, int>> events;
    events.reserve(2*n);
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y2--;

        events.push_back({x1, y1+COORD_MAX/2, y2+COORD_MAX/2, 1});
        events.push_back({x2, y1+COORD_MAX/2, y2+COORD_MAX/2, -1});
    }
    sort(events.begin(), events.end());

    DynamicSTree tree(2e6+1);
    int prev = -1e6-1;
    int result = 0;
    for (int i = 0; i < events.size(); i++)
    {
        auto [pos, low, high, delta] = events[i];
        int squares = tree.offset - (tree.FullRange().second == 0 ? tree.FullRange().first : 0);
        result += squares * (pos - prev);
        tree.Add(low, high, delta);
        prev = pos;
    }

    cout << result;
}
 
signed main() {
    solve();
}