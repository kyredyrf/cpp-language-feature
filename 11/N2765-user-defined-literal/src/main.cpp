// https://cpprefjp.github.io/lang/cpp11/user_defined_literals.html

#include <cstdio>

unsigned long long operator"" _k(unsigned long long value) {
    return value * 1000;
}

unsigned long long operator"" _M(unsigned long long value) {
    return value * 1000_k;
}

unsigned long long operator"" _G(unsigned long long value) {
    return value * 1000_M;
}

long double operator"" _k(long double value) {
    return value * 1e+3;
}

long double operator"" _M(long double value) {
    return value * 1e+3_k;
}

long double operator"" _G(long double value) {
    return value * 1e+3_M;
}

long double operator"" _m(long double value) {
    return value * 1e-3;
}

long double operator"" _u(long double value) {
    return value * 1e-3_m;
}

long double operator"" _n(long double value) {
    return value * 1e-3_u;
}

int main() {
    auto ik = 123_k;
    auto iM = 123_M;
    auto iG = 123_G;
    printf("ik=%llu\n", ik);
    printf("iM=%llu\n", iM);
    printf("iG=%llu\n", iG);

    auto fk = 1.23_k;
    auto fM = 1.23_M;
    auto fG = 1.23_G;
    auto fm = 1.23_m;
    auto fu = 1.23_u;
    auto fn = 1.23_n;
    printf("fk=%12.1Lf\n", fk);
    printf("fM=%12.1Lf\n", fM);
    printf("fG=%12.1Lf\n", fG);
    printf("fm=%23.12Lf\n", fm);
    printf("fu=%23.12Lf\n", fu);
    printf("fn=%23.12Lf\n", fn);
}
