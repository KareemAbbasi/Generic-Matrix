#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "Complex.h"
#include <stdexcept>
#include <exception>

/*
 * //////////////////
 *     EXCEPTIONS
 * //////////////////
 */

/**
 * An exception for when an operation can't be completed because of the size difference between
 * the matrices.
 */
class DifferentSizeException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "The two matrices don't have the same size!";
    }
} diffSizeEx;

/**
 * An exception for when an operation requires a square matrix and the current
 * matrix is not square.
 */
class NotSquareException: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Matrix is not square!";
    }
} notSquareEx;


/*
 * ///////////////////////
 *     GENERIC MATRIX
 * ///////////////////////
 */

/**
 * A class that implements a generic matrix where its value are of type T
 * @tparam T
 */
template <class T>
class Matrix
{
public:


    /*
     * ///////////////////////
     *        ITERATOR
     * ///////////////////////
     */
    /**
     * The Iterator class for the Matrix. Inherits from the bidirectional_iterator
     */
    class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
    {
        friend class Matrix;
    public:
        /**
         * Default constructor for the iterator
         */
        const_iterator() = default;
        /**
         * Constructor for the iterator receives a 2d vector and two indexes.
         * @param vect 2d vectors which represents the matrix.
         * @param outIndex The current index of the outer vector.
         * @param inIndex The current index of the inner vector.
         */
        const_iterator(std::vector<std::vector<T>> *vect, std::size_t outIndex, std::size_t inIndex):
            vec(vect),
            outerIterIndex(outIndex),
            innerIterIndex(inIndex)
        {};

        /**
         * Returns the next value in the iterator.
         * @return
         */
        const const_iterator& operator++();


        /**
         * Returns the previous value in the iterator.
         * @return
         */
        const const_iterator& operator--();

        /**
         * Returns the next value in the iterator.
         * @return
         */
        const const_iterator operator++(int);

        /**
         * Returns the previous value in the iterator.
         * @return
         */
        const const_iterator operator--(int);

        /**
         * Compares two values of the iterator.
         * @param other the other value.
         * @return True if equal, false otherwise.
         */
        bool operator==(const const_iterator& other);

        /**
         * Compares two values of the iterator.
         * @param other the other value.
         * @return True if not equal, false otherwise.
         */
        bool operator!=(const const_iterator& other);

        /**
         * Access the value stored in iterator.
         * @return
         */
        const T& operator*() const;

        /**
         * Access the value stored in iterator.
         * @return
         */
        T& operator*();

        /**
         * Access the value stored in iterator.
         * @return
         */
        const T& operator->() const;

        /**
         * Access the value stored in iterator.
         * @return
         */
        T& operator->();

    private:
        /**
         * The 2d vector that represents the matrix.
         */
        std::vector<std::vector<T>> *vec = nullptr;

        /**
         * The index of the outer vector.
         */
        std::size_t outerIterIndex = 0;

        /**
         * The index of the inner index.
         */
        std::size_t innerIterIndex = 0;
    };


    /**
     * Default constructor for the matrix.
     */
    Matrix();

    /**
     * Constructor that receives a number of rows and a number of cols and creates a matrix
     * with these sizes that has the default type of the Matrix type.
     * @param rows The number of rows.
     * @param cols The number of cols.
     */
    Matrix(unsigned int rows, unsigned int cols);

    /**
     * A copy constructor which creates a new matrix with the values of a given matrix.
     * @param mat The matrix with the values we want to copy.
     */
    Matrix(const Matrix& mat);

    /**
     * A constructor which receives the number of rows, number of cols and a vector which contains
     * all the values of the matrix.
     * @param rows The number of rows.
     * @param cols The number of cols.
     * @param cells The vector that conatains the values.
     */
    Matrix(unsigned int rows, unsigned int cols, const std::vector<T> & cells);

    //TODO check if destructor ok.
    /**
     * Destructor of the Matrix.
     */
    ~Matrix() = default;

    /**
     * Copy operator, changes the values of the current matrix to the values of the given matrix.
     * @param mat The given matrix
     * @return the changes matrix.
     */
    Matrix<T>& operator= (const Matrix<T> mat);

