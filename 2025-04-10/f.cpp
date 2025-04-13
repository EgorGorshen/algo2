#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

#define GRAPH_LIST std::vector<std::vector<size_t>>

void dfs(const GRAPH_LIST& graph, std::vector<bool>& visited,
         std::vector<size_t>& path, size_t node) {
    visited[node] = true;
    path.push_back(node);
    for (size_t neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, path, neighbor);
            path.push_back(node);
        }
    }
}

int main() {
    size_t n, m, start;
    std::cin >> n >> m >> start;
    --start;

    GRAPH_LIST graph(n);
    for (size_t k = 0; k < m; ++k) {
        size_t u, v;
        std::cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (size_t i = 0; i < n; ++i) {
        std::sort(graph[i].begin(), graph[i].end());
    }

    std::vector<bool> visited(n, false);
    std::vector<size_t> path;

    dfs(graph, visited, path, start);

    std::cout << path.size() << std::endl;
    for (size_t i : path) {
        std::cout << i + 1 << ' ';
    }

    return 0;
}
