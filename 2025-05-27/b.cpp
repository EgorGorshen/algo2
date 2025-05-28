#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

int inf = -1e9;

class MaxSegmentTree {
    std::vector<int64_t> tree_;
    int n;

    void build(const std::vector<int64_t>& arr, int v, int tl, int tr) {
        if (tr - tl == 1) {
            if (tl < (int)arr.size()) {
                tree_[v] = arr[tl];
            } else {
                tree_[v] = inf;
            }
            return;
        }

        int mid = (tl + tr) / 2;
        build(arr, 2 * v, tl, mid);
        build(arr, 2 * v + 1, mid, tr);
        tree_[v] = std::max(tree_[2 * v], tree_[2 * v + 1]);
    }

    int64_t get(int v, int tl, int tr, int l, int r) {
        if (r <= tl || tr <= l) return INT_MIN;
        if (l <= tl && tr <= r) return tree_[v];

        int mid = (tl + tr) / 2;
        return std::max(get(2 * v, tl, mid, l, r),
                        get(2 * v + 1, mid, tr, l, r));
    }

    void update(int v, int tl, int tr, int pos, int value) {
        if (tr - tl == 1) {
            tree_[v] = value;
            return;
        }

        int mid = (tl + tr) / 2;
        if (pos < mid)
            update(2 * v, tl, mid, pos, value);
        else
            update(2 * v + 1, mid, tr, pos, value);
        tree_[v] = std::max(tree_[2 * v], tree_[2 * v + 1]);
    }

   public:
    MaxSegmentTree(const std::vector<int64_t>& arr) {
        n = 1;
        while (n < (int)arr.size()) n <<= 1;
        tree_.assign(2 * n, INT_MIN);
        build(arr, 1, 0, n);
    }

    int64_t get(int l, int r) { return get(1, 0, n, l, r); }

    void update(int pos, int value) { update(1, 0, n, pos, value); }
};

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int64_t> arr(n);
    for (int i = 0; i < n; ++i) std::cin >> arr[i];
    MaxSegmentTree tree(arr);

    int k = 0;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        char cmd;
        std::cin >> cmd;

        if (cmd == 's') {
            int l = 0;
            int r = 0;
            std::cin >> l >> r;
            std::cout << tree.get(l, r) << ' ';
        } else if (cmd == 'u') {
            int ind = 0, val = 0;
            std::cin >> ind >> val;
            tree.update(ind, val);
        }
    }
}
