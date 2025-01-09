#include <bits/stdc++.h>
using namespace std;

array<vector<pair<int, int>>, 2> loops;
void CorrectLoop(vector<int>& arr, unordered_map<int, int>& numToIdx, int idx)
{
    int firstIndex = idx;
    if (arr[idx] == idx)
        return;
    
    int next = arr[idx];
    if (arr[next] == idx)
    {
        loops[0].push_back({idx, next});
        swap(arr[idx], arr[next]);
    }

    vector<int> secondSwitches;

    while (arr[arr[idx]] != idx)
    {
        secondSwitches.push_back(idx);
        int whereFrom = numToIdx[idx];
        int goingTo = arr[idx];
        loops[0].push_back({whereFrom, goingTo});
        swap(numToIdx[arr[whereFrom]], numToIdx[arr[goingTo]]);
        swap(arr[whereFrom], arr[goingTo]);
        idx = whereFrom;
    }
    if (idx != arr[idx])
        secondSwitches.push_back(idx);
    
    for (int other : secondSwitches)
    {
        loops[1].push_back({other, arr[other]});
        swap(arr[other], arr[arr[other]]);
    }
}

void Print(array<vector<pair<int, int>>, 2>& arr)
{
    if (loops[0].size() == 0)
        cout << 0 << '\n';
    else if (loops[1].size() == 0)
        cout << 1 << '\n';
    else
        cout << 2 << '\n';

    for (int i = 0; i < loops.size() && loops[i].size() != 0; i++)
    {
        cout << loops[i].size() << '\n';
        for (int j = 0; j < loops[i].size(); j++)
            cout << loops[i][j].first+1 << ' ' << loops[i][j].second+1 << '\n';
    }
}

signed main() 
{
    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_map<int, int> numToIdx;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        nums[i]--;
        numToIdx[nums[i]] = i;
    }

    loops[0] = vector<pair<int, int>>();
    loops[1] = vector<pair<int, int>>();

    for (int i = 0; i < nums.size(); i++)
        CorrectLoop(nums, numToIdx, i);
    
    Print(loops);
}