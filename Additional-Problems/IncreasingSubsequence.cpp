#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7;
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

    void Add(int idx, int val) {Set(idx, (data[offset+idx]+val) % mod);}
    void Set(int idx, int val) {
        idx += offset;
        data[idx] = val;
        idx /= 2;
        while (idx > 0)
        {
            data[idx] = data[2*idx] + data[2*idx+1];
            data[idx] %= mod;
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
            sum %= mod;
        }
        return sum;
    }
};

const int maxN = 2e6+1;
void solve() {
    int n;
    cin >> n;

    unordered_map<int, int> indexCompression;
    vector<int> nums(n);
    vector<int> sortedNums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sortedNums[i] = nums[i];
    }
    sort(sortedNums.begin(), sortedNums.end());
    indexCompression[sortedNums[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        if (sortedNums[i] > sortedNums[i-1])
            indexCompression[sortedNums[i]] = 1 + indexCompression[sortedNums[i-1]]; 
    }

    vector<int> _v;
    STree tree = STree(maxN, _v);

    int count = 0;
    for (int num : nums)
    {
        num = indexCompression[num];
        int sum = tree.Range(0, num-1) + 1;
        tree.Add(num, sum);
        count += sum;
        count %= mod;
    }
    cout << count;
}
 
signed main() {
    solve();
}