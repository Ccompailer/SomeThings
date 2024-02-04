#include <stdexcept>

template<typename To, typename From>
struct NarrowCaster {
    To Cast(From obj) {
        const auto converted = static_cast<To>(obj);

        const auto backwards = static_cast<From>(converted);

        if (obj != backwards)
            throw std::runtime_error{"Narrowed!"};

        return converted;
    }
};
