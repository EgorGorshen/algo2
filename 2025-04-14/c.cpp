#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

bool dfs(size_t u, std::vector<size_t>& visit,
         const std::vector<std::vector<size_t>>& gr, std::vector<size_t>& cycle,
         std::vector<int>& parent) {
    visit[u] = 1;
    for (size_t v : gr[u]) {
        if (visit[v] == 1) {
            cycle.push_back(u);
            size_t cur = u;
            while (cur != v) {
                cur = parent[cur];
                cycle.push_back(cur);
            }
            std::reverse(cycle.begin(), cycle.end());
            return true;
        }
        if (visit[v] == 0) {
            parent[v] = static_cast<int>(u);
            if (dfs(v, visit, gr, cycle, parent)) {
                return true;
            }
        }
    }
    visit[u] = 2;
    return false;
}

int main() {
    size_t n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<size_t>> gr(n);
    std::vector<size_t> visit(n, 0);
    std::vector<int> parent(n, -1);
    std::vector<size_t> cycle;

    for (size_t i = 0; i < m; ++i) {
        size_t u, v;
        std::cin >> u >> v;
        --u;
        --v;
        gr[u].push_back(v);
    }

    for (size_t u = 0; u < n; ++u) {
        if (visit[u] == 0 && dfs(u, visit, gr, cycle, parent)) {
            break;
        }
    }

    if (cycle.empty()) {
        std::cout << "NO";
    } else {
        std::cout << "YES" << std::endl;
        for (size_t v : cycle) {
            std::cout << v + 1 << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
