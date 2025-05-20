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

        if (pa == pb) {
            std::cout << "ALREADY " << a << ' ' << b << std::endl;
        }

        core_[pb] = pa;
    }
};

int main() {
    int reset_count = 0;
    DisjointSets ds(0);
    std::string cmd;
    while (std::cin >> cmd)
        if (cmd == "RESET") {
            int n = 0;
            std::cin >> n;
            ds = DisjointSets(n);
            std::cout << "RESET DONE" << std::endl;
        } else if (cmd == "JOIN") {
            int j = 0;
            int k = 0;
            std::cin >> j >> k;
            ds.Union(j, k);
        } else if (cmd == "CHECK") {
            int j = 0;
            int k = 0;
            std::cin >> j >> k;
            size_t pi = ds.Find(j);
            size_t pk = ds.Find(k);
            if (pi == pk)
                std::cout << "YES";
            else
                std::cout << "NO";
            std::cout << std::endl;
        }
}
