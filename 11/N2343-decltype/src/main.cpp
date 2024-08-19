// https://cpprefjp.github.io/lang/cpp11/decltype.html

#include <cstdio>
#include <typeinfo>

int main() {
    auto i = 0;
    decltype(i) i2 = i;
    decltype(i)* i3 = &i2;
    decltype((i)) i4 = *i3;
    decltype(i + 0.) d;
    printf("i=%s\n", typeid(i).name());
    printf("i2=%s\n", typeid(i2).name());
    printf("i3=%s\n", typeid(i3).name());
    printf("i4=%s\n", typeid(i4).name());
    printf("d=%s\n", typeid(d).name());
}
