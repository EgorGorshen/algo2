#include <cstddef>
#include <iostream>
#include <vector>
#define GRAPH_MATRIX(type) std::vector<std::vector<type> >
int main() {
    size_t n = 0;
    size_t m = 0;
    std::cin >> n >> m;

    GRAPH_MATRIX(bool) gr(n, std::vector<bool>(n, false));

    size_t h = 0;
    size_t w = 0;
    for (size_t i = 0; i < m; ++i) {
        std::cin >> h >> w;
        --h;
        --w;

        if (gr[h][w]) {
            std::cout << "YES";
            return 0;
        }

        gr[h][w] = true;
        gr[w][h] = true;
    }

    std::cout << "NO";

    return 0;
}
