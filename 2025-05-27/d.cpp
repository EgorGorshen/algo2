#include <algorithm>
#include <iostream>
#include <vector>

class SegmentTree {
    std::vector<int> tree_, arr_;
    int size;

    void push(int v, int tl, int tr) {
        if (arr_[v]) {
            tree_[v] += arr_[v];
            if (tl + 1 < tr) {
                arr_[2 * v + 1] += arr_[v];
                arr_[2 * v + 2] += arr_[v];
            }
            arr_[v] = 0;
        }
    }

    int get_max(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (r <= tl || tr <= l) return 0;
        if (l <= tl && tr <= r) return tree_[v];
        int tm = (tl + tr) / 2;
        return std::max(get_max(2 * v + 1, tl, tm, l, r),
                        get_max(2 * v + 2, tm, tr, l, r));
    }

    void range_add(int v, int tl, int tr, int l, int r, int val) {
        push(v, tl, tr);
        if (r <= tl || tr <= l) return;
        if (l <= tl && tr <= r) {
            arr_[v] += val;
            push(v, tl, tr);
            return;
        }

        int tm = (tl + tr) / 2;
        range_add(2 * v + 1, tl, tm, l, r, val);
        range_add(2 * v + 2, tm, tr, l, r, val);
        tree_[v] = std::max(tree_[2 * v + 1], tree_[2 * v + 2]);
    }

   public:
    SegmentTree(int n) {
        size = n;
        tree_.assign(4 * n, 0);
        arr_.assign(4 * n, 0);
    }

    int get_max(int l, int r) { return get_max(0, 0, size, l, r); }

    void range_add(int l, int r, int val) { range_add(0, 0, size, l, r, val); }
};

int main() {
    int n = 0;
    int k = 0;
    int m = 0;
    std::cin >> n >> k >> m;
    SegmentTree tree(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        if (tree.get_max(x, y) < k) {
            tree.range_add(x, y, 1);
            std::cout << 1;
        } else {
            std::cout << 0;
        }
        std::cout << std::endl;
    }

    return 0;
}
