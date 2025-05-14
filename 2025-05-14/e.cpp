#include <algorithm>
#include <iostream>
#include <vector>

int inf = 1e9;

int main() {
    int n = 0;
    std::cin >> n;

    std::vector<std::vector<int> > gr(n, std::vector<int>(n, inf));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> gr[i][j];
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (gr[i][j] < inf && gr[k][j] < inf && gr[k][k] < 0)
                    gr[i][j] =
                        std::min(std::min(gr[i][j], gr[i][k] + gr[k][j]), -inf);
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (gr[i][j] == inf)
    //             std::cout << 0;
    //         else {
    //             bool f = true;
    //             for (int k = 0; k < n; k++) {
    //                 if (gr[i][k] < inf && gr[k][j] < inf && gr[k][k] < 0) {
    //                     std::cout << 2;
    //                     f = false;
    //                     break;
    //                 }
    //             }
    //             if (f) std::cout << 1;
    //         }
    //         std::cout << ' ';
    //     }
    //     std::cout << std::endl;
    // }

    for (auto line : gr) {
        for (int i : line) {
            std::cout << i << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
