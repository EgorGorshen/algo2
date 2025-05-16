#include <iostream>
#include <vector>

int inf = 1e7;

struct Node {
    int from_;
    int to_;
    int w;
};

int main(int argc, char *argv[]) {
    int n = 0;
    int m = 0;
    int start = 0;
    int finish = 0;
    std::cin >> n >> m >> start >> finish;
    std::vector<Node> gr;

    for (int i = 0; i < m; ++i) {
        int from_, to_, w;
        std::cin >> from_ >> to_ >> w;
        gr.push_back({from_, to_, w});
        gr.push_back({to_, from_, w});
    }

    std::vector<int> dist(n + 1, inf);
    bool f = true;

    while (f) {
        f = false;
        for (auto [f, t, w] : gr) {
            if (dist[f] != inf && dist[t] > dist[f] + w) {
                dist[t] = dist[f] + w;
                f = true;
            }
        }
    }

    std::cout << (dist[finish] == inf ? -1 : dist[finish]);

    return 0;
}
