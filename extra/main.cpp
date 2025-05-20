#include <cmath>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

int gcd(int a, int b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    int n = 0;
    std::cin >> n;

    std::vector<std::pair<int, int>> pts(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> pts[i].first >> pts[i].second;
    }

    int64_t twice_area = 0;
    int64_t boundary_points = 0;

    for (int i = 0; i < n; ++i) {
        std::pair<int, int> a = pts[i];
        std::pair<int, int> b = pts[(i + 1) % n];

        // Шнуровка: удвоенная площадь
        twice_area += 1LL * (a.first * b.second - b.first * a.second);

        // GCD на границе
        int dx = std::abs(b.first - a.first);
        int dy = std::abs(b.second - a.second);
        boundary_points += gcd(dx, dy);
    }

    int64_t area = std::abs(twice_area) / 2;
    int64_t inside_points = area - boundary_points / 2 + 1;

    std::cout << inside_points << "\n";
    return 0;
}
