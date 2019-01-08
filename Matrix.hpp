#include <vector>
#include <iostream>

template <class T>
class Matrix
{
public:
    Matrix();
    Matrix(unsigned int rows, unsigned int cols);

private:
    unsigned int _numColumns, _numRows;
    std::vector<std::vector <T>> _matrix;

};

template <class T>
Matrix<T>::Matrix()
{
    _numRows = _numColumns = 1;
    std::vector<T> row;
    row.resize(1);
    _matrix.push_back(row);
//    _matrix.resize(1);
    //TODO remove this shit.
    std::cout << _matrix.size() << _matrix.at(0).size() <<  std::endl;
    std::cout << _matrix.at(0).at(0) << std::endl;
}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols)
{
    _numRows = rows;
    _numColumns = cols;
    _matrix.resize(_numRows);

    for (unsigned i = 0; i < _matrix.size(); ++i)
    {
        _matrix[i].resize(_numColumns);
    }

    for (unsigned i = 0; i < _matrix.size(); ++i)
    {
        for (unsigned j = 0 ; j < _numColumns; ++j)
        {
            std::cout << _matrix[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }

}