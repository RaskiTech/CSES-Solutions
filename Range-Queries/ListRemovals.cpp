#include <bits/stdc++.h>
using namespace std;
#define int long long

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

    int ConvertIndex(int val)
    {
        int i = 1;
        while (i < offset)
        {
            if (data[2*i] < val)
            {
                val -= data[2*i];
                i = 2*i+1;
            }
            else
            {
                i = 2*i;
            }
        }

        Set(i - offset, 0);
        return i - offset;
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
};
 
void solve() {
    
    int n;
    cin >> n;

    vector<int> orig(n, 1);
    STree tree = STree(n, orig);

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int idx = tree.ConvertIndex(a);
        cout << nums[idx] << ' ';
    }

}

signed main() {
    solve();
}