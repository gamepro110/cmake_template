# pragma once

#include <concepts>

namespace dummy
{
    template<typename T>
    concept numeral = std::same_as<T, int> || std::same_as<T, unsigned int> || std::same_as<T, float> || std::same_as<T, double>;

    template<numeral NUM>
    static NUM Add(NUM a, NUM b) {
        return a + b;
    }
} // namespace Dummy
