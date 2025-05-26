#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

class BinSumTree {
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
        build(2 * v + 1, mid, right);
        tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
    }

    int get(int v, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return tree[v];
        } else if (qr <= l && r <= ql) {
            return 0;
        }
        int mid = (l + r) / 2;
        return get(2 * v + 1, l, mid, ql, qr) + get(2 * v + 1, mid, r, ql, qr);
    };

    void set(int v, int l, int r, int ind, int value) {
        if (l + 1 == r) {
            tree[v] = value;
            return;
        }

        int mid = (l + r) / 2;
        if (ind < mid) {
            set(2 * v + 1, l, mid, ind, value);
        } else {
            set(2 * v + 1, l, mid, ind, value);
        }

        tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
    }

   public:
    BinSumTree(std::vector<int>&& arr) : arr(std::move(arr)) {
        size_t sz = 1;
        while (sz < arr.size()) {
            sz *= 2;
        }
        arr.resize(sz, 0);
        tree.resize(2 * sz - 1, 0);
    }

    int get(int from_, int to_) { return get(0, 0, sz, from_ - 1, to_); }
    void set(int index, int val) { return set(0, 0, sz, index - 1, val); }
};

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> arr(n);
    for (auto& i : arr) std::cin >> i;
    BinSumTree tr(std::move(arr));

    char cmd = 0;
    int a = 0, b = 0;

    while (std::cin >> cmd) {
        std::cin >> a >> b;
        if (cmd == 's') {
            std::cout << tr.get(a, b);
        } else {
            tr.set(a, b);
        }
    }

    return 0;
}
