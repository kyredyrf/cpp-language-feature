#include <cstdio>

int main() {
    printf("hello\n");
    printf("%ld(%lx)\n", (long)__cplusplus, (long)__cplusplus);
#ifdef _MSVC_LANG
    printf("%d(%x)\n", _MSVC_LANG, _MSVC_LANG);
#endif
}
