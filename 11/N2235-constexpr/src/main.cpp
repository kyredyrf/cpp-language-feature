// https://cpprefjp.github.io/lang/cpp11/constexpr.html

#include <cassert>
#include <cstdio>

constexpr int add(int a, int b) {
    return a + b;
}

int main() {
    constexpr auto i = 1;

    constexpr auto runtime_result = add(i, 2);
    assert(runtime_result == 3);
    printf("%d\n", runtime_result);

    constexpr auto compile_time_result = add(i, 3);
    static_assert(compile_time_result == 4, "result must be 4");
    printf("%d\n", compile_time_result);
}
