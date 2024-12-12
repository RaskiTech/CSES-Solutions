#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cmath>
#include <functional>
 
#define int long long
using namespace std;
 
 
void solve() {
    int n;
    cin >> n;
 
    vector<int> parents(n);
    vector<vector<int>> childs(n, vector<int>());
    parents[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        parents[i] = p;
        childs[p].push_back(i);
    }
    
    vector<int> res(n);
    
    std::function<int(int)> count = [&res, &count, &childs](int node){
        int r = childs[node].size();
        for (int i = 0; i < childs[node].size(); i++)
            r += count(childs[node][i]);
        res[node] = r;
        return r;
    };
    count(0);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
 
}
 
 
signed main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
        solve();
 
    return 0;
}