#include <cstddef>
#include <iostream>
#include <vector>

int main() {
    size_t n = 0;
    size_t m = 0;

    std::cin >> n >> m;

    size_t v = 0;
    size_t u = 0;

    std::vector<size_t> gr(n, 0);

    for (size_t i = 0; i < m; ++i) {
        std::cin >> u >> v;
        ++gr[--u];
        ++gr[--v];
    }

    for (size_t i = 0; i < n; ++i) {
        std::cout << gr[i] << ' ';
    }

    return 0;
}
