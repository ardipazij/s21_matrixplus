#include "s21_matrix_oop.h"

#include <cmath>
#include <stdexcept>

// Constructor and destructor
S21Matrix::S21Matrix() = default;

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::out_of_range("Incorrect matrix size");
  }
  MemoryAllocation();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : S21Matrix(other.rows_, other.cols_) {
  CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.Blank();
}

S21Matrix::~S21Matrix() { DestroyMatrix(); }

// Accessors and mutators
[[nodiscard]] int S21Matrix::GetCols() const { return cols_; }

[[nodiscard]] int S21Matrix::GetRows() const { return rows_; }

void S21Matrix::SetRows(int rows) { ChangeMatrixSize(rows, cols_); }

void S21Matrix::SetCols(int cols) { ChangeMatrixSize(rows_, cols); }

// Base functions
bool S21Matrix::EqMatrix(const S21Matrix &other) {
  if (isNonEqualitySizeCheck(other)) {
    throw std::out_of_range("Different matrix size, eq_error");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (std::fabs(matrix_[i][j] - other(i, j)) > 1E-5) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (isNonEqualitySizeCheck(other)) {
    throw std::out_of_range("Different matrix size, sum_error");
  }
  Arithmetic(other, 1);
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (isNonEqualitySizeCheck(other)) {
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
    throw std::out_of_range(
        "The number of rows A matrix not equal to the number of rows B matrix");
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

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  S21Matrix temp;
  temp = (*this);
  if (temp.rows_ != temp.cols_) {
    throw std::out_of_range("Size of rows and cols must be equal");
  }
  if (rows_ == 1) return matrix_[0][0];
  double result = 1;
  for (int row{0}; row < temp.rows_; ++row) {
    int pivot_row = row;
    for (int next_row{row + 1}; next_row < temp.rows_; ++next_row) {
      if (std::fabs(temp.matrix_[next_row][row]) >
          std::fabs(temp.matrix_[pivot_row][row]))
        pivot_row = next_row;
    }
    if (std::fabs(temp.matrix_[pivot_row][row]) < 1E-11) {
      result = 0;
      return result;
    }
    if (row != pivot_row) {
      std::swap(temp.matrix_[row], temp.matrix_[pivot_row]);
      result *= -1;
    }
    result *= temp.matrix_[row][row];
    for (int next_col = row + 1; next_col < temp.rows_; ++next_col)
      temp.matrix_[row][next_col] /= temp.matrix_[row][row];
    for (int other_row = 0; other_row < temp.rows_; ++other_row)
      if (other_row != row && std::fabs(temp.matrix_[other_row][row]) > 1E-5)
        for (int next_col = row + 1; next_col < temp.rows_; ++next_col)
          temp.matrix_[other_row][next_col] -=
              temp.matrix_[row][next_col] * temp.matrix_[other_row][row];
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::out_of_range("Count of rows are not equal counts of cols");
  }
  S21Matrix result(rows_, cols_);
  for (int i{0}; i < rows_; ++i) {
    for (int j{0}; j < cols_; ++j) {
      S21Matrix temp(rows_ - 1, cols_ - 1);
      GetMinor(temp, i, j);
      double determinant = temp.Determinant();
      result(i, j) = std::pow(-1, i + j) * determinant;
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (det == 0) {
    throw std::out_of_range(
        "Determinant is equal zero, inverse matrix doesnt exist");
  }
  S21Matrix result(rows_, cols_);
  if (rows_ == 1) {
    result.matrix_[0][0] = std::pow(matrix_[0][0], -1);
  } else {
    S21Matrix complements = CalcComplements();
    result = complements.Transpose();
    result.MulNumber(1 / det);
  }
  return result;
}

// Override methods
double &S21Matrix::operator()(int i, int j) const { return matrix_[i][j]; }

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

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return (*this);
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return (*this);
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    DestroyMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    MemoryAllocation();
    CopyMatrix(other);
  }
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this != &other) {
    DestroyMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.Blank();
  }
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(double num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return (*this);
}

S21Matrix &S21Matrix::operator*=(double num) {
  MulNumber(num);
  return (*this);
}

S21Matrix operator*(double num, const S21Matrix &other) noexcept {
  S21Matrix result(other);
  result.MulNumber(num);
  return result;
}

// Helpers
void S21Matrix::MemoryAllocation() {
  matrix_ = new double *[rows_] {};
  if (!matrix_) throw std::out_of_range("Memory is dont allocate");
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_]{};
    if (!matrix_[i]) throw std::out_of_range("Memory is dont allocate");
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

void S21Matrix::Arithmetic(const S21Matrix &other, int sign) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = matrix_[i][j] + sign * other(i, j);
    }
  }
}

[[nodiscard]] bool S21Matrix::isNonEqualitySizeCheck(
    const S21Matrix &other) const {
  return (rows_ != other.GetRows() || cols_ != other.GetCols());
}

void S21Matrix::CopyMatrix(const S21Matrix &other) {
  if (matrix_) {
    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < cols_; ++j) matrix_[i][j] = other.matrix_[i][j];
  }
}

void S21Matrix::GetMinor(S21Matrix &temp, int ex_row, int ex_col) {
  int i = 0, j = 0;
  for (int row = 0; row < rows_; ++row) {
    for (int col = 0; col < cols_; ++col) {
      if (row != ex_row && col != ex_col) {
        temp(i, j) = matrix_[row][col];
        j++;
        if (j == cols_ - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}

void S21Matrix::ChangeMatrixSize(int new_rows, int new_cols) {
  S21Matrix temp(new_rows, new_cols);
  int max_rows_count = new_rows, max_cols_count = new_cols;
  if (new_rows > rows_) max_rows_count = rows_;
  if (new_cols > cols_) max_cols_count = cols_;
  for (int i{0}; i < max_rows_count; ++i) {
    for (int j{0}; j < max_cols_count; ++j) {
      temp.matrix_[i][j] = matrix_[i][j];
    }
  }
  (*this) = temp;
}