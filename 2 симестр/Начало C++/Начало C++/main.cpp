#include <iostream>
#include <cmath>

int foo(int a, int b);

int main()
{
    std::cout << "Hello World!" << std::endl;
    int a = 0;
    std::cin >> a;
    int b = 0;
    std::cin >> b;
    std::cout << foo(a,b) << std::endl;
    return 0;
}

int foo(int a, int b)
{
    return a + b + 1;
}