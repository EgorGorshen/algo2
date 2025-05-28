#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

class SectionTree {
    std::vector<int> arr_;
    std::vector<int> tree_;
    int n;

    void build(int v, int tl, int tr) {
        if (tr - tl == 1) {
            if (tl < (int)arr_.size())
                tree_[v] = arr_[tl];
            else
                tree_[v] = 0;

            return;
        }

        int md = (tl + tr) / 2;
        build(2 * v, tl, md);
        build(2 * v + 1, md, tr);
        tree_[v] = std::gcd(tree_[2 * v], tree_[2 * v + 1]);
    }

    int get(int v, int tl, int tr, int ql, int qr) {
        if (qr <= tl || tr <= ql) return 0;
        if (ql <= tl && tr <= qr) return tree_[v];
        int mid = (tl + tr) / 2;
        return std::gcd(get(2 * v, tl, mid, ql, qr),
                        get(2 * v + 1, mid, tr, ql, qr));
    }

    void update(int v, int tl, int tr, int ind, int value) {
        if (tr - tl == 1) {
            tree_[v] += value;
            return;
        }

        int md = (tl + tr) / 2;
        if (ind < md) {
            update(2 * v, tl, md, ind, value);
        } else {
            update(2 * v + 1, md, tr, ind, value);
        }
        tree_[v] = std::gcd(tree_[2 * v], tree_[2 * v + 1]);
    }

   public:
    SectionTree(std::vector<int> &&Arr) : arr_(std::move(Arr)) {
        n = 1;
        while (n < arr_.size()) n <<= 1;
        tree_.assign(2 * n, 0);
        build(1, 0, n);
    }

    int get(int from_, int till_) { return get(1, 0, n, from_, till_); }
    void update(int ind, int value) { update(1, 0, n, ind, value); }
};

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> arr(n);

    for (int i = 0; i < n; ++i) std::cin >> arr[i];
    SectionTree tree(std::move(arr));

    int k = 0;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        int l, r;
        std::cin >> l >> r;
        std::cout << tree.get(l - 1, r) << ' ';
    }

    return 0;
}
