#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

std::vector<std::vector<int>> gr;
std::vector<int> used;
std::vector<int> tin;
std::vector<int> tout;
std::set<int> ans;
std::vector<std::pair<int, int>> e;
int timer = 0;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = tout[v] = timer++;
    for (size_t i = 0; i < gr[v].size(); ++i) {
        int to = gr[v][i];
        if (to == p) continue;
        if (used[to]) {
            tout[v] = std::min(tout[v], tin[to]);
        } else {
            dfs(to, v);
            tout[v] = std::min(tout[v], tout[to]);
            if (tin[v] < tout[to]) {
                for (size_t j = 0; j < e.size(); ++j) {
                    if ((e[j].first == v && e[j].second == to) ||
                        (e[j].first == to && e[j].second == v)) {
                        ans.insert(j + 1);
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    gr.resize(n + 1);
    used.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    e.resize(m);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        e[i] = {u, v};
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    dfs(1);
    std::cout << ans.size() << '\n';
    for (int x : ans) {
        std::cout << x << ' ';
    }
    if (!ans.empty()) {
        std::cout << '\n';
    }

    return 0;
}
