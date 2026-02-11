#include <iostream>
#include <string>

template<class T, T::type n = 0> // Note: non-type template parameter can only take structural literal type, so std::string not allowed
class X;
 
struct S
{
    using type = int;
};

int main() {
    // using T1 = X<S, int, int>; // error: too many arguments
    // using T2 = X<>;            // error: no default argument for first template parameter
    // using T3 = X<1>;           // error: value 1 does not match type-parameter
    // using T4 = X<int>;         // error: substitution failure for second template parameter
    using T5 = X<S>;              // OK
    // using T6 = X<S, int>       // error: type name not allowed
    // using T7 = X<S, "3">;      // error: ‘"3"’ is not a valid template argument for type ‘int’
    using T8 = X<S, 3>;           // OK
    return 0;
}