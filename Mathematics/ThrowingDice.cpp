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
#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp> // gcc only
template<typename T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
 
#define int long long
using namespace std;
 
int p(int base, int power, int mod)
{
    if (power == 0)
        return 1;
    if (power % 2 == 0)
    {
        int r = p(base, power/2, mod);
        return (r*r) % mod;
    }
    else
        return (p(base, power-1, mod)*base) % mod;
}
 
int LCM(int a, int b)
{
    return (a / __gcd(a, b)) * b;
}
 
int mod = 1e9+7;
 
void mP(vector<vector<int>>& inMat, vector<vector<int>>& temp, vector<vector<int>>& outMat, int power) {
    if (power == 1)
    {
        for (int i = 0; i < outMat.size(); i++)
            for (int j = 0; j < outMat[i].size(); j++)
                outMat[i][j] = inMat[i][j];
        return;
    }
    if (power % 2 == 0)
    {
        mP(inMat, temp, outMat, power / 2);
        swap(outMat, temp);
        for (int i = 0; i < outMat.size(); i++)
            for (int j = 0; j < outMat[i].size(); j++)
            {
                outMat[i][j] = 0;
                for (int idx = 0; idx < outMat.size(); idx++)
                {
                    outMat[i][j] += temp[i][idx] * temp[idx][j];
                    outMat[i][j] %= mod;
                }
            }
    }
    else
    {
        mP(inMat, temp, outMat, power-1);
        swap(outMat, temp);
        for (int i = 0; i < outMat.size(); i++)
            for (int j = 0; j < outMat[i].size(); j++)
            {
                outMat[i][j] = 0;
                for (int idx = 0; idx < outMat.size(); idx++)
                {
                    outMat[i][j] += temp[i][idx] * inMat[idx][j];
                    outMat[i][j] %= mod;
                }
            }
    }
}
 
void solve()
{
    int n;
    cin >> n;
 
    vector<int> init{1, 2, 4, 8, 16, 32};
 
    if (n == 1)
    {
        cout << init[n-1];
        return;
    }
 
    vector<vector<int>> mat(6, vector<int>(6, 0));
    for (int i = 1; i < mat.size(); i++)
        mat[i-1][i] = 1;
    for (int i = 0; i < mat.size(); i++)
        mat[mat.size()-1][i] = 1;
    
    
    vector<vector<int>> mat2(6, vector<int>(6, 0));
    vector<vector<int>> outMat(6, vector<int>(6, 0));
    
    mP(mat, mat2, outMat, n-1);
 
    for (int x = 0; x < 1; x++)
    {
        int res = 0;
        for (int i = 0; i < init.size(); i++)
        {
            res += outMat[x][i] * init[i];
            res %= mod;
        }
        cout << res << ' ';
    }
 
 
} 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        solve();
        //cout.flush();
    }
}