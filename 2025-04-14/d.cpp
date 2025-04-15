#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    size_t n = 0;
    size_t m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<size_t>> gr(n);

    size_t u = 0;
    size_t v = 0;

    for (size_t i = 0; i < m; ++i) {
        std::cin >> u >> v;
        --u;
        --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    std::vector<int> color(n, -1);

    for (size_t start = 0; start < n; ++start) {
        if (color[start] != -1) {
            continue;
        }
        std::queue<size_t> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            size_t u = q.front();
            q.pop();
            for (size_t v : gr[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    std::cout << "NO";
                    return 0;
                }
            }
        }
    }
    std::cout << "YES";

    return 0;
}
