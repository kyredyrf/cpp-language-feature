// https://cpprefjp.github.io/lang/cpp11/initializer_lists.html

#include <cstdio>
#include <vector>

int main() {
    int a[] = { 1, 2, 3 };
    std::vector<int> v1 = { 4, 5, 6 };
    std::vector<int> v2 { 7, 8, 9 };

    for (auto i : a) {
        printf("i=%d\n", i);
    }
    for (auto i : v1) {
        printf("i=%d\n", i);
    }
    for (auto i : v2) {
        printf("i=%d\n", i);
    }
}
