// https://cpprefjp.github.io/lang/cpp11/auto.html

#include <cstdio>
#include <memory>

int main() {
    auto i = 0;
    const auto ci = 0;
    auto& ri = i;
    auto pi = &i;
    auto ppi = &pi;
    auto s = "";
    auto p = std::make_pair(0L, 0.F);
    auto q = std::make_shared<int>(0);
    auto z = { 1., 2., 3., };
    auto f = []{};
    printf("i=%s\n", typeid(i).name());
    printf("ci=%s\n", typeid(ci).name());
    printf("ri=%s\n", typeid(ri).name());
    printf("pi=%s\n", typeid(pi).name());
    printf("ppi=%s\n", typeid(ppi).name());
    printf("s=%s\n", typeid(s).name());
    printf("p=%s\n", typeid(p).name());
    printf("q=%s\n", typeid(q).name());
    printf("z=%s\n", typeid(z).name());
    printf("f=%s\n", typeid(f).name());
    printf("main=%s\n", typeid(main).name());
    printf("printf=%s\n", typeid(printf).name());
}
