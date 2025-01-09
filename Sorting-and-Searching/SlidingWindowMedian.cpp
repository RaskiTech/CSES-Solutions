#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    multiset<int, greater<int>> smaller;
    multiset<int> bigger;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < k; i++)
        smaller.insert(nums[i]);
    for (int i = 0; i < k/2; i++)
    {
        bigger.insert(*smaller.begin());
        smaller.extract(smaller.begin()); 
    }

    bool shouldBeOneBigger = smaller.size() > bigger.size();
    cout << *smaller.begin() << ' ';
    for (int i = 0; i < n-k; i++)
    {
        int addedIdx = i+k;
        if (nums[i] <= *smaller.begin())
            smaller.extract(nums[i]);
        else
            bigger.extract(nums[i]);
        
        smaller.insert(nums[addedIdx]);
        while (*bigger.begin() < *smaller.begin() || smaller.size() > bigger.size()+shouldBeOneBigger)
        {
            bigger.insert(*smaller.begin());
            smaller.extract(*smaller.begin());
        }
        if (smaller.size() < bigger.size()+shouldBeOneBigger)
        {
            smaller.insert(*bigger.begin());
            bigger.extract(*bigger.begin());
        }

        cout << *smaller.begin() << ' ';
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}