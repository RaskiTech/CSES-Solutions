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
            data[i] = max(data[2*i], data[2*i+1]);
        }
    }
 
    int Search(int val)
    {
        int p = 1;
 
        while (p < offset)
        {
            if (data[2*p] >= val)
                p = 2*p;
            else
                p = 2*p+1;
        }
        Add(p - offset, -val);
        return p - offset;
    }
 
    void Add(int idx, int val) {Set(idx, data[offset+idx]+val);}
    void Set(int idx, int val) {
        idx += offset;
        data[idx] = val;
        idx /= 2;
        while (idx > 0)
        {
            data[idx] = max(data[2*idx], data[2*idx+1]);
            idx /= 2;
        }
    }
};
 
 
 
void solve()
{
    int n, m;
    cin >> n >> m;
 
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }
 
    STree tree = STree(n, nums);
 
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
 
        if (tree.data[1] < a)
            cout << 0 << ' ';
        else
            cout << tree.Search(a)+1 << ' ';
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