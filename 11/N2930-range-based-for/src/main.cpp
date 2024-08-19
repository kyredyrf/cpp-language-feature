// https://cpprefjp.github.io/lang/cpp11/range_based_for.html

#include <cstdio>
#include <vector>

int main() {
    std::vector<int> v = { 1, 2, 3 };

    for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); i++) {
        printf("i=%d\n", *i);
    }

    for (auto i : v) {
        printf("i=%d\n", i);
    }
}
