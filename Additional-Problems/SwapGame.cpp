#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
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
 
#define cross(x, y) (((x)*conj(y)).imag())
#define sign(v) ((0 < (v)) - ((v) < 0))
 
int dist(int num, int pos) { return abs((num%3)-(pos%3)) + abs(num/3-(pos/3)); }
 
int minDist(vector<int>& state)
{
    
 
    int minD = INT_MAX;
    for (int i = 0; i < 6; i++)
    {
        int switchDist = dist(state[i], i+3) + dist(state[i+3], i);
        int currDist = dist(state[i], i) + dist(state[i+3], i+3);
        if (switchDist < currDist || (
            switchDist == currDist && max(dist(state[i], i+3), dist(state[i+3], i)) < max(dist(state[i], i), dist(state[i+3], i+3))))
        {
            swap(state[i], state[i+3]);
            minD = min(minD, minDist(state)+1);
            swap(state[i], state[i+3]);
        }
    }
    for (int i : {0, 1, 3, 4, 6, 7})
    {
        int switchDist = dist(state[i], i+1) + dist(state[i+1], i);
        int currDist = dist(state[i], i) + dist(state[i+1], i+1);
        if (switchDist < currDist || (
            switchDist == currDist && max(dist(state[i], i+1), dist(state[i+1], i)) < max(dist(state[i], i), dist(state[i+1], i+1))))
        {
            swap(state[i], state[i+1]);
            minD = min(minD, minDist(state)+1);
            swap(state[i], state[i+1]);
        }
    }
    cout << "Found " << minD << " for\n";
    for (int i = 0; i < state.size(); i++)
    {
        cout << state[i] << " ";
        if (i % 3 == 2)
            cout << '\n';
    }
    if (minD == INT_MAX)
    {
        bool t = true;
        for (int i = 0; i < state.size(); i++)
            t |= state[i] == i;
        return t ? 0 : INT_MAX;
    }
 
    return minD;
}
 
void solve()
{
    string orig;
    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        orig.push_back(c);
    }
    
    unordered_set<string> visited;
    queue<string> states;
    states.push(orig);
    visited.insert(orig);
    states.push("-");
 
    int steps = 0;
    while (!states.empty())
    {
        if (states.front() == "-")
        {
            states.pop();
            states.push("-");
            steps++;
            continue;
        }
 
        if (states.front() == "123456789")
        {
            break;
        }
 
        // Generate all solutions
        string state = states.front();
        for (int i = 0; i < 6; i++)
        {
            swap(state[i], state[i+3]);
            if (visited.find(state) != visited.end())
            {
                swap(state[i], state[i+3]);
                continue;
            }
            visited.insert(state);
            states.push(state);
            swap(state[i], state[i+3]);
        }
        for (int i : {0, 1, 3, 4, 6, 7})
        {
            swap(state[i], state[i+1]);
            if (visited.find(state) != visited.end())
            {
                swap(state[i], state[i+1]);
                continue;
            }
            visited.insert(state);
            states.push(state);
            swap(state[i], state[i+1]);
        }
        states.pop();
    }
 
    cout << steps;
 
}
 
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(15);
 
    int t = 1;
 
    //cin >> t;
 
    for (int i = 0; i < t; i++)
    {
        solve();
        cout.flush();
    }
}