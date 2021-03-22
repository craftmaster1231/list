#include <iostream>
#include "List.h"


int main() {
    List<int> list1(5);
    List<int> list2(10);
    list2 = list1;
    return 0;
}