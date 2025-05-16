#include <iostream>
#include <queue>
#include <vector>

int64_t inf = 1e16;

struct Node {
    int to_;
    int64_t w;
};

int main() {
    int n = 0;
    int m = 0;
    int s = 0;
    int t = 0;

    std::cin >> n >> m >> s >> t;
    --s, --t;

    std::vector<std::vector<Node>> gr(n);

    int u = 0;
    int v = 0;
    int64_t w = 0;

    for (int i = 0; i < m; ++i) {
        std::cin >> u >> v >> w;
        --u, --v;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }

    std::vector<int64_t> dist(n, inf);
    dist[s] = 0;

    std::priority_queue<std::pair<int64_t, int>,
                        std::vector<std::pair<int64_t, int>>, std::greater<>>
        que;
    que.push({0, s});

    while (!que.empty()) {
        auto [d, u] = que.top();
        que.pop();

        if (d > dist[u]) {
            continue;
        }

        for (const Node& e : gr[u]) {
            if (dist[e.to_] > dist[u] + e.w) {
                dist[e.to_] = dist[u] + e.w;
                que.push({dist[e.to_], e.to_});
            }
        }
    }

    if (dist[t] == inf)
        std::cout << -1;
    else
        std::cout << dist[t];

    return 0;
}
