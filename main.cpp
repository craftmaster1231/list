#include <iostream>
#include "List.h"
#include <memory>

int main() {
    List<int> list1(5);
    List<int> list2(2);
    list1 = list2;
    List<int> list3(5);
    list1 = std::move(list3);
    return 0;
}