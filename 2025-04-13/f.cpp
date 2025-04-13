#include <cstddef>
#include <iostream>
#include <vector>

#define GRAPH_MATRIX(type) std::vector<std::vector<type> >

int main() {
    size_t n = 0;
    size_t m = 0;
    std::cin >> n >> m;

    size_t h = 0;
    size_t w = 0;

    GRAPH_MATRIX(bool) gr(n, std::vector<bool>(n, false));

    for (size_t i = 0; i < m; ++i) {
        std::cin >> h >> w;
        --h;
        --w;

        gr[h][w] = true;
        gr[w][h] = true;
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cout << (int)gr[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
