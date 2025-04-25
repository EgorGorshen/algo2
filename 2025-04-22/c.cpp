#include <algorithm>
#include <cstddef>
#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> dist;
std::vector<int> low;
std::vector<int> parent;
std::unordered_set<int> art_points;
std::vector<std::vector<size_t>> gr;

int timer = 0;

void dfs(size_t u) {
    int children = 0;
    dist[u] = low[u] = ++timer;

    for (const size_t& node : gr[u]) {
        if (dist[node] == -1) {
            parent[node] = u;
            children++;
            dfs(node);

            low[u] = std::min(low[u], low[node]);

            if ((parent[u] == -1 && children > 1) ||
                (parent[u] != -1 && low[node] >= dist[u])) {
                art_points.emplace(u);
            }
        } else {
            low[u] = std::min(low[u], dist[node]);
        }
    }
}

int main() {
    size_t n = 0;
    size_t m = 0;
    std::cin >> n >> m;

    dist.resize(n, -1);
    low.resize(n, -1);
    parent.resize(n, -1);
    gr.resize(n);

    size_t h, w;
    for (size_t i = 0; i < m; ++i) {
        std::cin >> h >> w;
        --h;
        --w;

        gr[h].push_back(w);
        gr[w].push_back(h);
    }

    for (size_t i = 0; i < n; ++i) {
        if (dist[i] == -1) {
            dfs(i);
        }
    }

    std::vector<int> res(art_points.begin(), art_points.end());
    std::sort(res.begin(), res.end());

    std::cout << res.size() << std::endl;
    for (int node : res) {
        std::cout << node + 1 << std::endl;
    }

    return 0;
}
