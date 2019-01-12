#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "Complex.h"

template <class T>
class Matrix
{
public:

    class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
        friend class Matrix;
    public:
//        const_iterator(): vec(_matrix), outerIterIndex(0), innerIterIndex(0) {};
        const_iterator() = default;
        const_iterator(std::vector<std::vector<T>> *vect, std::size_t outIndex, std::size_t inIndex):
            vec(vect),
            outerIterIndex(outIndex),
            innerIterIndex(inIndex)
        {};

        const const_iterator& operator++();
        const const_iterator& operator--();
        const const_iterator operator++(int);
        const const_iterator operator--(int);
        const bool operator==(const const_iterator& other);
        const bool operator!=(const const_iterator& other);
        const T& operator*() const;
        T& operator*();
        const T& operator->() const;
        T& operator->();




    private:
        std::vector<std::vector<T>> *vec = nullptr;
        std::size_t outerIterIndex = 0;
        std::size_t innerIterIndex = 0;
    };

    Matrix();
    Matrix(unsigned int rows, unsigned int cols);
    Matrix(const Matrix& mat);
    Matrix(unsigned int rows, unsigned int cols, const std::vector<T> & cells);
    //TODO Destructor.

    Matrix<T>& operator= (const Matrix<T> mat);
    template <class U> friend Matrix<U> operator+(const Matrix<U> m1, const Matrix<U> m2);
    template <class U> friend Matrix<U> operator-(const Matrix<U> m1, const Matrix<U> m2);
    template <class U> friend Matrix<U> operator*(const Matrix<U> m1, const Matrix<U> m2);
    static T multiplyVector(const std::vector<T> v1, const std::vector<T> v2);

    template <class U> friend bool operator==(const Matrix<U> m1, const Matrix<U> m2);
    template <class U> friend bool operator!=(const Matrix<U> m1, const Matrix<U> m2);


    //TODO test these functions.
    Matrix<T> trans();
//    template<> Matrix<Complex> trans();

    bool isSquareMatrix();
    //TODO create a const and a non-const version of this method.
    T& operator()(unsigned int row, unsigned int col);
    const T& operator()(unsigned int row, unsigned int col) const;

    const_iterator begin();
    const_iterator end();

    unsigned int rows();
    unsigned int cols();

    template <class U> friend std::ostream& operator<<(std::ostream &out, Matrix<U> m1);

    template <class U> friend Matrix<U> findTranspose(Matrix<U> mat);

//TODO make private
//private:
    unsigned int _numColumns, _numRows;
    std::vector<std::vector <T>> _matrix;

};

/*
 * Iterator Class
 */

//template <class T>
//Matrix<T>::const_iterator::const_iterator()
//{
//
//}

template <class T>
const typename Matrix<T>::const_iterator& Matrix<T>::const_iterator::operator++()
{
    if (innerIterIndex + 1 < (*vec)[outerIterIndex].size())
    {
        ++innerIterIndex;
    }
    else
    {
        do
        {
            ++outerIterIndex;
        } while (outerIterIndex < (*vec).size() && (*vec)[outerIterIndex].empty());
        innerIterIndex = 0;
    }
    return *this;
}

template <class T>
const typename Matrix<T>::const_iterator& Matrix<T>::const_iterator::operator--()
{
    if (innerIterIndex > 0)
    {
        --innerIterIndex;
    }
    else
    {
        do
        {
            --outerIterIndex;
        } while ((*vec)[outerIterIndex].empty());
        innerIterIndex = (*vec)[outerIterIndex].size() - 1;
    }
}

template <class T>
const typename Matrix<T>::const_iterator Matrix<T>::const_iterator::operator++(int)
{
    T retVal = *this;
    ++(*this);
    return retVal;
}

template <class T>
const typename Matrix<T>::const_iterator Matrix<T>::const_iterator::operator--(int)
{
    T retVal = *this;
    --(*this);
    return retVal;
}

template <class T>
const bool Matrix<T>::const_iterator::operator==(const Matrix<T>::const_iterator &other)
{
    return other.vec == vec && other.outerIterIndex == outerIterIndex && other.innerIterIndex == innerIterIndex;
}

template <class T>
const bool Matrix<T>::const_iterator::operator!=(const Matrix<T>::const_iterator &other)
{
    return !(*this == other);
}

template <class T>
const T& Matrix<T>::const_iterator::operator*() const
{
    return *this;
}

template <class T>
T& Matrix<T>::const_iterator::operator*()
{
    return (*vec)[outerIterIndex][innerIterIndex];
}

template <class T>
const T& Matrix<T>::const_iterator::operator->() const
{
    return *this;
}

