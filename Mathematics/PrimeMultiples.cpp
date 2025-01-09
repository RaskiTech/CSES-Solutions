#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> nums;
int N;
int res = 0;
void IncExl(int idx, int mult, int sign)
{
    if (idx == nums.size())
    {
        if (mult == 1)
            return;
        res += sign * N / mult;
        return;
    }

    IncExl(idx+1, mult, sign);
    if ((__int128_t)mult * (__int128_t)nums[idx] <= N)
        IncExl(idx+1, mult * nums[idx], sign > 0 ? -1 : 1);
}

void solve()
{
    int k;
    cin >> N >> k;
    nums = vector<int>(k);
    for (int i = 0; i < k; i++)
        cin >> nums[i];
    IncExl(0, 1, -1);
    cout << res;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}