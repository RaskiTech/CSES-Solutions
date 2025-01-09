#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int GetNextLoweringNumber(vector<int>& array)
{
    int next = array.size();
    for (auto num = array.rbegin(); num != array.rend(); num++)
        if (*num == next)
            next--;
    return next;
}
long long GetInversionCount(vector<int>& array)
{
    Tree<int> nums;
    long long inversionCount = 0;
    for (int i = 0; i < array.size(); i++)
    {
        nums.insert(array[i]);
        inversionCount += nums.size() - nums.order_of_key(array[i]) - 1;
    }
    return inversionCount;
}
int GetLongestIncreasingSubsequenceLength(vector<int>& array)
{
    set<pair<int, int>> mem;
    mem.insert({array[0], 1});
    int maxCount = 1;
    for (int i = 1; i < array.size(); i++)
    {
        int num = array[i];
        auto it = mem.upper_bound({num, 0});
        int count = 1;
        if (it != mem.begin())
        {
            auto prev = it;
            prev--;
            count = (*prev).second + 1;
            maxCount = max(maxCount, count);
        }
        if (it != mem.end() && (*it).second == count)
        {
            mem.erase(it);
        }
        mem.insert({num, count});
    }
    return maxCount;
}
int FindCycleCount(vector<int>& array)
{
    vector<bool> visited(array.size(), false);
    function<void(int)> func = [&](int idx) {
        if (visited[idx]) return;
        visited[idx] = true;
        func(array[idx]-1);
    };
    int cycleCount = 0;
    for (int i = 0; i < array.size(); i++)
        if (!visited[i])
        {
            cycleCount++;
            func(i);
        }
    return cycleCount;
}

int main() {
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; i++)
        cin >> array[i];
    
    cout << GetInversionCount(array) << ' ' << n - FindCycleCount(array) << ' '
        << n - GetLongestIncreasingSubsequenceLength(array) << ' ' << GetNextLoweringNumber(array);
}