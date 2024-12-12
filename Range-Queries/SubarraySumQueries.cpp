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
#define F first
#define S second
 
int mod = 1e9+7;
 
vector<int> lengths;
 
struct Node
{
    int m = 0;
    int l = 0;
    int r = 0;
    int full = 0;
};
 
int ST_GetRange(vector<Node> &tree, int lowerInclusive, int upperInclusive) {
    lowerInclusive += tree.size() / 2; upperInclusive += tree.size() / 2;
    int s = LLONG_MAX / 2; // 0 for SumTree and INT_MAX for MinTree
    while (lowerInclusive <= upperInclusive) {
        // Sum tree
        //if (lowerInclusive%2 == 1) s += tree[lowerInclusive++];
        //if (upperInclusive%2 == 0) s += tree[upperInclusive--];
        // Min tree
        //if (lowerInclusive%2 == 1) s = min(tree[lowerInclusive++], s);
        //if (upperInclusive%2 == 0) s = min(tree[upperInclusive--], s);
 
        lowerInclusive /= 2; upperInclusive /= 2;
    }
    return s;
}
 
 
void Update(vector<Node>& tree, int i)
{
    tree[i].full = tree[2*i].full + tree[2*i+1].full;
    tree[i].l = max(tree[2*i].l, tree[2*i].full + tree[2*i+1].l);
    tree[i].r = max(tree[2*i+1].r, tree[2*i+1].full + tree[2*i].r);
 
    tree[i].m = 0;
    tree[i].m = max(tree[i].m, tree[2*i].m);
    tree[i].m = max(tree[i].m, tree[2*i+1].m);
    tree[i].m = max(tree[i].m, tree[i].l);
    tree[i].m = max(tree[i].m, tree[i].r);
    tree[i].m = max(tree[i].m, tree[2*i].r + tree[2*i+1].l);
}
void ST_Set(vector<Node> &tree, int index, int newVal) {
    index += tree.size() / 2;
    
    //tree[index] += newVal; // For adding
    int v = max<int>(0, newVal);
    tree[index] = {v, v, v, newVal}; // For setting value
 
    for (index /= 2; index >= 1; index /= 2) {
        Update(tree, index);
    }
}
 
// Create segment tree
vector<Node> ST_Create(vector<int> &input, int valueCount) {
    int res = 1;
    while (res < valueCount) res <<= 1;
    vector<Node> tree(2 * res, {0, 0, 0, 0});
    lengths = vector<int>(2*res, 1);
 
    // Add input to the end
    for (int i = 0; i < input.size(); i++) {
        int v = max<int>(0, input[i]);
        tree[res + i] = {v, v, v, input[i]};
    }
 
    // start from the end, from the second last element -> -2
    for (int i = res-1; i > 0; i--) {
        lengths[i] = lengths[2*i]+1;
        Update(tree, i);
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
 
    vector<Node> segment_tree = ST_Create(nums, nums.size());
 
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        ST_Set(segment_tree, a-1, b);
        cout << segment_tree[1].m << '\n';
 
        //for (int i = 0; i < segment_tree.size(); i++)
        //    cout << segment_tree[i].full << '-' << segment_tree[i].m << '-' << segment_tree[i].l << '-' << segment_tree[i].r << ' ';
        //cout << endl;
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