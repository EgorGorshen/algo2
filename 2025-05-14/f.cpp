#include <iostream>
#include <vector>

int inf = 1e9;

int main() {
    int n = 0;
    std::cin >> n;

    std::vector<std::vector<int>> gr(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> gr[i][j];
            if (gr[i][j] == -1) gr[i][j] = inf;
            if (i == j) gr[i][j] = 0;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (gr[i][k] != inf && gr[k][j] != inf) {
                    gr[i][j] = std::min(gr[i][j], gr[i][k] + gr[k][j]);
                }
            }
        }
    }

    std::vector<int> e(n, 0);

    int d = 0;
    int r = inf;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (gr[i][j] != inf) {
                e[i] = std::max(e[i], gr[i][j]);
            }
        }
        d = std::max(d, e[i]);
        r = std::min(r, e[i]);
    }

    std::cout << d << std::endl << r;

    return 0;
}
