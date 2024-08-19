// https://cpprefjp.github.io/lang/cpp11/rvalue_ref_and_move_semantics.html

#include <cstdio>
#include <string>

int main() {
    auto s1 = std::string("hoge");
    printf("s1 = [%p] \"%s\"(%zu)\n", s1.c_str(), s1.c_str(), s1.length());

    auto s2 = std::move(s1);
    printf("s1 = [%p] \"%s\"(%zu)\n", s1.c_str(), s1.c_str(), s1.length());
    printf("s2 = [%p] \"%s\"(%zu)\n", s2.c_str(), s2.c_str(), s2.length());
}
