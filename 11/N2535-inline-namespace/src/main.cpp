// https://cpprefjp.github.io/lang/cpp11/inline_namespaces.html

#include <cstdio>

namespace A {
    namespace B {
        void func() { printf("%s\n", __func__); }
    }

    inline namespace C {
        void func() { printf("%s\n", __func__); }
    }
}

namespace D {
    void func() { printf("%s\n", __func__); }

    namespace E {
        void func() { printf("%s\n", __func__); }
    }
}

namespace F {
    void func() { printf("%s\n", __func__); }

    inline namespace G {
        void func() { printf("%s\n", __func__); }
    }
}

int main() {
    A::func();
    A::B::func();
    A::C::func();

    D::func();
    D::E::func();

    // error: call to 'func' is ambiguous
    // F::func();
    F::G::func();
}
