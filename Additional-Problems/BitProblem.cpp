#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main()
{
    int n;
    cin >> n;

    vector<tuple<int, int, int>> boxes(n);
    for (int i = 0; i < boxes.size(); i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        boxes[i] = {x, y, z};
    }
    sort(boxes.begin(), boxes.end());

    // We can ignore x, since every new box can always be put under according to it
    // bag: from y to height
    set<pair<int, int>> bag;

    vector<pair<int, int>> removeThese;
    removeThese.reserve(50);

    for (auto& [_, y, height] : boxes)
    {
        if (bag.empty())
        {
            bag.insert({y, height});
            continue;
        }

        auto next = bag.upper_bound({y, INT_MAX});
        if (next == bag.begin())
        {
            while (next != bag.end() && (*next).second <= height)
                removeThese.push_back(*next), next++;
            bag.insert({y, height});
        }
        else
        {
            auto possibleRemove = next;
            next--;
            int newHeight = (*next).second + height;
            if ((*next).first == y)
                possibleRemove = next;
            
            while (possibleRemove != bag.end() && (*possibleRemove).second <= newHeight)
                removeThese.push_back(*possibleRemove), possibleRemove++;
            
            bag.insert({y, newHeight});
        }

        for (auto& elem : removeThese) bag.erase(elem);
        removeThese.clear();
    }

    auto last = bag.end();
    last--;
    cout << (*last).second;
}