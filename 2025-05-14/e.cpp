#include <algorithm>
#include <iostream>
#include <vector>

int inf = 1e9;

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> gr(n, std::vector<int>(n, inf));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val;
            std::cin >> val;
            if (val == 0 && i != j)
                gr[i][j] = inf;
            else
                gr[i][j] = val;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (gr[i][k] < inf && gr[k][j] < inf) {
                    gr[i][j] =
                        std::min(gr[i][j], std::max(gr[i][k] + gr[k][j], -inf));
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (gr[i][j] == inf) {
                std::cout << 0;
            } else {
                bool f = false;
                for (int k = 0; k < n; ++k) {
                    if (gr[i][k] < inf && gr[k][j] < inf && gr[k][k] < 0) {
                        f = true;
                        break;
                    }
                }
                std::cout << (f ? 2 : 1);
            }
            std::cout << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
