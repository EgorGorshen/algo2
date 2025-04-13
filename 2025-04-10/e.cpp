#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

#define GRAPH_MATRIX std::vector<std::vector<bool>>

void dfs(const GRAPH_MATRIX& gr, std::vector<bool>& visited, size_t node) {
    visited[node] = true;
    for (size_t i = 0; i < gr.size(); ++i) {
        if (gr[node][i] && !visited[i]) {
            dfs(gr, visited, i);
        }
    }
}

int main() {
    size_t n, m;
    std::cin >> n >> m;

    if (m != n - 1) {
        std::cout << "NO";
        return 0;
    }

    GRAPH_MATRIX gr(n, std::vector<bool>(n, false));
    std::vector<bool> visited(n, false);

    for (size_t k = 0; k < m; ++k) {
        size_t i, j;
        std::cin >> i >> j;

        --i;
        --j;
        gr[i][j] = true;
        gr[j][i] = true;
    }

    dfs(gr, visited, 0);

    if (std::all_of(visited.begin(), visited.end(), [](bool v) { return v; })) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}
