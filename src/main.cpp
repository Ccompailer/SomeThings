#include "./NarrowCaster.cpp"
#include <iostream>

struct LambdaFactory {
    LambdaFactory(char in) : _toCount{in}, _tally{} {

    }

    auto MakeLambda() {
        return [this](const char* str) {
            size_t index{}, result{};

            while (str[index]) {
                if (str[index] == _toCount)
                    ++result;
                ++index;
            }

            _tally += result;
            return result;
        };
    }

private:
    const char _toCount;
    size_t _tally;
};

int main() {
    LambdaFactory lambda {'s'};
    auto lamb = lambda.MakeLambda();
    std::cout << lamb("Tests");
    return 0;
}

float Test(int a, float b) {
    return static_cast<float>(a) + b;
}
