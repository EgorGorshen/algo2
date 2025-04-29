#include <cstddef>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

size_t inf = 10000000000000000;

int main() {
    size_t n = 0;
    size_t m = 0;

    std::cin >> n >> m;

    std::vector<std::vector<int>> gr(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> gr_dist(n, std::vector<int>(m, inf));
    std::vector<std::vector<bool>> visted(n, std::vector<bool>(m, false));
    std::queue<std::pair<size_t, size_t>> que;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cin >> gr[i][j];
            if (gr[i][j]) {
                gr_dist[i][j] = 0;
                que.push({i, j});
            }
        }
    }

    while (!que.empty()) {
        auto [ni, nj] = que.front();
        visted[ni][nj] = true;
        que.pop();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (size_t k = 0; k < 4; ++k) {
            size_t i = ni + dx[k];
            size_t j = nj + dy[k];
            if (i < 0 || i >= n || j < 0 || j >= m) continue;

            if (gr_dist[i][j] > gr_dist[ni][nj] + 1) {
                gr_dist[i][j] = gr_dist[ni][nj] + 1;
                que.push({i, j});
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cout << gr_dist[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
