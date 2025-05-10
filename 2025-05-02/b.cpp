#include <iostream>
#include <vector>

int inf = 1e9;

int main() {
    int n = 0;
    int start = 0;
    int finish = 0;

    std::cin >> n >> start >> finish;
    --start, --finish;

    std::vector<std::vector<int> > gr(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> gr[i][j];
        }
    }
    std::vector<int> dist(n, inf);
    dist[start] = 0;
    std::vector<int> used(n, false);

    while (true) {
        int cur = -1;

        for (int i = 0; i < n; ++i) {
            if (used[i] || dist[i] == inf) continue;

            if ((cur == -1) || (dist[i] < dist[cur])) {
                cur = i;
            }
        }

        if (cur == -1) break;

        for (int to = 0; to < n; ++to) {
            if (gr[cur][to] == -1 || cur == to) continue;
            int w = gr[cur][to];
            if (dist[to] > dist[cur] + w) {
                dist[to] = dist[cur] + w;
            }
        }
        used[cur] = true;
    }

    std::cout << (dist[finish] == inf ? -1 : dist[finish]);

    return 0;
}
