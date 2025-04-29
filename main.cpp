#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

std::vector<int> used;
std::vector<int> tin;
std::vector<std::vector<int>> gr;
std::vector<int> tout;
std::set<int> points;
int timer = 0;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = tout[v] = timer++;
    int x = 0;
    for (const auto to : gr[v]) {
        if (to == p) continue;
        if (used[to]) {
            tout[v] = std::min(tout[v], tin[to]);
        } else {
            dfs(to, v);
            tout[v] = std::min(tout[v], tout[to]);
            if (p != -1 && tout[to] >= tin[v]) {
                points.insert(v);
            }
            ++x;
        }
    }
    if (p == -1 && x > 1) {
        points.insert(v);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    gr.resize(n + 1);
    used.resize(n + 1, 0);
    tin.resize(n + 1);
    tout.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }

    std::cout << points.size() << '\n';
    for (int v : points) {
        std::cout << v << ' ';
    }
    if (!points.empty()) {
        std::cout << '\n';
    }

    return 0;
}
