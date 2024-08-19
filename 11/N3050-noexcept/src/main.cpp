// https://cpprefjp.github.io/lang/cpp11/noexcept.html

int main() {
    auto plus = [](int a, int b) noexcept { return a + b; };
    static_assert(noexcept(plus(1, 2)), "plus function never throw exception");

    auto get = [](int* p) { return *p; };
    auto i = 0;
    static_assert(noexcept(get(&i)), "get function never throw exception");
}
