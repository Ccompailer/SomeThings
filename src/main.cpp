#include "./NarrowCaster.cpp"
#include <iostream>

template<typename From>
using ShortCaster = NarrowCaster<short, From>;
float Test(int, float);

int main() {
    int five = 5;

    using TestPointer = float (*) (int, float);

    TestPointer pointer = Test;
    ShortCaster<int> caster;
    auto testCast = caster.Cast(five);
    std::cout << typeid(testCast).name() << "\n";
    std::cout << pointer(5, 5.1f);
    return 0;
}

float Test(int a, float b) {
    return static_cast<float>(a) + b;
}
