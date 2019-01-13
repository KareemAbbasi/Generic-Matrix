#include <iostream>
//#include "Matrix.hpp"
#include "Complex.h"''

//TODO remove this line.
using namespace std;

template <class T>
void foo(T t)
{
    cout << "T function " << t << endl;
}

template <>
void foo<int>(int t)
{
    cout << "int funtcion " << t << endl;
}

//int main() {
//
//    cout << endl;
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}