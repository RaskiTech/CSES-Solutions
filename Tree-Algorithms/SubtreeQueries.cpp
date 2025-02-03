#include <bits/stdc++.h>
#define int long long
using namespace std;

class STree {
public:
    vector<int> data;
    int offset;
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

int recurse(vector<vector<int>>& adj, int node, int parent, int nextGraphIdx, vector<int>& graphIdxToVecIdx, 
    vector<int>& sizes)
{
    graphIdxToVecIdx[node] = nextGraphIdx;
    nextGraphIdx++;

    for (int neigh : adj[node])
    {
        if (neigh == parent)
            continue;
        
        nextGraphIdx = recurse(adj, neigh, node, nextGraphIdx, graphIdxToVecIdx, sizes);
    }

    sizes[node] = nextGraphIdx - graphIdxToVecIdx[node];
    return nextGraphIdx;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> graphVec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> graphVec[i];
    }

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> graphIdxToVecIdx(n, -1);
    vector<int> sizes(n, -1);
    recurse(adj, 0, -1, 0, graphIdxToVecIdx, sizes);

    vector<int> treeVec(n); 
    for (int i = 0; i < n; i++)
        treeVec[graphIdxToVecIdx[i]] = graphVec[i];
    
    STree tree = STree(n, treeVec);

    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int s, x;
            cin >> s >> x;
            s--;
            tree.Set(graphIdxToVecIdx[s], x);
        }
        else
        {
            int s;
            cin >> s;
            s--;
            cout << tree.Range(graphIdxToVecIdx[s], graphIdxToVecIdx[s] + sizes[s] - 1) << '\n';
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}