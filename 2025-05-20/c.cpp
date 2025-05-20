#include <cstddef>
#include <iostream>
#include <numeric>
#include <vector>
class DisjointSets {
   private:
    std::vector<size_t> core_;
    std::vector<int> rank_;
    std::vector<int> sum_;

   public:
    DisjointSets(size_t size) : core_(size), rank_(size, 0), sum_(size, 0) {
        std::iota(core_.begin(), core_.end(), 0);
    }

    size_t Find(size_t v) {
        if (core_[v] != v) {
            core_[v] = Find(core_[v]);
        }
        return core_[v];
    }

    void Union(size_t a, size_t b, int w) {
        size_t pa = Find(a);
        size_t pb = Find(b);
        if (pa == pb) {
            sum_[pa] += w;
            return;
        }

        if (rank_[pa] < rank_[pb]) std::swap(pa, pb);
        core_[pb] = pa;

        sum_[pa] += sum_[pb] + w;
        if (rank_[pa] == rank_[pb]) ++rank_[pa];
    }

    int GetSum(size_t v) { return sum_[Find(v)]; }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    DisjointSets ds(n + 1);

    for (int i = 0; i < m; ++i) {
        int cmd;
        std::cin >> cmd;
        if (cmd == 1) {
            int x, y, w;
            std::cin >> x >> y >> w;
            ds.Union(x, y, w);
        } else if (cmd == 2) {
            int set;
            std::cin >> set;
            std::cout << ds.GetSum(set) << '\n';
        }
    }
}
