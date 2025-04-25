#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>

std::pair<std::vector<int>, int> bfs_diameter(
    const std::vector<std::vector<int>>& gr) {
    int n = gr.size();
    int max_dist = 0;
    std::vector<int> best_path;

    for (int start = 0; start < n; ++start) {
        std::vector<int> dist(n, -1);
        std::vector<int> parent(n, -1);
        std::queue<int> que;

        dist[start] = 0;
        que.push(start);

        while (!que.empty()) {
            int node = que.front();
            que.pop();

            for (int neib : gr[node]) {
                if (dist[neib] != -1) continue;

                dist[neib] = dist[node] + 1;
                parent[neib] = node;
                que.push(neib);
            }
        }

        for (int end = 0; end < n; ++end) {
            if (dist[end] != -1 && dist[end] > max_dist) {
                max_dist = dist[end];

                std::vector<int> path;
                for (int v = end; v != -1; v = parent[v]) {
                    path.push_back(v);
                }
                std::reverse(path.begin(), path.end());
                best_path = path;
            }
        }
    }

    return {best_path, max_dist};
}

int dfs_depth(int v, int parent, const std::vector<std::vector<int>>& gr,
              const std::vector<bool>& on_diam) {
    int max_depth = 0;
    for (int u : gr[v]) {
        if (u == parent || on_diam[u]) continue;
        max_depth = std::max(max_depth, 1 + dfs_depth(u, v, gr, on_diam));
    }
    return max_depth;
}

std::vector<int> create_magistral(const std::vector<std::vector<int>>& gr,
                                  const std::vector<int>& diam) {
    int n = gr.size();
    std::vector<bool> on_diam(n, false);
    for (int v : diam) on_diam[v] = true;

    std::vector<int> depths;
    for (int v : diam) {
        int mx = 0;
        for (int u : gr[v]) {
            if (on_diam[u]) continue;
            mx = std::max(mx, 1 + dfs_depth(u, v, gr, on_diam));
        }
        depths.push_back(mx);
    }

    return depths;
}

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> gr(n);

    for (int i = 0; i < n - 1; ++i) {
        int from = 0;
        int to = 0;
        std::cin >> from >> to;
        --from, --to;
        gr[from].push_back(to);
        gr[to].push_back(from);
    }

    auto [diameter_path, diameter_len] = bfs_diameter(gr);

    if (diameter_len >= m) {
        std::cout << m;
    } else {
        std::vector<int> magistral = create_magistral(gr, diameter_path);
        int count = diameter_path.size();
        m -= count;
        for (int node : magistral) {
            if (m < 0) break;

            if (m >= 2 * node) {
                count += node;
                m -= 2 * node;
            } else if (m >= node) {
                count += node;
                break;
            } else {
                count += m;
                break;
            }
        }
        std::cout << count;
    }

    return 0;
}
