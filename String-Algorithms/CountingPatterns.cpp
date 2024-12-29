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

void solve() {
    string s;
    cin >> s;
    s += '{';
    vector<int> sufArr(s.size());
    buildSuffixArray(s, sufArr);

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

        cout << r - l + 1 << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}