#include <vector>
#include <iostream>

template <class T>
class Matrix
{
public:
    Matrix();
    Matrix(unsigned int rows, unsigned int cols);
    Matrix(const Matrix& mat);
    Matrix(unsigned int rows, unsigned int cols, const std::vector<T> & cells);
    //TODO Destructor.

    

    void printMat();

//TODO make private
//private:
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

    //TODO remove
    for (unsigned i = 0; i < _matrix.size(); ++i)
    {
        for (unsigned j = 0 ; j < _numColumns; ++j)
        {
            std::cout << _matrix[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
}

template <class T>
Matrix<T>::Matrix(const Matrix &mat)
{
    _numColumns = mat._numColumns;
    _numRows = mat._numRows;
    _matrix.resize(_numRows);

    for (unsigned i = 0; i < _matrix.size(); ++i)
    {
        _matrix[i].resize(_numColumns);
        for (unsigned j = 0 ; j < _numColumns; ++j)
        {
            _matrix[i][j] = mat._matrix[i][j];
        }
    }
}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols, const std::vector<T> &cells)
{
    _numColumns = cols;
    _numRows = rows;
    _matrix.resize(_numRows);

    for (unsigned i = 0; i < _matrix.size(); ++i)
    {
        _matrix[i].resize(_numColumns);
        for (unsigned j = 0; j < _numColumns; ++j)
        {
            //TODO check if cells doesn't have values in the current index, maybe using exceptions.
            _matrix[i][j] = cells[j + i * _numColumns];
        }
    }
}



template <class T>
void Matrix<T>::printMat()
{
    for (unsigned i = 0; i < _matrix.size(); ++i)
    {
        for (unsigned j = 0 ; j < _numColumns; ++j)
        {
            std::cout << _matrix[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
}