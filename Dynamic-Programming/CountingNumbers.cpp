#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[20][10][2][2];
int calc(const string& s, int idx, int prevDigit, int zeros, int tight)
{
    if (idx == 0)
        return 1;
    if (dp[idx][prevDigit][zeros][tight] != -1)
        return dp[idx][prevDigit][zeros][tight];
    
    int limit = 9;
    if (tight != 0) {
        limit = s[s.size() - idx] - '0';
    }
    int count = 0;
    for (int digit = 0; digit <= limit; digit++)
    {
        if (!zeros && digit == prevDigit)
            continue;
        
        int newZeros = zeros && digit == 0;
        int newTight = digit == limit && tight;
        count += calc(s, idx-1, digit, newZeros, newTight);
    }
    return dp[idx][prevDigit][zeros][tight] = count;
}

signed main() {
    int aInt, bInt;
    cin >> aInt >> bInt;

    string a = to_string(aInt-1);
    string b = to_string(bInt);

    memset(dp, -1, sizeof(dp));
    int first = calc(b, b.size(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    int second = aInt == 0 ? 0 : calc(a, a.size(), -1, 1, 1);
    cout << first - second;
}