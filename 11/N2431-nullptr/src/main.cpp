// https://cpprefjp.github.io/lang/cpp11/nullptr.html

#include <cstdio>

int main() {
    int* p = nullptr;
    if (p == 0) {
        printf("p == 0\n");
    }
    if (p == NULL) {
        printf("p == NULL\n");
    }
    if (p == nullptr) {
        printf("p == nullptr\n");
    }
}
