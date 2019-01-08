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

    Matrix& operator= (const Matrix mat);
    template <class U> friend Matrix<U> operator+(const Matrix<U> m1, const Matrix<U> m2);

    void printMat();
    template <class U> friend Matrix<U> findTranspose(Matrix<U> mat);

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
Matrix<T>& Matrix<T>::operator=(const Matrix mat)
{
    this->_numColumns = mat._numColumns;
    this->_numRows = mat._numRows;
    this->_matrix.resize(_numRows);

    for (unsigned i = 0; i < this->_matrix.size(); ++i)
    {
        this->_matrix[i].resize(_numColumns);
        for (unsigned j = 0 ; j < this->_numColumns; ++j)
        {
            this->_matrix[i][j] = mat._matrix[i][j];
        }
    }
    return *this;
}

template <class U>
Matrix<U> operator+(const Matrix<U> m1, const Matrix<U> m2)
{
    //TODO if going to do the bonus, add the bool value
    if (m1._numColumns != m2._numColumns || m1._numRows != m2._numRows)
    {
        throw "The two matrices don't have the same size!";
    }

    Matrix<U> newMatrix(m1._numRows, m1._numColumns);

    for (unsigned i = 0 ; i < m1._numRows; ++i)
    {
        for (unsigned j = 0; j < m1._numColumns; ++j)
        {
            //TODO change to use operator()
            newMatrix._matrix[i][j] = m1._matrix[i][j] + m2._matrix[i][j];
        }
    }
    return newMatrix;
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

template <class U>
Matrix<U> findTranspose(Matrix<U> mat)
{
    Matrix<U> transposedMat(mat._numColumns, mat._numRows);
    for (unsigned i = 0; i < mat._numRows; ++i)
    {
        for (unsigned j = 0; j < mat._numColumns; ++j)
        {
            transposedMat._matrix[j][i] = mat._matrix[i][j];
        }
    }
    return transposedMat;
}