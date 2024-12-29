#include <bits/stdc++.h>
using namespace std;
#define int long long
 
class MinSTree {
public:
    vector<pair<int, int>> data;
    int offset;
    MinSTree() {};
    MinSTree(int size, const vector<int>& startVals)
    {
        offset = 1;
        while (size > offset) offset <<= 1;
        data = vector<pair<int, int>>(2*offset, {INT_MAX, -1});
 
        for (int i = 0; i < startVals.size(); i++)
            data[offset+i] = {startVals[i], i};
        
        for (int i = offset-1; i > 0; i--)
        {
            data[i] = min(data[2*i], data[2*i+1]);
        }
    }
 
    void Add(int idx, int val) {Set(idx, data[offset+idx].first+val);}
    void Set(int idx, int val) {
        idx += offset;
        data[idx].first = val;
        idx /= 2;
        while (idx > 0)
        {
            data[idx] = min(data[2*idx], data[2*idx+1]);
            idx /= 2;
        }
    }
    pair<int, int> Range(int LInc, int RInc) {
        LInc += offset; RInc += offset;
        pair<int, int> minElem = {INT_MAX, -1};
        while (LInc <= RInc)
        {
            if (LInc % 2 == 1) minElem = min(minElem, data[LInc++]);
            if (RInc % 2 == 0) minElem = min(minElem, data[RInc--]);
            LInc /= 2;
            RInc /= 2;
        }
        return minElem;
    }
};
class STree {
public:
    vector<int> data;
    int offset;
    STree() {};
    STree(int size, vector<int>& startVals)
    {
        offset = 1;
        while (size > offset) offset <<= 1;
        data = vector<int>(2*offset, 0);
 
        for (int i = 0; i < startVals.size(); i++)
            data[offset+i] = startVals[i];
        
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
class FlippedSTree {
public:
    STree tree;
    FlippedSTree(int size, vector<int>& startVals)
    {
        vector<int> diffArr(startVals.size());
        if (startVals.size() > 0)
            diffArr[0] = startVals[0];
        for (int i = 1; i < startVals.size(); i++)
        {
            diffArr[i] = startVals[i] - startVals[i-1];
        }
        tree = STree(size, diffArr);
    }
    int Query(int pos) { return tree.Range(0, pos); }
    void Add(int lInc, int rInc, int val) {
        tree.Add(lInc, val);
        if (rInc < tree.offset-1)
            tree.Add(rInc+1, -val);
    }
};
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> vals(n);
    for (int i = 0; i < vals.size(); i++)
        cin >> vals[i];
    
    MinSTree minTree = MinSTree(n, vals);
    vector<int> empty;
    FlippedSTree sumTree = FlippedSTree(n, empty);
 
    int l = 0;
    int r = n-1;
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        auto [minVal, minIdx] = minTree.Range(0, n-1);
        minTree.Set(minIdx, INT_MAX);
 
        int realIdx = minIdx + sumTree.Query(minIdx);
        if (realIdx - l < r - realIdx)
        {
            cost += realIdx - l;
            sumTree.Add(0, minIdx, 1);
            l++;
        }
        else
        {
            cost += r - realIdx;
            sumTree.Add(minIdx, n-1, -1);
            r--;
        }
    }
 
    cout << cost;
}
 
signed main() {
    solve();
}