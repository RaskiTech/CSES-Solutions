#include <bits/stdc++.h>
#define int long long
using namespace std;

class DynamicSTree {
public:
    vector<pair<int, int>> data;
    vector<int> sizes;
    int offset;
    DynamicSTree(int size, vector<int>& start) {
        offset = 1;
        while (offset < size) offset <<= 1;
        data = vector<pair<int, int>>(2*offset, {0, 0});
        for (int i = 0; i < min<int>(size, start.size()); i++)
            data[offset+i].first = start[i];

        sizes = vector<int>(2*offset);
        for (int i = offset; i < sizes.size(); i++)
            sizes[i] = 1;
        for (int i = offset-1; i > 0; i--)
        {
            sizes[i] = sizes[2*i] + sizes[2*i+1];
            data[i] = max(data[2*i], data[2*i+1]);
        }
    }

    void Add(int lInc, int rInc, int value, int offsetIdx = 1)
    {
        if (lInc >= sizes[offsetIdx] || rInc < 0)
            return;
        if (lInc <= 0 && rInc >= sizes[offsetIdx]-1)
        {
            data[offsetIdx] = {data[offsetIdx].first + value, data[offsetIdx].second + value};
            return;
        }

        PropagateNode(offsetIdx);
        Add(lInc, min(rInc, sizes[2*offsetIdx]), value, 2*offsetIdx);
        Add(max<int>(lInc - sizes[2*offsetIdx], 0), rInc - sizes[2*offsetIdx], value, 2*offsetIdx+1);
        data[offsetIdx] = {max(data[2*offsetIdx].first, data[2*offsetIdx+1].first), 0};
    }
    void PropagateNode(int offsetIdx)
    {
        int value = data[offsetIdx].second;
        if (value == 0 || offsetIdx >= offset)
            return;
        data[2*offsetIdx] = {data[2*offsetIdx].first + value, data[2*offsetIdx].second + value};
        data[2*offsetIdx+1] = {data[2*offsetIdx+1].first + value, data[2*offsetIdx+1].second + value};
        data[offsetIdx].second = 0;
    }
    int Range(int lInc, int rInc, int offsetIdx = 1)
    {
        PropagateNode(offsetIdx);
        if (lInc <= 0 && rInc >= sizes[offsetIdx]-1)
            return data[offsetIdx].first;

        int sum = LLONG_MIN/2;
        if (lInc < sizes[2*offsetIdx]) sum = max(sum, Range(lInc, min(rInc, sizes[2*offsetIdx]), 2*offsetIdx));
        if (rInc >= sizes[2*offsetIdx]) sum = max(sum, Range(max<int>(0, lInc - sizes[2*offsetIdx]), rInc - sizes[2*offsetIdx], 2*offsetIdx+1));
        return sum;
    }
};


void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> vals(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        vals[i] = sum;
    }

    DynamicSTree tree = DynamicSTree(n, vals);
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            b--;
            int realVal = tree.Range(b, b) - (b == 0 ? 0 : tree.Range(b-1, b-1));
            int diff = c - realVal;
            tree.Add(b, n-1, diff);
        }
        else
        {
            b--;c--;
            int sub = b == 0 ? 0 : tree.Range(b-1, b-1);
            int maxPref = tree.Range(b, c);
            cout << max<int>(0, maxPref - sub) << '\n';
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}