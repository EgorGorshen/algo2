#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int inf = 1e9;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> gr(n, std::vector<int>(m));
    std::vector<std::vector<int>> dist(n, std::vector<int>(m, inf));
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    std::queue<std::pair<int, int>> que;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> gr[i][j];
        }
    }

    que.push({0, 0});
    dist[0][0] = 0;
    visited[0][0] = true;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!que.empty()) {
        const auto [ni, nj] = que.front();
        que.pop();

        for (int k = 0; k < 4; ++k) {
            int i = ni, j = nj;

            while ((0 <= i && i < n) && (0 <= j && j < m) && gr[i][j] != 1) {
                if (gr[i][j] == 2) {
                    std::cout << dist[ni][nj] + 1;
                    return 0;
                }
                i += dx[k];
                j += dy[k];
            }

            i -= dx[k];
            j -= dy[k];

            if (!visited[i][j]) {
                visited[i][j] = true;
                dist[i][j] = dist[ni][nj] + 1;
                que.push({i, j});
            }
        }
    }

    return 0;
}
