#include <cstddef>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    int n = 0;
    int m = 0;

    std::cin >> n >> m;

    std::vector<std::vector<int> > gr(n, std::vector<int>(m, 0));
    std::vector<std::vector<int> > dist(n, std::vector<int>(m, -1));
    std::queue<std::pair<int, int> > que;
    std::vector<std::vector<bool> > visited(n, std::vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> gr[i][j];
        }
    }

    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;

    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;
    x1--, y1--;
    --x2, --y2;

    que.push({x1, y1});
    dist[x1][y1] = 0;

    while (!que.empty()) {
        auto [ni, nj] = que.front();
        que.pop();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; ++k) {
            int i = ni + dx[k];
            int j = nj + dy[k];
            if (i < 0 || i >= n || j < 0 || j >= m) continue;
            if (gr[i][j] == 1) continue;
            if (!visited[i][j]) {
                visited[i][j] = true;
                dist[i][j] = dist[ni][nj] + 1;
                que.push({i, j});
            }
        }
    }

    if (!visited[x2][y2])
        std::cout << -1;
    else
        std::cout << dist[x2][y2];

    return 0;
}
