// https://cpprefjp.github.io/lang/cpp11/lambda_expressions.html

#include <cstdio>

int main() {
    auto plus = [](int a, int b) { return a + b; };
    auto a = 1;
    auto b = 2;
    printf("%d+%d=%d\n", a, b, plus(a, b));

    // OK
    auto rc = [&]() { a++; };

    // error C3491: 'a': 変更できないラムダではコピーによるキャプチャは変更できません
    // https://www.google.com/search?q=error+C3491
    // auto cc = [=]() { a++; };
}
