#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
int mod = 998244353;
 
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
            if (data[2*i] == 0)
                data[i] = data[2*i+1];
            else if (data[2*i+1] == 0)
                data[i] = data[2*i];
            else
                data[i] = __gcd(data[2*i], data[2*i+1]);
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
        int res = -1;
        while (LInc <= RInc)
        {
            if (LInc % 2 == 1) {
                if (res == -1)
                    res = data[LInc++];
                else
                {
                    if (res == 0)
                        res = data[LInc];
                    else if (data[LInc] != 0)
                        res = __gcd(res, data[LInc]);
                    LInc++;
                }
            }
            if (RInc % 2 == 0) {
                if (res == -1)
                    res = data[RInc--];
                else
                {
                    if (res == 0)
                        res = data[RInc];
                    else if (data[RInc] != 0)
                        res = __gcd(res, data[RInc]);
                    RInc--;
                }
            }
            LInc /= 2;
            RInc /= 2;
        }
        return res;
    }
};
 
 
void solve()
{
    int n, q;
    cin >> n >> q;
 
    vector<vector<int>> parents(30, vector<int>(n, 0));
    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        a--;
        parents[0][i] = a;
    }
 
    for (int i = 1; i < parents.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            parents[i][j] = parents[i-1][parents[i-1][j]];
        }
    }
 
    for (int i = 0; i < q; i++)
    {
        int x, k;
        cin >> x >> k;
        x--;
 
        for (int idx = parents.size()-1; idx >= 0; idx--)
        {
            int lift = 1 << idx;
            if (k > lift)
            {
                x = parents[idx][x];
                k -= lift;
            }
        }
        if (x == 0)
            cout << -1 << endl;
        else
            cout << parents[0][x]+1 << endl;
    }
    
 
} 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    //std::ifstream file("testcase.txt"); std::cin.rdbuf(file.rdbuf());
 
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}