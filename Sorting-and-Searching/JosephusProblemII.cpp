#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <functional>
#include <type_traits>
#include <fstream>
#include <bitset>
#include <complex>
 
#define int long long
using namespace std;
 
#define cross(x, y) (((x)*conj(y)).imag())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
struct STree
{
    vector<int> data;
    int offset;
    STree(int size, vector<int>& nums)
    {
        offset = 1;
        while (size > offset)
            offset <<= 1;
        data = vector<int>(offset*2);
 
        for (int i = 0; i < nums.size(); i++)
            data[i+offset] = nums[i];
        
        for (int i = offset-1; i > 0; i--)
            data[i] = data[2*i] + data[2*i+1];
    }
 
    void Add(int idx, int val) { Set(idx, data[offset+idx] + val); }
    void Set(int idx, int val)
    {
        idx += offset;
        data[idx] = val;
        idx /= 2;
        while (idx > 0)
        {
            data[idx] = data[2*idx]+ data[2*idx+1];
            idx /= 2;
        }
    }
    int Range(int lInc, int rInc) 
    {
        lInc += offset;
        rInc += offset;
        int sum = 0;
        while (lInc <= rInc)
        {
            if (lInc % 2 == 1) sum += data[lInc++];
            if (rInc % 2 == 0) sum += data[rInc--];
 
            lInc /= 2;
            rInc /= 2;
        }
        return sum;
    }
    void Traverse(int next)
    {
        int curr = 1;
        while (curr < offset)
        {
            if (data[2*curr] > next)
                curr *= 2;
            else
            {
                next -= data[2*curr];
                curr = curr * 2 + 1;
            }
        }
        int idx = curr - offset;
        Set(idx, 0);
        cout << (idx+1) << " ";
    }
};
 
void solve()
{
    int n, k;
    cin >> n >> k;
 
    vector<int> vec = vector<int>(n, 1);
 
    STree t = STree(n, vec);
    for (int i = t.offset; i < t.data.size(); i++)
        t.data[i] = 1;
 
    int next = 0;
    for (int i = n; i > 0; i--)
    {
        next = (next + k) % i;
        t.Traverse(next);
    }
 
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
    //ifstream f("testcase.txt");
    //cin.rdbuf(f.rdbuf());
 
    for (int i = 0; i < t; i++)
        solve();
}