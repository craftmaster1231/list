#include <iostream>
#include "List.h"


int main() {
    List<int> list1(5);
    List<int> list2(2);
    list1 = list2;
    return 0;
}