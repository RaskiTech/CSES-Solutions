#include <bits/stdc++.h>
#define int long long
using namespace std;

void buildSuffixArray(const string& s, vector<int>& res)
{
    int alphabet = 30;
    int n = s.size();
    vector<int> c(n), count(max<int>(alphabet, n), 0);
    for (int i = 0; i < n; i++) count[s[i]-'a']++;
    for (int i = 1; i < alphabet; i++) count[i] += count[i-1];
    for (int i = 0; i < n; i++) res[--count[s[i]-'a']] = i;

    c[res[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[res[i]] != s[res[i-1]]) 
            classes++;
            c[res[i]] = classes - 1;
    }
    vector<int> tRes(n), tC(n);
    for (int h = 0; (1 << h) < n; h++)
    {
        for (int i = 0; i < n; i++)
        {
            tRes[i] = res[i] - (1<<h);
            if (tRes[i] < 0) tRes[i] += n;
        }
        fill(count.begin(), count.begin()+classes, 0);
        for (int i = 0; i < n; i++) count[c[tRes[i]]]++;
        for (int i = 1; i < classes; i++) count[i] += count[i-1];
        for (int i = n-1; i >= 0; i--) res[--count[c[tRes[i]]]] = tRes[i];
        tC[res[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++)
        {
            if (c[res[i]] != c[res[i-1]] || c[(res[i]+(1<<h))%n] != c[(res[i-1]+(1<<h))%n])
                classes++;
            tC[res[i]] = classes-1;
        }
        swap(c, tC);
    }
}
void BuildLcp(const string& s, vector<int>& suffix, vector<int> outLcp)
{
    vector<int> inv(s.size());
    for (int i = 0; i < suffix.size(); i++) inv[suffix[i]] = i;
    int L = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int j = suffix[inv[i]-1];
        while (i+L < s.size() && j+L < s.size() && s[i+L] == s[j+L])
            L++;
        outLcp[inv[i]] = L;
        L = max<int>(L-1, 0);
    }
}
class STree {
public:
    vector<int> data;
    int offset;
    STree(int size, vector<int>& startVals)
    {
        offset = 1;
        while (size > offset) offset <<= 1;
        data = vector<int>(2*offset, INT_MAX);

        for (int i = 0; i < startVals.size(); i++)
            data[offset+i] = startVals[i];
        
        for (int i = offset-1; i > 0; i--)
            data[i] = min(data[2*i], data[2*i+1]);
    }

    void Add(int idx, int val) {Set(idx, data[offset+idx]+val);}
    void Set(int idx, int val) {
        idx += offset;
        data[idx] = val;
        idx /= 2;
        while (idx > 0)
        {
            data[idx] = min(data[2*idx], data[2*idx+1]);
            idx /= 2;
        }
    }
    int Range(int LInc, int RInc) {
        LInc += offset; RInc += offset;
        int sum = INT_MAX;
        while (LInc <= RInc)
        {
            if (LInc % 2 == 1) sum = min(sum, data[LInc++]);
            if (RInc % 2 == 0) sum = min(sum, data[RInc--]);
            LInc /= 2;
            RInc /= 2;
        }
        return sum;
    }
};

void solve() {
    string s;
    cin >> s;
    s += '{';
    vector<int> sufArr(s.size());
    buildSuffixArray(s, sufArr);

    STree tree = STree(sufArr.size(), sufArr);

    int q;
    cin >> q;
    string qStr;
    for (int i = 0; i < q; i++)
    {
        qStr.clear();
        cin >> qStr;

        int l = 0;
        int r = sufArr.size()-1;
        for (int i = 0; i < qStr.size(); i++)
        {
            int lHigh = r;
            while (l <= lHigh)
            {
                int mid = (l+lHigh)/2;
                if (s[(sufArr[mid]+i) % s.size()] < qStr[i])
                    l = mid+1;
                else
                    lHigh = mid-1;
            }
            int rLow = l;
            while (rLow <= r)
            {
                int mid = (r+rLow) / 2;
                if (s[(sufArr[mid]+i) % s.size()] > qStr[i])
                    r = mid-1;
                else
                    rLow = mid+1;
            }
        }

        if (r - l < 0)
            cout << -1 << '\n';
        else
            cout << tree.Range(l, r)+1 << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}