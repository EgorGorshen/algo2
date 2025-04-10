template <typename Item>
void insertion_sort(Item first, Item last) {
    for (Item i = first + 1; i != last; ++i) {
        Item j = i;
        auto k = *j;
        while (j != first && *(j - 1) > k) {
            *j = *(j - 1);
            --j;
        }
        *j = k;
    }
}
