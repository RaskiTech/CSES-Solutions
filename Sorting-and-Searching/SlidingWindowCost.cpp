#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename Comp>
struct CountingSet {
    multiset<int, Comp> container;
    int sum = 0;
    void extract(int num) { container.extract(num); sum -= num; }
    void insert(int num) { container.insert(num); sum += num; }
    auto begin() { return container.begin(); }
    int size() { return container.size(); }
};

void solve()
{
    int n, k;
    cin >> n >> k;

    CountingSet<greater<int>> smaller;
    CountingSet<less<int>> bigger;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < k; i++)
    {
        smaller.insert(nums[i]);
    }
    for (int i = 0; i < k/2; i++)
    {
        bigger.insert(*smaller.begin());
        smaller.extract(*smaller.begin()); 
    }

    bool shouldBeOneBigger = smaller.size() > bigger.size();
    cout << (*smaller.begin() * smaller.size() - smaller.sum + bigger.sum - *smaller.begin() * bigger.size()) << ' ';

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

        cout << (*smaller.begin() * smaller.size() - smaller.sum + bigger.sum - *smaller.begin() * bigger.size()) << ' ';
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}