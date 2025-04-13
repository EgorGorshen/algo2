#include <cstddef>
#include <iostream>
#include <vector>

int main() {
    size_t n = 0;
    size_t m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<bool> > gr(n, std::vector<bool>(n, false));
    size_t h = 0;
    size_t w = 0;
    for (int k = 0; k < m; ++k) {
        std::cin >> h >> w;
        h--;
        w--;
        gr[h][w] = true;
        gr[w][h] = true;
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (!gr[i][j]) {
                std::cout << "NO";
                return 0;
            }
        }
    }

    std::cout << "YES";
    return 0;
}
