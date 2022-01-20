#include <iostream>
using namespace std;
/*
The new specifier consteval creates an immediate function.For an immediate function,
every call to the function must produce a compile - time constant expression.
An immediate function is implicit a constexpr function.

The final assignment gives an error because x is not a constant expression and, therefore, sqr(x) can not  be performed at compile-time

constinit ensures that the variable with static storage duration is initialized at compile-time.
Static storage duration means that the object is allocated when the program begins and deallocated when the
program ends. Objects declared at namespace scope (global objects), objects declared as static or extern have
static storage duration.

*/

consteval int sqr(int n)
{
    return n * n;
}
constexpr int r = sqr(100); // OK
int main()
{
    constexpr int x = 100;
    int r2 = sqr(x); // Error
}