#include "s21_matrix_oop.h"
#include <stdexcept>
#include <cmath>

// constructor and destructor
S21Matrix::S21Matrix() {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
    if (rows_ <= 0 || cols_ <= 0) {
        throw std::out_of_range("Incorrect matrix size");
    }
    MemoryAllocation();
}

S21Matrix::S21Matrix(const S21Matrix &other) : S21Matrix(other.rows_, other.cols_) {
    CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix &&other)

noexcept:
rows_(other
.rows_),
cols_(other
.cols_),
matrix_(other
.matrix_) {
other.

Blank();

}

S21Matrix::~S21Matrix() { DestroyMatrix(); }

// accessors and mutators
int S21Matrix::GetCols() const {
    return cols_;
}

int S21Matrix::GetRows() const {
    return rows_;
}

// base functions
bool S21Matrix::EqMatrix(const S21Matrix &other) {
    if (NonEqualitySizeCheck(other)) {
        throw std::out_of_range("Different matrix size, eq_error");
    }
    bool result = true;
    for (int i = 0; i < rows_ && result; i++) {
        for (int j = 0; j < cols_ && result; j++) {
            if (fabs(matrix_[i][j] - other(i, j)) > 1E-6) {
                result = false;
            }
        }
    }
    return result;

}

void S21Matrix::SumMatrix(const S21Matrix &other) {
    if (NonEqualitySizeCheck(other)) {
        throw std::out_of_range("Different matrix size, sum_error");
    }
    Arithmetic(other, 1);
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
    if (NonEqualitySizeCheck(other)) {
        throw std::out_of_range("Different matrix size, sub_error");
    }
    Arithmetic(other, -1);
}

void S21Matrix::MulNumber(const double num) {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            matrix_[i][j] *= num;
        }
    }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
    if (cols_ != other.rows_) {
        throw std::out_of_range("The number of rows A matrix not equal to the number of rows B matrix");
    }
    S21Matrix result(rows_, other.cols_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < other.cols_; ++j) {
            result.matrix_[i][j] = 0;
            for (int k = 0; k < other.rows_; ++k) {
                result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
            }
        }
    }
    *this = result;
}

//override methods
double &S21Matrix::operator()(int i, int j) const {
    if (i < 0 || j < 0 || i > rows_ - 1 || j > cols_ - 1)
        throw std::out_of_range("Incorrect matrix's index");
    return matrix_[i][j];
}

double &S21Matrix::operator()(int i, int j) {
    if (i < 0 || j < 0 || i > rows_ - 1 || j > cols_ - 1)
        throw std::out_of_range("Incorrect matrix's index");
    return matrix_[i][j];
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
    S21Matrix result(*this);
    result.SumMatrix(other);
    return result;

}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
    S21Matrix result(*this);
    result.SubMatrix(other);
    return result;
}

bool S21Matrix::operator==(const S21Matrix &other) {
    return EqMatrix(other);
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
    SumMatrix(other);
    return (*this);
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
    SubMatrix(other);
    return (*this);
}

S21Matrix S21Matrix::operator=(const S21Matrix &other) {
    if (this != &other) {
        DestroyMatrix();
        rows_ = other.rows_;
        cols_ = other.cols_;
        MemoryAllocation();
        CopyMatrix(other);
    }
    return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
    if (this != &other) {
        DestroyMatrix();
        rows_ = other.rows_;
        cols_ = other.cols_;
        matrix_ = other.matrix_;
        other.Blank();
    }
    return *this;
}
//const double num
//S21Matrix& operator*(S21Matrix&& other){
//    S21Matrix result(*this);
//    result.MulMatrix(other);
//    return result;
//}
//S21Matrix& operator*=(S21Matrix&& other){
//    S21Matrix result(*this);
//    result.MulNumber(other);
//    return result;
//}

// helpers
void S21Matrix::MemoryAllocation() {
    matrix_ = new double *[rows_]{};
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_]{};
    }
}

void S21Matrix::Blank() {
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
}

void S21Matrix::DestroyMatrix() {
    if (matrix_ != nullptr) {
        for (int i = 0; i < rows_; ++i) {
            delete[] matrix_[i];
        }
        delete[] matrix_;
    }
}

void S21Matrix::Arithmetic(const S21Matrix &other, const int sign) {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] = matrix_[i][j] + sign * other(i, j);
        }
    }
}

bool S21Matrix::NonEqualitySizeCheck(const S21Matrix &other) {
    return (rows_ != other.GetRows() || cols_ != other.GetCols());
}

void S21Matrix::CopyMatrix(const S21Matrix &other) {
    if (matrix_) {
        for (int i = 0; i < rows_; i++)
            for (int j = 0; j < cols_; j++) matrix_[i][j] = other.matrix_[i][j];
    }
}