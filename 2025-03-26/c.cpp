template <typename Item, typename T>
Item bin_search(Item begin, Item end, const T& target) {
    while (begin < end) {
        Item mid = begin + (end - begin) / 2;

        if (*mid == target) {
            return mid;
        } else if (*mid < target) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }
    return end;
}
