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
 
#include <ext/pb_ds/assoc_container.hpp> // gcc only
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
#define int long long
using namespace std;
 
#define cross(x, y) (((x)*conj(y)).imag())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
 
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
 
    vector<int> arr(n);
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a - last;
        last = a;
    }
    STree tree = STree(n, arr);
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int b, c, d;
            cin >> b >> c >> d;
            b--;c--;
            tree.Add(b, d);
            if (c != n-1)
                tree.Add(c+1, -d);
        }
        else
        {
            int k;
            cin >> k;
            cout << tree.Range(0, k-1) << '\n';
        }
    }
 
 
 
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
        //cout.flush();
    }
}