template <class T>
T& Matrix<T>::const_iterator::operator->()
{
    return *this;
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

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
Matrix<T>& Matrix<T>::operator=(const Matrix<T> mat)
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

template <class U>
Matrix<U> operator-(const Matrix<U> m1, const Matrix<U> m2)
{
    if (m1._numColumns != m2._numColumns || m1._numRows != m2._numRows)
    {
        throw "The two matrices don't have the same size!";
    }

    Matrix<U> newMatrix(m1._numRows, m1._numColumns);
    for (unsigned i = 0; i < m1._numRows; ++i)
    {
        for (unsigned j = 0; j < m1._numColumns; ++j)
        {
            //TODO change to use operator()
            newMatrix._matrix[i][j] = m1._matrix[i][j] - m2._matrix[i][j];
        }
    }
    return newMatrix;
}

template <class U>
Matrix<U> operator*(const Matrix<U> m1, const Matrix<U> m2)
{
    //TODO exception m1 cols = m2 rows
    Matrix<U> newMatrix(m1._numRows, m2._numColumns);
    Matrix<U> transposedMat = findTranspose(m2);

    for (unsigned i = 0; i < m1._numRows; ++i)
    {
        for (unsigned j = 0; j < m2._numColumns; ++j)
        {
            newMatrix._matrix[i][j] = Matrix<U>::multiplyVector(m1._matrix[i], transposedMat._matrix[j]);
        }
    }
    return newMatrix;
}

template <class T>
T Matrix<T>::multiplyVector(const std::vector<T> v1, const std::vector<T> v2)
{
    if (v1.size() != v2.size())
    {
        throw "Not same size";
    }

    T result;

    for (int i = 0; i < v1.size(); ++i)
    {
        result += v1[i] * v2[i];
    }
    return result;
}

template <class U>
bool operator==(const Matrix<U> m1, const Matrix<U> m2)
{
    if (m1._numColumns != m2._numColumns || m1._numRows != m2._numRows)
    {
        return false;
    }
    else
    {
        for (unsigned i = 0; i < m1._numColumns; ++i)
        {
            for (unsigned j = 0; j < m1._numRows; ++j)
            {
                if (m1._matrix[i][j] != m2._matrix[i][j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

template <class U>
bool operator!=(const Matrix<U> m1, const Matrix<U> m2)
{
    return !(m1 == m2);
}

template <class T>
Matrix<T> Matrix<T>::trans()
{
    if (_numRows != _numColumns)
    {
        throw "Matrix is not square";
    }
    else
    {
        return findTranspose(*this);
    }
}

template <>
Matrix<Complex> Matrix<Complex>::trans()
{
    if (_numRows != _numColumns)
    {
        throw "Matrix is not square";
    }
    Matrix<Complex> newMatrix;
    newMatrix = findTranspose(*this);

    for (unsigned i = 0; i < newMatrix._numRows; ++i)
    {
        for (unsigned j = 0; j < newMatrix._numColumns; ++j)
        {
            newMatrix._matrix[i][j] = newMatrix._matrix[i][j].conj();
        }
    }
    return newMatrix;
}

template <class T>
bool Matrix<T>::isSquareMatrix()
{
    return this->_numRows == this->_numColumns;
}

template <class U>
std::ostream& operator<<(std::ostream &out, Matrix<U> m1)
{
    for (unsigned i = 0; i < m1._matrix.size(); ++i)
    {
        for (unsigned j = 0 ; j < m1._numColumns; ++j)
        {
            out << m1._matrix[i][j] << "\t";
        }
        if (i < m1._numRows - 1)
        {
            out << "" << std::endl;
        }
    }
    return out;
}

template <class T>
T& Matrix<T>::operator()(unsigned int row, unsigned int col)
{
    if (row > this->_numRows || row <= 0 || col > this->_numColumns || col <= 0)
    {
        throw "Indexes out of range";
    }
    return this->_matrix[row - 1][col - 1];
}

template <class T>
const T& Matrix<T>::operator()(unsigned int row, unsigned int col) const
{
    if (row > this->_numRows || row <= 0 || col > this->_numColumns || col <= 0)
    {
        throw "Indexes out of range";
    }
    return this->_matrix[row - 1][col - 1];
}

template <class T>
typename Matrix<T>::const_iterator Matrix<T>::begin()
{
    return const_iterator(&_matrix, 0, 0);
}

template <class T>
typename Matrix<T>::const_iterator Matrix<T>::end()
{
    return const_iterator(&_matrix, _matrix.size(), 0);
}

template <class T>
unsigned int Matrix<T>::rows()
{
    return _numRows;
}

template <class T>
unsigned int Matrix<T>::cols()
{
    return _numColumns;
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