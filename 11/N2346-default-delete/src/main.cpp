// https://cpprefjp.github.io/lang/cpp11/defaulted_and_deleted_functions.html

#include <cstdio>

struct X {
    int i;
    X() = default;
    inline X(const X&) = default;
    inline X(X&&) = default;
    inline void operator =(const X&) = delete;
    inline void operator =(const X&&) = delete;
    virtual ~X() = default;
};

int main() {
    X x1 = X();
    x1.i = 123;
    X x2 = x1;
    x2.i++;
    printf("x1.i=%d[%p]\n", x1.i, &x1.i);
    printf("x2.i=%d[%p]\n", x2.i, &x2.i);
}
