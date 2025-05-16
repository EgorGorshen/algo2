#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n = 0;
    int m = 0;

    std::cin >> n >> m;

    std::vector<std::vector<int>> gr(n);

    for (int i = 0; i < m; ++i) {
        int from_ = 0;
        int to_ = 0;
        std::cin >> from_ >> to_;
        --from_, --to_;

        gr[from_].push_back(to_);
        gr[to_].push_back(from_);
    }

    std::vector<int> colors(n, -1);

    for (int start = 0; start < n; ++start) {
        if (colors[start] != -1) continue;

        std::queue<int> que;
        que.push(start);
        colors[start] = 0;

        while (!que.empty()) {
            int node = que.front();
            que.pop();

            for (int i : gr[node]) {
                if (colors[i] == -1) {
                    colors[i] = 1 - colors[node];
                    que.push(i);
                } else if (colors[i] == colors[node]) {
                    std::cout << "NO";
                    return 0;
                }
            }
        }
    }

    std::cout << "YES";

    return 0;
}
