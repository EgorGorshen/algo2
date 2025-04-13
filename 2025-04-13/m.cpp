#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    size_t n = 0;
    std::cin >> n;

    std::vector<std::pair<size_t, size_t> > gr(n, std::pair(0, 0));
    bool v = false;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> v;

            gr[i].first += v;
            gr[j].second += v;
        }
    }

    for (size_t i = 0; i < n; ++i) {
        std::cout << gr[i].second << std::endl << gr[i].first << std::endl;
    }
    return 0;
}
