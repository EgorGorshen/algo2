#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

struct Edge {
    int u, v;
    int64_t weight;

    bool operator<(const Edge &other) const { return weight < other.weight; }
};

class DisjointSets {
   private:
    std::vector<size_t> core_;
    std::vector<int> rank_;

   public:
    DisjointSets(size_t size) : core_(size), rank_(size, 0) {
        std::iota(core_.begin(), core_.end(), 0);
    }

    size_t Find(size_t v) {
        if (core_[v] != v) {
            core_[v] = Find(core_[v]);
        }
        return core_[v];
    }

    bool Union(size_t a, size_t b) {
        size_t pa = Find(a);
        size_t pb = Find(b);
        if (pa == pb) {
            return false;
        }

        if (rank_[pa] < rank_[pb]) {
            core_[pa] = pb;
        } else if (rank_[pa] > rank_[pb]) {
            core_[pb] = pa;
        } else {
            core_[pb] = pa;
            rank_[pa]++;
        }
        return true;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    std::sort(edges.begin(), edges.end());

    DisjointSets dsu(n);
    int64_t total_weight = 0;
    int edge_count = 0;

    for (const auto &e : edges) {
        if (dsu.Union(e.u, e.v)) {
            total_weight += e.weight;
            edge_count++;
            if (edge_count == n - 1) break;
        }
    }

    if (edge_count == n - 1) {
        std::cout << total_weight;
    } else {
        std::cout << "NON-CONNECTED";
    }

    return 0;
}
