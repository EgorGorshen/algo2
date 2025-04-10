#include <iostream>
#include <vector>

template <typename Item, typename T>
Item linear_sort(T obj, Item first, Item last) {
    for (Item i = first; i != last; ++i) {
        if (*i == obj) {
            return i;
        }
    }
    return last;
}

int main(int argc, char *argv[]) {
    std::vector<int> v = {1, 5, 2, 7, 1, 45, 8, 1};
    int val = 1000;
    std::cout << *linear_sort(val, v.begin(), v.end());
    return 0;
}
