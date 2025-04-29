#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int inf = 1000000000;

int main() {
    int n = 0;
    int m = 0;

    std::cin >> m >> n;
    std::vector<std::vector<bool>> gr(n, std::vector<bool>(m, false));
    std::vector<std::vector<int>> dist(n, std::vector<int>(m, inf));
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    std::queue<std::pair<int, int>> que;

    for (int i = 0; i < n; ++i) {
        char ch = ' ';
        for (int j = 0; j < m; ++j) {
            std::cin >> ch;
            if (ch == '.') {
                gr[i][j] = true;

                if (que.empty()) {
                    que.push({i, j});
                    visited[i][j] = true;
                    dist[i][j] = 0;
                }
            }
        }
    }

    int mx = -1;
    std::pair<int, int> u(-1, -1);

    while (!que.empty()) {
        auto [ni, nj] = que.front();
        que.pop();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; ++k) {
            int i = ni + dx[k];
            int j = nj + dy[k];

            if (i < 0 || j < 0 || i >= n || j >= m) continue;
            if (!gr[i][j]) continue;

            if (dist[i][j] > dist[ni][nj] + 1) {
                dist[i][j] = dist[ni][nj] + 1;
            }

            if (dist[i][j] > mx) {
                mx = dist[i][j];
                u = {i, j};
            }

            if (!visited[i][j]) {
                que.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    mx = -1;
    que.push(u);

    dist = std::vector<std::vector<int>>(n, std::vector<int>(m, inf));
    visited = std::vector<std::vector<bool>>(n, std::vector<bool>(m, false));
    dist[u.first][u.second] = 0;

    while (!que.empty()) {
        auto [ni, nj] = que.front();
        que.pop();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; ++k) {
            int i = ni + dx[k];
            int j = nj + dy[k];

            if (i < 0 || j < 0 || i >= n || j >= m) continue;
            if (!gr[i][j]) continue;

            if (dist[i][j] > dist[ni][nj] + 1) {
                dist[i][j] = dist[ni][nj] + 1;
            }

            if (dist[i][j] > mx) {
                mx = dist[i][j];
            }

            if (!visited[i][j]) {
                que.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    std::cout << mx;

    return 0;
}
