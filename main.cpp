#include <iostream>
#include "List.h"


int main() {

    List<int> list1(5);
    List<int> list2(6);
    list1 = list2;
    List<int> list3 = list1;

    return 0;
}