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
    
    tree[index] += newVal; // For adding
    //tree[index] = newVal; // For setting value
 
    for (index /= 2; index >= 1; index /= 2) {
        tree[index] = tree[2*index]+tree[2*index+1]; // Sum tree
        //tree[index] = min(tree[2*index], tree[2*index+1]); // Min tree
    }
}
 
// Create segment tree
vector<int> ST_Create(int valueCount) {
    int res = 1;
    while (res < valueCount) res <<= 1;
    vector<int> tree(2 * res, 0);
 
    // start from the end, from the second last element -> -2
    for (int i = res * 2 - 2; i > 0; i -= 2) {
        //tree[i/2] = min(tree[i], tree[i + 1]); // Min tree
        tree[i/2] = tree[i] + tree[i + 1]; // Sum tree
    }
    return tree;
}
 
 
#define cross(x, y) (((x)*conj(y)).imag())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
void solve()
{
    int n;
    cin >> n;
 
    vector<int> segment_tree = ST_Create(1000001*2);
 
    vector<tuple<int, int, int>> events;
    events.reserve(2*n);
 
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 == y2)
        {
            events.push_back({x1, INT_MAX, y1});
            events.push_back({x2, INT_MIN, y1});
        }
        else
        {
            if (y1 > y2)
                swap(y1, y2);
            events.push_back({x1, y1, y2});
        }
    }
    sort(events.begin(), events.end());
 
    int res = 0;
    for (int i = 0; i < events.size(); i++)
    {
        auto [p1, p2, p3] = events[i];
        if (p2 == INT_MAX)
            ST_Set(segment_tree, p3+1000001, 1);
        else if (p2 == INT_MIN)
            ST_Set(segment_tree, p3+1000001, -1);
        else
        {
            res += ST_GetRange(segment_tree, p2+1000001, p3+1000001);
        }
    }
 
    cout << res;
 
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