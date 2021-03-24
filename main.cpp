#include "List.h"

int main() {
    List<int> list1(5);
    List<int> list2(2);
    list2 = std::move(list1);
    return 0;
}