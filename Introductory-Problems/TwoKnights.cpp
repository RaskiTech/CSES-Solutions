#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    int n;
    cin >> n;
 
    vector<int> firstOnes = {0, 6, 28, 96, 252};
    for (int i = 0; i < min<int>(n, firstOnes.size()); i++)
        cout << firstOnes[i] << '\n';
 
    int last = firstOnes.back();
    
    for (int i = firstOnes.size()+1; i <= n; i++)
    {
        // Special cases
        last += (i*i-3) + (i*i-5) + (i*i-i-2) + (i*i-i-2) + ((i-1)*i-3) + ((i-1)*(i-1)+1-3) + ((i-1)*(i-1)-2);
        // H Line
        last += (i-4) * (i*i-4) - (3+i-2) * (i-4) / 2;
        // V Line
        last += (i-4) * (i*(i-1)-4) - (3+i-2) * (i-4) / 2 + 1;
        last += (i-4);
 
        cout << last << '\n';
    }
 
}