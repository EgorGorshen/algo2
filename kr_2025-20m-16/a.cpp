#include <iostream>
#include <vector>
int main() {
    int n = 0;
    int c = 0;
    std::cin >> n;

    std::vector<std::vector<int> > gr(n, std::vector<int>(n, 0));
    std::vector<int> color(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> gr[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> color[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (gr[i][j] && color[i] != color[j]) ++c;
        }
    }

    std::cout << c / 2;

    return 0;
}
