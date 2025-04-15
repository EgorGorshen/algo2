#include <cstddef>
#include <iostream>
#include <vector>

bool dfs(size_t v, const std::vector<std::vector<size_t>>& gr,
         std::vector<size_t>& visted) {
    visted[v] = 1;

    for (size_t u = 0; u < gr.size(); ++u) {
        if (gr[v][u]) {
            if (visted[u] == 0) {
                if (dfs(u, gr, visted)) return true;
            } else if (visted[u] == 1) {
                return true;
            }
        }
    }

    visted[v] = 2;
    return false;
}

int main() {
    size_t n = 0;
    std::cin >> n;

    std::vector<std::vector<size_t>> gr(n, std::vector<size_t>(n));
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j) std::cin >> gr[i][j];

    std::vector<size_t> color(n, 0);

    for (size_t i = 0; i < n; ++i) {
        if (color[i] == 0 && dfs(i, gr, color)) {
            std::cout << 1;
            return 0;
        }
    }

    std::cout << 0;
    return 0;
}
