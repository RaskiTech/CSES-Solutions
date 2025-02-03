#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> nums(n+2);
    vector<int> numToIdx(n+2, -1);
    numToIdx[0] = 0;
    nums[0] = 0;
    nums[n+1] = n+1;
    numToIdx[n+1] = n+1;
    int numOfRounds = 1;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        nums[i] = a;
        numToIdx[a] = i;
        if (numToIdx[a-1] == -1)
            numOfRounds++;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if (nums[a] > nums[b])
            swap(a, b);

        int iA = a;
        int iB = b;

        if (a == b)
        {
            cout << numOfRounds << '\n';
            continue;
        }
        if (nums[a] == nums[b]-1)
        {
            numOfRounds -= numToIdx[nums[a]-1] > iA;
            numOfRounds += numToIdx[nums[a]-1] > iB;
            numOfRounds -= numToIdx[nums[b]+1] < iB;
            numOfRounds += numToIdx[nums[b]+1] < iA;
            numOfRounds += iA < iB ? 1 : -1;
        }
        else
        {
            numOfRounds -= numToIdx[nums[a]-1] > iA;
            numOfRounds -= numToIdx[nums[a]+1] < iA;
            numOfRounds += numToIdx[nums[a]-1] > iB;
            numOfRounds += numToIdx[nums[a]+1] < iB;

            numOfRounds -= numToIdx[nums[b]-1] > iB;
            numOfRounds -= numToIdx[nums[b]+1] < iB;
            numOfRounds += numToIdx[nums[b]-1] > iA;
            numOfRounds += numToIdx[nums[b]+1] < iA;
        }

        swap(numToIdx[nums[a]], numToIdx[nums[b]]);
        swap(nums[a], nums[b]);
        
        cout << numOfRounds << '\n';
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}