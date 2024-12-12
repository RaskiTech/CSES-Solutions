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
 
#define cross(x, y) (((x)*conj(y)).imag())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
int mod = 1e9+7;
 
int ST_GetRange(vector<int> &tree, int lowerInclusive, int upperInclusive) {
    lowerInclusive += tree.size() / 2; upperInclusive += tree.size() / 2;
    int s = 0; // 0 for SumTree and INT_MAX for MinTree
    while (lowerInclusive <= upperInclusive) {
        // Sum tree
        if (lowerInclusive%2 == 1) s += tree[lowerInclusive++];
        if (upperInclusive%2 == 0) s += tree[upperInclusive--];
        // Min tree
        //if (lowerInclusive%2 == 1) s = min(tree[lowerInclusive++], s);
        //if (upperInclusive%2 == 0) s = min(tree[upperInclusive--], s);
 
        lowerInclusive /= 2; upperInclusive /= 2;
    }
    return s;
}
 
void ST_Set(vector<int> &tree, int index, int newVal) {
    index += tree.size() / 2;
    
    //tree[index] += newVal; // For adding
    tree[index] = newVal; // For setting value
 
    for (index /= 2; index >= 1; index /= 2) {
        tree[index] = tree[2*index]+tree[2*index+1]; // Sum tree
        //tree[index] = min(tree[2*index], tree[2*index+1]); // Min tree
    }
}
 
// Create segment tree
vector<int> ST_Create(vector<int> &input, int valueCount) {
    int res = 1;
    while (res < valueCount) res <<= 1;
    vector<int> tree(2 * res, LLONG_MAX / 2);
 
    // Add input to the end
    for (int i = 0; i < input.size(); i++) {
        tree[res + i] = input[i];
    }
 
    // start from the end, from the second last element -> -2
    for (int i = res * 2 - 2; i > 0; i -= 2) {
        //tree[i/2] = min(tree[i], tree[i + 1]); // Min tree
        tree[i/2] = tree[i] + tree[i + 1]; // Sum tree
    }
    return tree;
}
 
 
void solve()
{
    int n, q;
    cin >> n >> q;
 
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++)
        cin >> nums[i];
 
    vector<int> segment_tree = ST_Create(nums, nums.size());
 
    for (int i = 0; i < q; i++)
    {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 1)
        {
            ST_Set(segment_tree, a-1, b);
        }
        else
        {
            cout << ST_GetRange(segment_tree, a-1, b-1) << '\n';
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
        cout.flush();
    }
}