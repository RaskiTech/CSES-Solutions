#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <cmath>
#include <functional>
#include <type_traits>
#include <fstream>
#include <bitset>
#include <complex>
#include <iomanip>
 
#define int long long
using namespace std;
 
//#define cross(x, y) ((x).real()*(y).imag()-(x).imag()*(y).real()) 
#define cross(x, y) (((x)*conj(y)).imag())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
struct Node {
    int middleStreak = 0;
    int leftStreak = 0;
    int rightStreak = 0;
};
 
class STree {
public:
    vector<Node> data;
    vector<int> children;
    int offset;
    STree(int size, string vals) {
        offset = 1;
        while (size > offset) offset <<= 1;
        data = vector<Node>(2*offset);
 
        children = vector<int>(data.size());
        for (int i = offset; i < data.size(); i++)
            children[i] = 1;
        for (int i = offset-1; i > 0; i--)
            children[i] = children[i*2] + children[i*2+1];
        
        for (int i = 0; i < vals.size(); i++)
        {
            data[i+offset].middleStreak = 1;
            data[i+offset].rightStreak = ((vals[i]  == '1') ? 1 : -1);
            data[i+offset].leftStreak = ((vals[i] == '1') ? 1 : -1);
        }
        for (int i = offset-1; i > 0; i--)
            Update(i);
        
        //Print();
    }
 
    void Update(int idx) 
    {
        data[idx].leftStreak = data[2*idx].leftStreak;
        if (data[idx].leftStreak == 0)
            data[idx].leftStreak = data[2*idx+1].leftStreak;
        else
        {
            if (abs(data[idx].leftStreak) == children[2*idx] && sign(data[idx].leftStreak) == sign(data[2*idx+1].leftStreak))
                data[idx].leftStreak += data[2*idx+1].leftStreak;
        }
        data[idx].rightStreak = data[2*idx+1].rightStreak;
        if (data[idx].rightStreak == 0)
            data[idx].rightStreak = data[2*idx].rightStreak;
        else {
            if (abs(data[idx].rightStreak) == children[2*idx+1] && sign(data[idx].rightStreak) == sign(data[2*idx].rightStreak))
                data[idx].rightStreak += data[2*idx].rightStreak;
        }
        data[idx].middleStreak = max(max(max(data[2*idx].middleStreak, data[2*idx+1].middleStreak), abs(data[idx].rightStreak)), abs(data[idx].leftStreak));
        if (sign(data[2*idx].rightStreak) == sign(data[2*idx+1].leftStreak))
            data[idx].middleStreak = max(data[idx].middleStreak, abs(data[2*idx].rightStreak + data[2*idx+1].leftStreak));
    }
 
    void Set(int idx, Node node)
    {
        idx += offset;
        data[idx] = node;
        idx /= 2;
        while (idx)
        {
            Update(idx);
            idx /= 2;
        }
 
    }
    void Print()
    {
        for (int i = 0; i < data.size(); i++)
            cout << "(" << data[i].leftStreak << " " << data[i].middleStreak << " " << data[i].rightStreak << ") ";
        cout << endl;
    }
 
};
 
void solve()
{
    string s;
    cin >> s;
 
    auto t = STree(s.size(), s);
 
    int n;
    cin >> n;
 
    for (int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        if (t.data[t.offset + idx-1].rightStreak == -1)
            t.Set(idx-1, Node{1, 1, 1});
        else
            t.Set(idx-1, Node{1, -1, -1});
        
        //t.Print();
        
        cout << abs(t.data[1].middleStreak) << " ";
    }
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    //cout.precision(25);
    //setprecision(10);
    //cin.tie(0);
 
    int t = 1;
 
    //cin >> t;
    //ifstream f("testcase.txt");
    //cin.rdbuf(f.rdbuf());
 
    for (int i = 0; i < t; i++)
        solve();
}