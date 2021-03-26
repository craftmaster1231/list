#include "List.h"
#include <string>
#include <list>

int main() {
    //auto&& ref = std::move(a);
    List<int> l1(5);
    l1 = std::move(l1);
}