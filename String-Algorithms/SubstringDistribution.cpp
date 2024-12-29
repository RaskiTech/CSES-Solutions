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
void BuildLcp(const string& s, vector<int>& suffix, vector<int>& outLcp)
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

void solve() {
    string s;
    cin >> s;
    s += '{';
    vector<int> sufArr(s.size());
    buildSuffixArray(s, sufArr);
    vector<int> lcp(s.size());
    BuildLcp(s, sufArr, lcp);

    vector<int> subs(s.size()+1, 0);
    for (int i = 1; i < lcp.size(); i++)
        subs[lcp[i]]++;
    for (int i = subs.size()-2; i >= 0; i--)
        subs[i] += subs[i+1];
    
    for (int i = 0; i < s.size()-1; i++)
    {
        int total = s.size()-i - 1;
        cout << total - subs[i+1] << ' ';
    }

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}