    /**
     * Add the values of two given matrices.
     * @tparam U The type of the values of the matrices.
     * @param m1 The first matrix.
     * @param m2 The second matrix.
     * @return A new matrix which is the result.
     */
    template <class U> friend Matrix<U> operator+(const Matrix<U> m1, const Matrix<U> m2);

    /**
     * Subtracts two matrices from each other.
     * @tparam U The type of the values of the matrices.
     * @param m1 The first matrix.
     * @param m2 The second matrix.
     * @return A new matrix which is the result.
     */
    template <class U> friend Matrix<U> operator-(const Matrix<U> m1, const Matrix<U> m2);

    /**
     * Multiplies two given matrices.
     * @tparam U The type of the values of the matrices.
     * @param m1 The first matrix.
     * @param m2 The second matrix.
     * @return A new matrix which is the result.
     */
    template <class U> friend Matrix<U> operator*(const Matrix<U> m1, const Matrix<U> m2);

    /**
     * Multiplies the values of two given vectors.
     * @param v1 The first vector.
     * @param v2 The second vector.
     * @return The new result vector.
     */
    static T multiplyVector(const std::vector<T> v1, const std::vector<T> v2);

    /**
     * Compare operator, compares two given matrices.
     * @tparam U The type of the values of the matrices.
     * @param m1 The first matrix.
     * @param m2 The second matrix.
     * @return True if the matrices are equal, false otherwise.
     */
    template <class U> friend bool operator==(const Matrix<U> m1, const Matrix<U> m2);

    /**
     * Compare operator, compares two given matrices.
     * @tparam U The type of the values of the matrices.
     * @param m1 The first matrix.
     * @param m2 The second matrix.
     * @return True if the matrices are not equal, false otherwise.
     */
    template <class U> friend bool operator!=(const Matrix<U> m1, const Matrix<U> m2);


    //TODO test these functions.
    /**
     * Find the transposed matrix of the current matix.
     * @return A new matrix which is the transposed matrix.
     */
    Matrix<T> trans() const;

    /**
     * @return True if the current matrix if square, false otherwise.
     */
    bool isSquareMatrix();

    //TODO create a const and a non-const version of this method.
    /**
     * Access operator.
     * @param row the index of the row we want to access.
     * @param col the index of the col we want ot access.
     * @return The value in the given row and col indexes.
     */
    T& operator()(unsigned int row, unsigned int col);

    /**
     * Access operator.
     * @param row the index of the row we want to access.
     * @param col the index of the col we want ot access.
     * @return The value in the given row and col indexes.
     */
    const T& operator()(unsigned int row, unsigned int col) const;

    /**
     * Iterator for the matrix.
     * @return Iterator which points to the value in the beginning of the matrix.
     */
    const_iterator begin();

    /**
     * Iterator of the matrix.
     * @return Iterator which point to the value in the end of the matrix.
     */
    const_iterator end();

    /**
     * @return the number of rows in the matrix.
     */
    unsigned int rows();

    /**
     * @return The number of cols in the matrix.
     */
    unsigned int cols();

    /**
     * Print operator, prints the values of the matrix to the output.
     * @tparam U The type of the values of the matrix.
     * @param out the output stream.
     * @param m1 The matrix that will be printed.
     * @return the output stream.
     */
    template <class U> friend std::ostream& operator<<(std::ostream &out, Matrix<U> m1);

    /**
     * Find the transposed matrix of the given matrix.
     * @tparam U The type of the values of the matrix.
     * @param mat The given matrix.
     * @return The transposed matrix.
     */
    template <class U> friend Matrix<U> findTranspose(Matrix<U> mat);


private:
    /**
     * The number of rows and the number of cols in the matrix.
     */
    unsigned int _numColumns, _numRows;

    /**
     * A 2d vector that stores the values of the matrix.
     */
    std::vector<std::vector <T>> _matrix;

};


/*
     * ///////////////////////
     *        ITERATOR
     * ///////////////////////
     */

/**
 * Returns the next value in the iterator.
 * @return
 */
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

/**
 * Returns the previous value in the iterator.
 * @return
 */
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

