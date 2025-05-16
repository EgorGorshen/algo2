#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int inf = 1e9;

int main() {
    int n = 0;
    int s = 0;
    int m = 0;
    std::cin >> n >> s >> m;
    --s;

    std::vector<std::vector<std::pair<int, int> > > gr(n);
    std::vector<int> dist(n, inf);
    std::vector<bool> visited(n, false);
    std::queue<int> que;

    dist[s] = 0;
    que.push(s);
    visited[s] = true;

    for (int i = 0; i < m; ++i) {
        int from_ = 0;
        int to_ = 0;
        int w = 0;
        std::cin >> from_ >> to_ >> w;
        --from_, --to_;
        gr[from_].emplace_back(to_, w);
    }

    while (!que.empty()) {
        int node = que.front();
        que.pop();
        visited[node] = false;

        for (auto [to, w] : gr[node]) {
            if (dist[node] != inf && dist[to] > dist[node] + w) {
                dist[to] = dist[node] + w;

                if (visited[to]) continue;
                que.push(to);
                visited[to] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i] == inf)
            std::cout << '?';
        else
            std::cout << dist[i];
        std::cout << ' ';
    }

    return 0;
}
