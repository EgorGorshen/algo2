#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

int main() {
    size_t n = 0;
    size_t m = 0;

    std::cin >> n >> m;
    std::vector<std::vector<size_t>> g(n + 1);
    for (size_t i = 0; i < m; i++) {
        size_t u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<bool> used(n + 1, false);
    std::vector<size_t> comp(n + 1, 0);
    size_t c = 0;
    for (size_t i = 1; i <= n; i++) {
        if (used[i]) {
            continue;
        }
        ++c;
        std::queue<size_t> q;
        q.push(i);
        used[i] = true;
        comp[i] = c;
        while (!q.empty()) {
            size_t v = q.front();
            q.pop();
            for (size_t to : g[v]) {
                if (!used[to]) {
                    used[to] = true;
                    comp[to] = c;
                    q.push(to);
                }
            }
        }
    }

    std::cout << c << std::endl;
    for (size_t i = 1; i <= n; i++) {
        std::cout << comp[i];
        if (i < n) std::cout << " ";
    }
    return 0;
}