/**
 * Returns the next value in the iterator.
 * @return
 */
template <class T>
const typename Matrix<T>::const_iterator Matrix<T>::const_iterator::operator++(int)
{
    T retVal = *this;
    ++(*this);
    return retVal;
}

/**
 * Returns the previous value in the iterator.
 * @return
 */
template <class T>
const typename Matrix<T>::const_iterator Matrix<T>::const_iterator::operator--(int)
{
    T retVal = *this;
    --(*this);
    return retVal;
}

/**
 * Compares two values of the iterator.
 * @param other the other value.
 * @return True if equal, false otherwise.
 */
template <class T>
bool Matrix<T>::const_iterator::operator==(const Matrix<T>::const_iterator &other)
{
    return other.vec == vec && other.outerIterIndex == outerIterIndex && other.innerIterIndex == innerIterIndex;
}

/**
 * Compares two values of the iterator.
 * @param other the other value.
 * @return True if not equal, false otherwise.
 */
template <class T>
bool Matrix<T>::const_iterator::operator!=(const Matrix<T>::const_iterator &other)
{
    return !(*this == other);
}

/**
 * Access the value stored in iterator.
 * @return
 */
template <class T>
const T& Matrix<T>::const_iterator::operator*() const
{
    return *this;
}

/**
 * Access the value stored in iterator.
 * @return
 */
template <class T>
T& Matrix<T>::const_iterator::operator*()
{
    return (*vec)[outerIterIndex][innerIterIndex];
}

/**
 * Access the value stored in iterator.
 * @return
 */
template <class T>
const T& Matrix<T>::const_iterator::operator->() const
{
    return *this;
}

/**
 * Access the value stored in iterator.
 * @return
 */
template <class T>
T& Matrix<T>::const_iterator::operator->()
{
    return *this;
}

/*
 * ///////////////////////
 *     GENERIC MATRIX
 * ///////////////////////
 */

/**
 * Default constructor for the matrix.
 */
template <class T>
Matrix<T>::Matrix()
{
    _numRows = _numColumns = 1;
    std::vector<T> row;
    row.resize(1);
    _matrix.push_back(row);
}

/**
 * Constructor that receives a number of rows and a number of cols and creates a matrix
 * with these sizes that has the default type of the Matrix type.
 * @param rows The number of rows.
 * @param cols The number of cols.
 */
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

/**
 * A copy constructor which creates a new matrix with the values of a given matrix.
 * @param mat The matrix with the values we want to copy.
 */
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

/**
* A constructor which receives the number of rows, number of cols and a vector which contains
* all the values of the matrix.
* @param rows The number of rows.
* @param cols The number of cols.
* @param cells The vector that conatains the values.
*/
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

/**
 * Copy operator, changes the values of the current matrix to the values of the given matrix.
 * @param mat The given matrix
 * @return the changes matrix.
 */
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

/**
 * Add the values of two given matrices.
 * @tparam U The type of the values of the matrices.
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return A new matrix which is the result.
 */
