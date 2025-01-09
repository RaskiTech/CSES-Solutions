#include <bits/stdc++.h>
using namespace std;
#define int long long
 
struct Treap {
    Treap *left, *right, *parent;
    int weight, size;
    bool flipped;
    int value;
    Treap(int v) : left(nullptr), right(nullptr), parent(nullptr), weight(rand()), size(1),
        flipped(false), value(v) {}
};
 
int size(Treap *treap) {
    if (!treap)
        return 0;
    return treap->size;
}
void propagateFlip(Treap* treap) { 
    if (!treap || !treap->flipped) return;
 
    swap(treap->left, treap->right);
    if (treap->left) treap->left->flipped = !treap->left->flipped;
    if (treap->right) treap->right->flipped = !treap->right->flipped;
    treap->flipped = false;
}
void MakeSureNoFlip(Treap* treap)
{
    if (treap->parent) MakeSureNoFlip(treap->parent);
    propagateFlip(treap);
}
 
void split(Treap* treap, Treap *&outLeft, Treap *&outRight, int leftCount)
{
    if (treap == NULL) {
        outLeft = outRight = NULL;
        return;
    }
 
    propagateFlip(treap);
    if (size(treap->left) < leftCount) {
        split(treap->right, treap->right, outRight, leftCount-size(treap->left) - 1);
        outLeft = treap;
    }
    else {
        split(treap->left, outLeft, treap->left, leftCount);
        outRight = treap;
    }
    if (outRight)
    {
        outRight->parent = nullptr;
        if (outRight->left) outRight->left->parent = outRight;
        if (outRight->right) outRight->right->parent = outRight;
    }
    if (outLeft) 
    {
        outLeft->parent = nullptr;
        if (outLeft->left) outLeft->left->parent = outLeft;
        if (outLeft->right) outLeft->right->parent = outLeft;
    }
    treap->size = size(treap->left) + size(treap->right) + 1;
}
 
void merge(Treap*& outTreap, Treap* left, Treap* right) {

    if (!left || !right) {
        outTreap = left ? left : right;
        return;
    }
 
    if (left->weight < right->weight) {
        propagateFlip(left);
 
        merge(left->right, left->right, right);
        outTreap = left;
    } 
    else {
        propagateFlip(right);
        merge(right->left, left, right->left);
        outTreap = right;
    }
    if (outTreap->left) outTreap->left->parent = outTreap;
    if (outTreap->right) outTreap->right->parent = outTreap;
    outTreap->size = size(outTreap->left) + size(outTreap->right) + 1;
}

int FindIndex(Treap* treap)
{
    MakeSureNoFlip(treap);
    int idx = 0;
    Treap* prev = nullptr;
    idx += size(treap->left);
    while (treap->parent != nullptr)
    {
        prev = treap;
        treap = treap->parent;
        if (prev == treap->right)
            idx += size(treap->left) + 1;
    }
    return idx;
}
 
void Print(Treap* treap) {
    if (treap == NULL) return;
    propagateFlip(treap);
    Print(treap->left);
    cout << treap->value;
    Print(treap->right);
}
 
signed main() {
    int n;
    cin >> n;
 
    Treap* treap = nullptr;
    vector<Treap*> treapsByNumber(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        a--;
        treapsByNumber[a] = new Treap(a);
        merge(treap, treap, treapsByNumber[a]);
    }

    cout << n << '\n';
    for (int i = 0; i < n; i++)
    {
        int idx = FindIndex(treapsByNumber[i]);
        cout << i+1 << ' ' << idx+1 << '\n';

        Treap* left, *middle, *right;
        split(treap, middle, right, idx+1);
        split(middle, left, middle, i);
        middle->flipped = true;
        merge(treap, left, middle);
        merge(treap, treap, right);
    }
}