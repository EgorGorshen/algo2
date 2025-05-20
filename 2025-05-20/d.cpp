#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <ostream>
#include <string>
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

std::vector<bool> d;

struct Action {
    std::string cmd;
    size_t x;
    size_t y;

    void run(DisjointSets &ds) const {
        if (cmd == "ask") {
            if (ds.Find(x) == ds.Find(y))
                d.push_back(true);
            else
                d.push_back(false);
        } else if (cmd == "cut") {
            ds.Union(x, y);
        }
    }
};

int main() {
    int n = 0;
    int m = 0;
    int k = 0;
    std::cin >> n >> m >> k;

    DisjointSets ds(n + 1);
    std::vector<Action> act;

    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
    }

    for (int i = 0; i < k; ++i) {
        std::string cmd;
        size_t x;
        size_t y;
        std::cin >> cmd >> x >> y;
        act.push_back({cmd, x, y});
    }

    std::reverse(act.begin(), act.end());

    for (Action a : act) {
        a.run(ds);
    }

    for (int i = d.size() - 1; i >= 0; --i) {
        if (d[i])
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << std::endl;
    }

    return 0;
}
