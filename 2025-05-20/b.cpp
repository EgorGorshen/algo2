#include <cstddef>
#include <iostream>
#include <numeric>
#include <vector>

class DisjointSets {
   private:
    std::vector<size_t> core_;

   public:
    DisjointSets(size_t size) : core_(size) {
        std::iota(core_.begin(), core_.end(), 0);
    }

    size_t Find(size_t v) {
        if (core_[v] != v) {
            core_[v] = Find(core_[v]);
        }
        return core_[v];
    }

    void Union(size_t a, size_t b) {
        size_t pa = this->Find(a);
        size_t pb = this->Find(b);

        core_[pb] = pa;
    }
};

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    DisjointSets ds(n);

    for (int c = 0; c < m; ++c) {
        int v, u;
        std::cin >> u >> v;
        --v, --u;
        ds.Union(v, u);
        bool f = true;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (ds.Find(i) != ds.Find(j)) {
                    f = false;
                    break;
                };
            }
            if (!f) break;
        }
        if (f) {
            std::cout << c + 1;
            return 0;
        }
    }
    std::cout << m;
}
