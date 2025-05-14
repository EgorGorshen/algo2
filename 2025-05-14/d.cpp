#include <algorithm>
#include <iostream>
#include <vector>

int inf = 1e9;

int main() {
    int n = 0;
    std::cin >> n;

    std::vector<std::vector<int> > gr(n, std::vector<int>(n, 100));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> gr[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                gr[i][j] = std::min(gr[i][j], gr[i][k] + gr[k][j]);
            }
        }
    }

    for (auto line : gr) {
        for (int i : line) std::cout << i << ' ';
        std::cout << std::endl;
    }

    return 0;
}
