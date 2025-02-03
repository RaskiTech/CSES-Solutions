#include <bits/stdc++.h>
#define int long long
using namespace std;

const int bitsPerNum = 30;

int nextAlloc = 1;
struct Node {
    int left = -1;
    int right = -1;
    int leafNum = -1;
    void init() {
        left = -1;
        right = -1;
        leafNum = -1;
    }
};

vector<Node> nodes;

void InsertNum(int num)
{
    int node = 0;
    for (int i = bitsPerNum; i >= 0; i--)
    {
        if (num & (1 << i))
        {
            if (nodes[node].right == -1)
            {
                nodes[node].right = nextAlloc;
                nodes[nextAlloc].init();
                nextAlloc++;
            }
            node = nodes[node].right;
        }
        else
        {
            if (nodes[node].left == -1)
            {
                nodes[node].left = nextAlloc;
                nodes[nextAlloc].init();
                nextAlloc++;
            }
            node = nodes[node].left;
        }
    }
    nodes[node].leafNum = num;
}
int FindOptimalFor(int num)
{
    int node = 0;
    for (int i = bitsPerNum; i >= 0; i--)
    {
        if (nodes[node].left == -1 && nodes[node].right == -1)
            break;

        if (num & (1 << i))
            node = nodes[node].left == -1 ? nodes[node].right : nodes[node].left;
        else
            node = nodes[node].right == -1 ? nodes[node].left : nodes[node].right;
    }
    return nodes[node].leafNum;
}

void solve()
{
    int n;
    cin >> n;

    nodes = vector<Node>(n*bitsPerNum+3);

    int prefix = 0;
    int maxRes = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        InsertNum(prefix);
        prefix ^= num;
        maxRes = max(maxRes, prefix ^ FindOptimalFor(prefix));
    }
    cout << maxRes;

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