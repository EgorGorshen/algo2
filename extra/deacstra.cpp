#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int inf = 1e9;

int main() {
    int n = 0;
    int m = 0;
    int start = 0;
    int finish = 0;

    std::cin >> n >> m >> start >> finish;

    std::vector<std::vector<std::pair<int, int>>> gr(n + 1);

    for (int i = 0; i < m; ++i) {
        int u = 0;
        int v = 0;
        int w = 0;
        std::cin >> u >> v >> w;
        gr[u].push_back({v, w});
        gr[v].emplace_back(u, w);
    }

    std::vector<int> dist(n + 1, inf);
    dist[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        que;

    que.push({0, start});

    while (!que.empty()) {
        auto [d, from] = que.top();
        que.pop();

        for (auto [to, w] : gr[from]) {
            if (dist[to] > dist[from] + w) {
                dist[to] = dist[from] + w;
                que.push({dist[to], to});
            }
        }
    }

    std::cout << (dist[finish] == inf ? -1 : dist[finish]);
    return 0;
}
