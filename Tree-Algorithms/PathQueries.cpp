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

        data[offset] = startVals[0];
        for (int i = 1; i < startVals.size(); i++)
        {
            data[offset+i] = startVals[i] - startVals[i-1];
        }
        
        for (int i = offset-1; i > 0; i--)
        {
            data[i] = data[2*i] + data[2*i+1];
        }
    }

    void Handle(int idx, int val)
    {

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

int nextArrayIdx = 0;
int CreateArray(const vector<int>& values, vector<int>& parents, vector<int>& sizes, vector<int>& sumArray, vector<vector<int>>& adj, unordered_map<int, int>& nodeToIdx, int node, int sum)
{
    sum += values[node];
    nodeToIdx[node] = nextArrayIdx;
    sumArray[nextArrayIdx] = sum;
    nextArrayIdx++;

    int size = 1;
    for (int neighbor : adj[node])
    {
        if (parents[neighbor] == -1)
        {
            parents[neighbor] = node;
            size += CreateArray(values, parents, sizes, sumArray, adj, nodeToIdx, neighbor, sum);
        }
    }
    sizes[node] = size;
    return size;
}

// We create pre-order traversal array and put a difference array of that into a segment tree 

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> values(n);
    for (int i = 0; i < n; i++)
        cin >> values[i];

    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parents(n, -1);
    parents[0] = -100;
    vector<int> sums(n, -1);
    vector<int> sizes(n, -1);
    unordered_map<int, int> nodeToIdx;
    CreateArray(values, parents, sizes, sums, adj, nodeToIdx, 0, 0);

    STree tree = STree(n, sums);

    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int s, x;
            cin >> s >> x;
            s--;
            // Change s to x
            int vecIdx = nodeToIdx[s];

            int parentSub = (vecIdx == 0 ? 0 : tree.Range(0, nodeToIdx[parents[s]]));
            int nodeVal = tree.Range(0, vecIdx) - parentSub;
            int diff = x - nodeVal;
            tree.Add(vecIdx, diff);
            int endIdx = vecIdx+sizes[s];
            if (endIdx < tree.data.size())
                tree.Add(endIdx, -diff);
        }
        else
        {
            int s;
            cin >> s;
            s--;
            // Print s
            int vecIdx = nodeToIdx[s];
            int nodeVal = tree.Range(0, vecIdx);
            cout << nodeVal << '\n';
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}