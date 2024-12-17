#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <climits>
#include <cmath>
#include <functional>
#include <type_traits>
#include <fstream>
#include <bitset>
#include <complex>
#include <iomanip>
 
#define int long long
using namespace std;
 
int mod = 1e9+7;
 
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


 
void solve()
{
    int n, q;
    cin >> n >> q;
 
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++)
        cin >> nums[i];
    unordered_map<int, int> seen;

    vector<int> v;
    STree tree = STree(n, v);

    vector<pair<pair<int, int>, int>> ques(q);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;b--;
        ques[i] = {{b, a}, i};
    }
    sort(ques.begin(), ques.end());

    vector<int> res(q, 0);


    int qIdx = 0;
    for (int i = 0; i < n; i++)
    {
        if (seen.find(nums[i]) != seen.end())
            tree.Set(seen[nums[i]], 0);
        seen[nums[i]] = i;
        tree.Set(i, 1);

        while (qIdx < ques.size() && ques[qIdx].first.first == i) {
            res[ques[qIdx].second] = tree.Range(ques[qIdx].first.second, ques[qIdx].first.first);
            qIdx++;
        }
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\n';
 
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(15);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        solve();
        cout.flush();
    }
}