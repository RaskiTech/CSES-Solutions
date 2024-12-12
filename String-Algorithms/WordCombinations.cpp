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
#include <bitset>
#include <fstream>
 
#define int long long
using namespace std;
 
constexpr int mod = 1e9+7;
constexpr int nodes = 1e6+2;
 
void solve() {
 
    vector<array<int, 26>> trie(nodes);
    for (int i = 0; i < trie[0].size(); i++)
        trie[0][i] = -1;
    array<bool, nodes> isEnd;
    for (int i = 0; i < nodes; i++)
        isEnd[i] = false;
    /*
    for (int i = 0; i < trie.size(); i++)
        for (int j = 0; j < trie[i].size(); j++)
            trie[i][j] = -1;
    */
    int nextNew = 1;
 
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string a;
        cin >> a;
 
        int curr = 0;
        int aIdx = 0;
        while (aIdx < a.size())
        {
            if (trie[curr][a[aIdx] - 'a'] == -1)
            {
                trie[curr][a[aIdx] - 'a'] = nextNew;
                for (int i = 0; i < trie[nextNew].size(); i++)
                    trie[nextNew][i] = -1;
                nextNew++;
            }
            curr = trie[curr][a[aIdx]-'a'];
            aIdx++;
        }
        //cout << "Setting " << curr << " to end" << endl;
        isEnd[curr] = true;
    }
    
    vector<int> dp(s.size()+1);
    dp[0] = 1;
    for (int i = 0; i < dp.size(); i++)
    {
        int curr = 0;
        for (int j = i; j < s.size(); j++)
        {
            curr = trie[curr][s[j]-'a'];
            if (curr == -1)
                break;
            if (isEnd[curr])
            {
                //cout << "Adding " << i << " to " << j+1 << endl;
                dp[j+1] = (dp[j+1] + dp[i]) % mod;
            }
        }
        dp[i] = dp[i] % mod;
    }
    cout << dp.back();
}
 
signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--) { solve(); }
}