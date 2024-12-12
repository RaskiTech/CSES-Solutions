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
 
 
void solve()
{
    int n;
    cin >> n;
 
    vector<int> freq(n+1);
    vector<int> nums(n-2);
 
    for (int i = 0; i < n-2; i++)
    {
        cin >> nums[i];
        freq[nums[i]]++;
    }
 
    set<int> available;
    for (int i = 1; i < freq.size(); i++)
        if (freq[i] == 0)
            available.insert(i);
    
    for (int i = 0; i < n-2; i++)
    {
        int minNum = *available.begin();
        available.erase(minNum);
        cout << minNum << " " << nums[i] << '\n';
        freq[nums[i]]--;
        if (freq[nums[i]] == 0)
            available.insert(nums[i]);
    }
    // The last edge
    cout << (*available.begin()) << " " << *next(available.begin());
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