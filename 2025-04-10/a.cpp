#include <iostream>
#include <vector>

int main() {
    size_t n, m;
    std::cin >> n >> m;

    if (m != n * (n - 1) / 2) {
        std::cout << "NO";
        return 0;
    }

    std::vector<std::vector<int> > mt(n, std::vector<int>(n, 0));

    for (size_t i = 0; i < m; i++) {
        size_t u, v;
        std::cin >> u >> v;
        u--;
        v--;
        mt[u][v] = 1;
    }

    for (size_t i = 0; i < n; i++) {
        if (mt[i][i] != 0) {
            std::cout << "NO";
            return 0;
        }
        for (size_t j = 0; j < n; j++) {
            if (i == j) continue;
            if (mt[i][j] + mt[j][i] != 1) {
                std::cout << "NO";
                return 0;
            }
        }
    }

    std::cout << "YES";
    return 0;
}
