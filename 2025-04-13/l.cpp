#include <cstddef>
#include <iostream>
#include <vector>
int main() {
    size_t n = 0;
    size_t m = 0;
    std::cin >> n >> m;
    std::vector<size_t> gr(n, 0);
    size_t h = 0;
    size_t w = 0;
    for (size_t i = 0; i < m; ++i) {
        std::cin >> h >> w;
        --h;
        --w;
        ++gr[h];
        ++gr[w];
    }

    for (size_t i = 0; i < n; ++i) {
        std::cout << gr[i] << std::endl;
    }

    return 0;
}
