#include <iostream>
#include <vector>

int main() {
    size_t n = 0;
    size_t m = 0;
    std::cin >> n >> m;

    if (n == 1) {
        std::cout << "YES";
        return 0;
    }

    std::vector<std::vector<bool> > gr(n, std::vector<bool>(n, false));

    for (int k = 0; k < m; ++k) {
        int a, b;
        std::cin >> a >> b;
        gr[a - 1][b - 1] = true;
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (!gr[i][j] && !gr[j][i]) {
                std::cout << "NO";
                return 0;
            }
        }
    }

    std::cout << "YES";
    return 0;
}
