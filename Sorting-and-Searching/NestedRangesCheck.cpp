#include <bits/stdc++.h>
using namespace std;
#define int long long

class STree {
public:
    vector<int> data;
    int offset;
    STree(int size)
    {
        offset = 1;
        while (size > offset) offset <<= 1;
        data = vector<int>(2*offset, 0);

        for (int i = offset-1; i > 0; i--)
        {
            data[i] = data[2*i] + data[2*i+1];
        }
    }

    void Add(int idx, int val) {Set(idx, data[offset+idx]+val);}
    void Set(int idx, int val) {
        idx += offset;
        data[idx] = val;
        idx /= 2;
        while (idx > 0)
        {
            data[idx] = data[2*idx] + data[2*idx+1];
            idx /= 2;
        }
    }
    int Range(int LInc, int RInc) {
        LInc += offset; RInc += offset;
        int sum = 0;
        while (LInc <= RInc)
        {
            if (LInc % 2 == 1) sum += data[LInc++];
            if (RInc % 2 == 0) sum += data[RInc--];
            LInc /= 2;
            RInc /= 2;
        }
        return sum;
    }
};

signed main() {
    int n;
    cin >> n;

    vector<pair<int, int>> events;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        events.push_back({a, -i});
        events.push_back({b, i});
    }
    sort(events.begin(), events.end());

    // Index compression
    int lastReal = -1;
    int lastModified = -1;
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].first == lastReal)
        {
            events[i].first = lastModified;
        }
        else
        {
            lastReal = events[i].first;
            lastModified++;
            events[i].first = lastModified;
        }
    }

    STree tree = STree(lastModified+2);

    unordered_map<int, int> onGoing;

    vector<int> hadEnded(n+2, 0);
    vector<int> contains(n+2, 0);

    vector<int> needFlushing;
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].second < 0)
        {
            onGoing[abs(events[i].second)] = events[i].first;
            continue;
        }

        // Most of the complexity comes from handling ones that have same start or end position

        needFlushing.push_back(events[i].second);

        if (i < events.size()-1 && events[i+1].second > 0 && events[i+1].first == events[i].first)
            continue;
        
        for (int idx : needFlushing)
            hadEnded[idx] = tree.Range(0, onGoing[idx]);
        for (int idx : needFlushing)
            tree.Add(onGoing[idx], 1);
        for (int idx : needFlushing)
            contains[idx] = tree.Range(onGoing[idx], events[i].first) - 1;
        needFlushing.clear();
    }

    for (int i = 1; i <= n; i++)
        cout << min<int>(contains[i], 1) << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++)
        cout << min<int>(tree.Range(0, onGoing[i]) - hadEnded[i] - 1, 1) << ' ';
}