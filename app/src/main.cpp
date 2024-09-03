#include "lib/dummy.hpp"

#include <cstdio>

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    if (!(35 == dummy::Add(5, 30))) {
        printf("failed to add<int>");
    }
    if (!(35u == dummy::Add(5u, 30u))) {
        printf("failed to add<uint>");
    }
    if (!(35.0f == dummy::Add(5.0f, 30.0f))) {
        printf("failed to add<float>");
    }
    if (!(35.0 == dummy::Add(5.0, 30.0))) {
        printf("failed to add<double>");
    }
    return 0;
}
