#ifndef CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H

class S21Matrix {
public:
    S21Matrix(); // tested
    S21Matrix(int rows, int cols); // tested
    S21Matrix(const S21Matrix &other); // tested
    S21Matrix(S21Matrix &&other) noexcept; // tested
    ~S21Matrix(); // tested

    [[nodiscard]] int GetRows() const; // tested
    [[nodiscard]] int GetCols() const; // tested
    void SetRows(int rows);
    void SetCols(int cols);

    bool EqMatrix(const S21Matrix &other); // tested
    void SumMatrix(const S21Matrix &other); // tested
    void SubMatrix(const S21Matrix &other); // tested
    void MulNumber(double num); // tested
    void MulMatrix(const S21Matrix &other); // tested
    S21Matrix Transpose(); // tested
    double Determinant(); // tested
    S21Matrix CalcComplements(); // tested
    S21Matrix InverseMatrix(); // tested

    double &operator()(int i, int j) const; // tested
    double &operator()(int i, int j); // override tested
    S21Matrix operator+(const S21Matrix &other); // tested
    S21Matrix operator-(const S21Matrix &other); // tested
    bool operator==(const S21Matrix &other); // tested
    S21Matrix &operator+=(const S21Matrix &other); // tested
    S21Matrix &operator-=(const S21Matrix &other); // tested
    S21Matrix &operator=(const S21Matrix &other); // tested
    S21Matrix &operator=(S21Matrix &&other) noexcept; // tested
    S21Matrix operator*(const S21Matrix &other); // tested
    S21Matrix operator*(double num); // tested
    S21Matrix &operator*=(const S21Matrix &other); // tested
    S21Matrix &operator*=(double num); // tested
    friend S21Matrix operator*(double num, const S21Matrix &other) noexcept; // tested

private:
    void DestroyMatrix();
    void MemoryAllocation();
    void Blank();
    void Arithmetic(const S21Matrix &other, int sign);
    [[nodiscard]] bool isNonEqualitySizeCheck(const S21Matrix &other) const;
    void CopyMatrix(const S21Matrix &other);
    void GetMinor(S21Matrix &temp, int ex_row, int ex_col);
    void ChangeMatrixSize(int new_rows, int new_cols);

    int rows_ = 0, cols_ = 0;
    double **matrix_ = nullptr;
};

#endif