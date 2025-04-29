#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n = 0;
    int m = 0;
    int v = 0;

    std::cin >> n >> m >> v;

    --v;

    std::vector<std::vector<int> > gr(n);
    std::vector<int> wave;
    std::vector<bool> visited(n);
    std::queue<int> que;

    int from_ = 0;
    int to_ = 0;

    for (int i = 0; i < m; ++i) {
        std::cin >> from_ >> to_;
        --from_, --to_;
        gr[from_].push_back(to_);
        gr[to_].push_back(from_);
    }

    visited[v] = true;
    que.push(v);

    while (!que.empty()) {
        int node = que.front();
        wave.push_back(node);
        que.pop();

        for (auto i : gr[node]) {
            if (visited[i]) continue;

            visited[i] = true;
            que.push(i);
        }
    }

    std::cout << wave.size() << std::endl;

    for (int node : wave) {
        std::cout << node + 1 << ' ';
    }

    return 0;
}
