#include <iostream>
#include "Matrix.hpp"
#include "Complex.h"

//TODO remove this line.
using namespace std;
int main() {

    try {
        cout << "TESTING MATRIX MULTIPLICATION" << endl;
        cout << "First matrix --->" << endl;
        Matrix<int> m1(2, 4, {1, 1, 1, 1, 1, 1, 1, 1});
        cout << m1;

        cout << endl;
        cout << "Second Matrix --->" << endl;
        Matrix<int> m2(4, 2, {1, 2, 3, 4, 5, 6, 7, 8});
        cout << m2;

        cout << endl;
        cout << "Multiplication result --->" << endl;
        Matrix<int> newMat;
        newMat = m1 * m2;
        cout << newMat;

        cout << endl;
        cout << endl;
        m2(2, 2) = 122;
        cout << m2 << endl;
//
    } catch (const char* msg)
    {
        cerr << msg << endl;
    }
    cout << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}