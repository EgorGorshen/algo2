#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    size_t n = 0;
    size_t m = 0;
    std::cin >> n >> m;

    std::vector<std::pair<size_t, size_t>> gr(n, {0, 0});
    size_t from_ = 0;
    size_t to_ = 0;

    for (size_t i = 0; i < m; ++i) {
        std::cin >> from_ >> to_;
        --from_;
        --to_;
        ++gr[from_].first;
        ++gr[to_].second;
    }

    for (size_t i = 0; i < n; ++i) {
        std::cout << gr[i].second << std::endl << gr[i].first << std::endl;
    }
    return 0;
}
