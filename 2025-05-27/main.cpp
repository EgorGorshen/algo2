#include <iostream>
#include <utility>
#include <vector>

#include "SectionTree.cpp"

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) std::cin >> arr[i];
    SectionTree tree(std::move(arr));

    char cmd;
    while (std::cin >> cmd) {
        if (cmd == '?') {
            int l = 0;
            int r = 0;
            std::cin >> l >> r;
            std::cout << tree.get(l, r) << std::endl;
        } else if (cmd == '!') {
            int ind = 0;
            int value = 0;
            std::cin >> ind >> value;
            tree.update(ind, value);
        } else if (cmd == '>') {
            tree.debug();
        }
    }
}