template <class U>
Matrix<U> operator+(const Matrix<U> m1, const Matrix<U> m2)
{
    //TODO if going to do the bonus, add the bool value
    if (m1._numColumns != m2._numColumns || m1._numRows != m2._numRows)
    {
        throw diffSizeEx;
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

/**
 * Subtracts two matrices from each other.
 * @tparam U The type of the values of the matrices.
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return A new matrix which is the result.
 */
template <class U>
Matrix<U> operator-(const Matrix<U> m1, const Matrix<U> m2)
{
    if (m1._numColumns != m2._numColumns || m1._numRows != m2._numRows)
    {
        throw diffSizeEx;
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

/**
 * Multiplies two given matrices.
 * @tparam U The type of the values of the matrices.
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return A new matrix which is the result.
 */
template <class U>
Matrix<U> operator*(const Matrix<U> m1, const Matrix<U> m2)
{
    //TODO exception m1 cols = m2 rows
    if (m1._numColumns != m2._numRows)
    {
        throw diffSizeEx;
    }

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

/**
 * Multiplies the values of two given vectors.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return The new result vector.
 */
template <class T>
T Matrix<T>::multiplyVector(const std::vector<T> v1, const std::vector<T> v2)
{
    if (v1.size() != v2.size())
    {
        throw diffSizeEx;
    }

    T result;

    for (unsigned i = 0; i < v1.size(); ++i)
    {
        result += v1[i] * v2[i];
    }
    return result;
}

/**
 * Compare operator, compares two given matrices.
 * @tparam U The type of the values of the matrices.
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return True if the matrices are equal, false otherwise.
 */
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

/**
 * Compare operator, compares two given matrices.
 * @tparam U The type of the values of the matrices.
 * @param m1 The first matrix.
 * @param m2 The second matrix.
 * @return True if the matrices are not equal, false otherwise.
 */
template <class U>
bool operator!=(const Matrix<U> m1, const Matrix<U> m2)
{
    return !(m1 == m2);
}

/**
 * Find the transposed matrix of the current matix.
 * @return A new matrix which is the transposed matrix.
 */
template <class T>
Matrix<T> Matrix<T>::trans() const
{
    if (_numRows != _numColumns)
    {
        throw notSquareEx;
    }
    else
    {
        return findTranspose(*this);
    }
}

/**
 * Find the transposed matrix of the current matix (Specific implementation for Complex
 * value types).
 * @return A new matrix which is the transposed matrix.
 */
template <>
Matrix<Complex> Matrix<Complex>::trans() const
{
    if (_numRows != _numColumns)
    {
        throw notSquareEx;
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

/**
 * @return True if the current matrix if square, false otherwise.
 */
template <class T>
bool Matrix<T>::isSquareMatrix()
{
    return this->_numRows == this->_numColumns;
}

/**
 * Print operator, prints the values of the matrix to the output.
 * @tparam U The type of the values of the matrix.
 * @param out the output stream.
 * @param m1 The matrix that will be printed.
 * @return the output stream.
 */
template <class U>
std::ostream& operator<<(std::ostream &out, Matrix<U> m1)
{
    for (unsigned i = 0; i < m1._matrix.size(); ++i)
    {
        for (unsigned j = 0 ; j < m1._numColumns; ++j)
        {
            out << m1._matrix[i][j] << "\t";
        }
        out << "" << std::endl;

    }
    return out;
}

/**
 * Access operator.
 * @param row the index of the row we want to access.
 * @param col the index of the col we want ot access.
 * @return The value in the given row and col indexes.
 */
template <class T>
T& Matrix<T>::operator()(unsigned int row, unsigned int col)
{
    if (row > this->_numRows || row <= 0 || col > this->_numColumns || col <= 0)
    {
        throw std::out_of_range("");
    }
    return this->_matrix[row - 1][col - 1];
}

/**
 * Access operator.
 * @param row the index of the row we want to access.
 * @param col the index of the col we want ot access.
 * @return The value in the given row and col indexes.
 */
template <class T>
const T& Matrix<T>::operator()(unsigned int row, unsigned int col) const
{
    if (row > this->_numRows || row <= 0 || col > this->_numColumns || col <= 0)
    {
        throw std::out_of_range("");
    }
    return this->_matrix[row - 1][col - 1];
}

/**
 * Iterator for the matrix.
 * @return Iterator which points to the value in the beginning of the matrix.
 */
template <class T>
typename Matrix<T>::const_iterator Matrix<T>::begin()
{
    return const_iterator(&_matrix, 0, 0);
}

/**
 * Iterator of the matrix.
 * @return Iterator which point to the value in the end of the matrix.
 */
template <class T>
typename Matrix<T>::const_iterator Matrix<T>::end()
{
    return const_iterator(&_matrix, _matrix.size(), 0);
}

/**
 * @return the number of rows in the matrix.
 */
template <class T>
unsigned int Matrix<T>::rows()
{
    return _numRows;
}

/**
 * @return The number of cols in the matrix.
 */
template <class T>
unsigned int Matrix<T>::cols()
{
    return _numColumns;
}

/**
 * Find the transposed matrix of the given matrix.
 * @tparam U The type of the values of the matrix.
 * @param mat The given matrix.
 * @return The transposed matrix.
 */
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

#endif