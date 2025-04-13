#include <cstddef>
#include <iostream>
#include <vector>

#define GRAPH_MATRIX(type) std::vector<std::vector<type> >

int main() {
    size_t n = 0;
    std::cin >> n;

    GRAPH_MATRIX(bool) gr(n, std::vector<bool>(n, false));
    bool v = false;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> v;
            gr[i][j] = v;
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if ((gr[i][j] != gr[j][i]) || (i == j && gr[i][j] != 0)) {
                std::cout << "NO";
                return 0;
            }
        }
    }

    std::cout << "YES";
    return 0;
}
