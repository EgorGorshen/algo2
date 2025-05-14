#include <iostream>
#include <queue>
#include <vector>

int64_t inf = 1e16;

struct Node {
    int from_;
    int to_;
    int64_t weight;
};

int main() {
    int n = 0;
    int m = 0;
    int s = 0;
    std::cin >> n >> m >> s;
    --s;

    std::vector<Node> edges(m);
    for (int i = 0; i < m; ++i) {
        int u = 0;
        int v = 0;
        int64_t w = 0;
        std::cin >> u >> v >> w;
        edges[i] = {u - 1, v - 1, w};
    }

    std::vector<int64_t> dist(n, inf);
    std::vector<bool> reachable(n, false);
    dist[s] = 0;
    reachable[s] = true;

    for (int i = 0; i < n - 1; ++i) {
        for (const auto& e : edges) {
            if (dist[e.from_] < inf && dist[e.from_] + e.weight < dist[e.to_]) {
                dist[e.to_] = dist[e.from_] + e.weight;
                reachable[e.to_] = true;
            }
        }
    }

    std::vector<bool> negativ(n, false);
    for (auto e : edges) {
        if (dist[e.from_] < inf && dist[e.from_] + e.weight < dist[e.to_]) {
            negativ[e.to_] = true;
        }
    }

    std::queue<int> q;
    std::vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (negativ[i]) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto& e : edges) {
            if (e.from_ == u && !visited[e.to_]) {
                visited[e.to_] = true;
                negativ[e.to_] = true;
                q.push(e.to_);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!reachable[i]) {
            std::cout << "*";
        } else if (negativ[i]) {
            std::cout << "-";
        } else {
            std::cout << dist[i];
        }
        std::cout << std::endl;
    }

    return 0;
}
