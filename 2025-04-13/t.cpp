#include <cstddef>
#include <iostream>
#include <vector>

int main() {
    size_t n;
    std::cin >> n;
    std::vector<std::vector<size_t> > gr(n, std::vector<size_t>(n, 0));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> gr[i][j];
        }
    }

    for (size_t u = 0; u < n; ++u) {
        for (size_t v = 0; v < n; ++v) {
            for (size_t w = 0; w < n; ++w) {
                if (gr[u][v] && gr[v][w] && !gr[u][w]) {
                    std::cout << "NO";
                    return 0;
                }
            }
        }
    }

    std::cout << "YES";
    return 0;
}
