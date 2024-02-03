#include "./NarrowCaster.cpp"
#include <tuple>

struct LambdaFactory {
    LambdaFactory(char in) : _toCount{in}, _tally{} {

    }

    auto MakeLambda() {

        float floatTest = 1.11f;
        void* testVoidPtr = nullptr;
        float* floatPtr = &floatTest;

        auto testTuple = std::tuple<int, float*, std::string, double, void*> {5, floatPtr, "Test", 0.06, testVoidPtr};

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

float Test(int a, float b) {
    return static_cast<float>(a) + b;
}

int main(int argc, char** argv) {

    printf("Arguments: %d\n", argc);

    for (size_t i{}; i < argc; ++i) {
        printf("%zu: %s\n", i, argv[i]);
    }

    Test(5, 5.2f);

    return 0;
}
