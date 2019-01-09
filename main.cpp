#include <iostream>
#include "Matrix.hpp"
#include "Complex.h"

//TODO remove this line.
using namespace std;
int main() {

    cout << "TESTING MATRIX MULTIPLICATION" << endl;
    cout << "First matrix --->" << endl;
    Matrix<int> m1(2,4 ,{1,1,1,1,1,1,1,1});
    m1.printMat();

    cout << endl;
    cout << "Second Matrix --->" << endl;
    Matrix<int> m2(4,2, {1,1,1,1,0,0,0,0});
    m2.printMat();

    cout << endl;
    cout << "Multiplication result --->" << endl;
    Matrix<int> newMat;
    newMat = m1*m2;
    newMat.printMat();


    std::cout << "Hello, World!" << std::endl;
    return 0;
}