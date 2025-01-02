#include <bits/stdc++.h>
using namespace std;
#define int long long
 
struct Treap {
    Treap *left, *right;
    int weight, size;
    bool flipped;
    char value;
    Treap(char v) : left(nullptr), right(nullptr), weight(rand()), size(1),
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
    outTreap->size = size(outTreap->left) + size(outTreap->right) + 1;
}
 
void Print(Treap* treap) {
    if (treap == NULL) return;
    propagateFlip(treap);
    Print(treap->left);
    cout << treap->value;
    Print(treap->right);
}
 
signed main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
 
    Treap* treap = nullptr;
    for (int i = 0; i < s.size(); i++)
        merge(treap, treap, new Treap(s[i]));
 
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
 
        Treap* left, *middle, *right;
        split(treap, middle, right, b);
        split(middle, left, middle, a-1);
        middle->flipped = true;
        merge(treap, left, middle);
        merge(treap, treap, right);
    }
 
    Print(treap);
    cout << "\n";
}