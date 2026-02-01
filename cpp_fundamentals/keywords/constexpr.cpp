#include <iostream>

// constexpr meaning roughly to be executed at compile time, This is used primarily 
// to specify constants, to allow placement of data in memory where it is unlikely to be 
// corrupted, and for performance.

// The constexpr specifier declares that it is possible to evaluate the value of the 
// entities at compile time. Such entities can then be used where only compile time 
// constant expressions are allowed

// arr[x]  // OK: only if x is a constexpr
// switch (n) {
//     case x   // OK: only if x is constexpr
// }


// Examples
double square(int n) {   // runs only at runtime
    return n*n;
}

constexpr double square_c(int n) {  // may run at compile time or runtime depending on arg
    return n*n;
}

int main() {

    const int dmv = 17;    // dmv is constant
    int var = 17;          // var is not a constant and therefore suscepible to changes

    // constexpr double max1 = square(dmv);   // ERROR: because rvalue is a non-constexpr expression (its double)
    // constexpr double max2 = square_c(var); // ERROR: the value of var can't be used as a constant
    constexpr double max3 = square_c(dmv);    // OK: 

    // now since we don't want different flavours of same functions this is legal
    double max4 = square_c(var);  // OK: square_c can accept variables with runtime values

    // constexpr std::string str = "hello";  // ERROR: std::string is not a literal type

    return 0;
}

// Reference: https://en.cppreference.com/w/cpp/language/constexpr.html