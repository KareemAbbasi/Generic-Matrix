#include <iostream>
#include "Matrix.hpp"
#include "Complex.h"

int main() {
    Matrix<int> nM(3, 6);

    std::cout << "1 done" << std::endl;

    Matrix<int> ns(nM);
    std::cout << "2 done" << std::endl;
    nM._matrix.at(1).at(2) = 3;
    nM.printMat();
    std::cout << "" << std::endl;
    ns.printMat();

    std::cout << "" << std::endl;
    std::cout << "NEW MATRIX FROM VECTOR" << std::endl;
    std::cout << "" << std::endl;

    std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    Matrix<int> matVect(3, 5, v);
    matVect.printMat();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}