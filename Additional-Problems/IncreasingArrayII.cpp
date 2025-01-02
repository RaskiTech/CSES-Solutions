#include <bits/stdc++.h>
using namespace std;
#define int long long
 
// https://codeforces.com/blog/entry/47821
signed main() {
    int n;
    cin >> n;

	priority_queue<int> que;
    int first;
    cin >> first;
    que.push(first);

    int res = 0;
	for (int i = 1; i < n; i++)
	{
		int num;
        cin >> num;
		que.push(num);
		if (que.top() > num)
		{
			res += que.top() - num;
			que.pop();
			que.push(num);
		}
	}
	cout << res;
	return 0;
}