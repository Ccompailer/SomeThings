#include "./NarrowCaster.cpp"
#include <iostream>

template<typename From>
using ShortCaster = NarrowCaster<short, From>;

int main() {
    int five = 5;
    ShortCaster<int> caster;
    auto testCast = caster.Cast(five);
    std::cout << typeid(testCast).name();
    return 0;
}
