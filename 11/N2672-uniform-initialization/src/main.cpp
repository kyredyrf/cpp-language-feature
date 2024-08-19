// https://cpprefjp.github.io/lang/cpp11/uniform_initialization.html

#include <string>

struct X {
    int i;
    double d;
    std::string s;
    X(int i, double d, std::string s) {
        this->i = i;
        this->d = d;
        this->s = s;
    }
};

X get() {
    return { 123, 3.14, "hoge" };
}

int main() {
    X x = get();
    printf("%d\n", x.i);
    printf("%f\n", x.d);
    printf("%s\n", x.s.c_str());
}
