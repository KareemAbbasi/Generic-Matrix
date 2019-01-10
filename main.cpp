#include <iostream>
#include "Matrix.hpp"
#include "Complex.h"

//TODO remove this line.
using namespace std;
int main() {

    Matrix<int> mat(2, 3, {1, 2, 3, 4, 5, 6});

    for (auto i = mat.begin(); i != mat.end(); i++)
    {
        cout << i << endl;
    }


    cout << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}