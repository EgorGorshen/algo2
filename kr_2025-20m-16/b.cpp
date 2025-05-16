#include <iostream>
#include <queue>
#include <vector>

int inf = 1e7;

int main() {
    int n = 0;
    int s = 0;
    int f = 0;
    int c = 0;

    std::cin >> n >> s >> f;
    --s, --f;

    std::vector<std::vector<int> > gr(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int v = 0;
            std::cin >> v;
            if (v) gr[i].push_back(j);
        }
    }

    std::vector<int> dist(n, -1);
    std::queue<int> que;
    que.push(s);
    dist[s] = 0;

    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (int i : gr[node]) {
            if (dist[i] == -1) {
                dist[i] = dist[node] + 1;
                que.push(i);
            }
        }
    }

    std::cout << (dist[f] == -1 ? 0 : dist[f]);
    return 0;
    ;
}
