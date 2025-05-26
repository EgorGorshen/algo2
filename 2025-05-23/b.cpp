#include <iostream>
#include <numeric>
#include <vector>

class GCDSegmentTree {
    std::vector<int> arr;
    std::vector<int> tree;
    size_t sz;

    void build(int v, int left, int right) {
        if (left + 1 == right) {
            tree[v] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2 * v + 1, left, mid);
        build(2 * v + 2, mid, right);
        tree[v] = std::gcd(tree[2 * v + 1], tree[2 * v + 2]);
    }

    int get(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql) return 0;
        if (ql <= l && r <= qr) return tree[v];
        int mid = (l + r) / 2;
        int left_gcd = get(2 * v + 1, l, mid, ql, qr);
        int right_gcd = get(2 * v + 2, mid, r, ql, qr);
        return std::gcd(left_gcd, right_gcd);
    }

   public:
    GCDSegmentTree(const std::vector<int>& input) {
        sz = 1;
        while (sz < input.size()) sz <<= 1;
        arr = input;
        arr.resize(sz, 0);
        tree.resize(2 * sz - 1);
        build(0, 0, sz);
    }

    int get(int l, int r) { return get(0, 0, sz, l - 1, r); }
};

int main() {
    int n = 0;
    int k = 0;
    int l = 0, r = 0;

    std::cin >> n;
    std::vector<int> arr(n);
    for (int& x : arr) std::cin >> x;

    GCDSegmentTree tree(arr);

    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        std::cin >> l >> r;
        std::cout << tree.get(l, r) << " ";
    }

    return 0;
}
