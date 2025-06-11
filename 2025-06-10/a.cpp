#include <iostream>
#include <vector>
int main(int argc, char *argv[]) {
    int n = 0;
    std::cin >> n;

    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i) std::cin >> parent[i];

    int m = 0;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        int n1, n2;
        std::cin >> n1 >> n2;

        // NOTE: решение здесь
    }

    return 0;
}
