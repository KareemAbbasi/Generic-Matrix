#include <iostream>
#include "Matrix.hpp"
#include "Complex.h"

int main() {

    std::cout << "TEST TRANSPOSE" << std::endl;
    Matrix<int> m1(2,4, {1,2,3,4,5,6,7,8});
    std::cout << "The original matrix" << std::endl;
    m1.printMat();
    std::cout << "Transposed:" << std::endl;
    Matrix<int> nMat;
    nMat = findTranspose(m1);
    nMat.printMat();



    std::cout << "Hello, World!" << std::endl;
    return 0;
}