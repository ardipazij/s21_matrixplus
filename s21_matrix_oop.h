#ifndef CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H

class S21Matrix {
public:
    S21Matrix(); // tested
    S21Matrix(int rows, int cols); // tested
    S21Matrix(const S21Matrix &other); //tested
    S21Matrix(S21Matrix &&other) noexcept; //tested

    [[nodiscard]] int GetRows() const; // tested
    [[nodiscard]] int GetCols() const; // tested
    void SetRows(int rows);
    void SetCols(int cols);

    bool EqMatrix(const S21Matrix &other); //tested
    void SumMatrix(const S21Matrix &other);//tested
    void SubMatrix(const S21Matrix &other);//tested
    void MulNumber(double num); // tested
    void MulMatrix(const S21Matrix &other); //tested
    S21Matrix Transpose(); // tested
    double Determinant();

    double &operator()(int i, int j) const; // tested
    double &operator()(int i, int j); // override tested
    S21Matrix operator+(const S21Matrix &other); // tested
    S21Matrix operator-(const S21Matrix &other); //tested
    bool operator==(const S21Matrix &other); //tested
    S21Matrix &operator+=(const S21Matrix &other); //tested
    S21Matrix &operator-=(const S21Matrix &other); // tested
    S21Matrix& operator=(const S21Matrix &other);// tested
    S21Matrix &operator=(S21Matrix &&other) noexcept; //tested
    S21Matrix operator*(const S21Matrix &other); // tested
    S21Matrix operator*(double num); // tested
    S21Matrix &operator*=(const S21Matrix &other); // tested
    S21Matrix &operator*=(double num); //tested
    friend S21Matrix operator*(double num, const S21Matrix &other) noexcept; // tested

    ~S21Matrix(); //tested
private:
    int rows_ = 0, cols_ = 0;
    double **matrix_ = nullptr;

    void DestroyMatrix();

    void MemoryAllocation();

    void Blank();

    void Arithmetic(const S21Matrix &other, int sign);

    bool NonEqualitySizeCheck(const S21Matrix &other);

    void CopyMatrix(const S21Matrix &other);
};

#endif
/*

S21Matrix CalcComplements()
S21Matrix InverseMatrix()




* // done
*= // done
 *  set_rows(); // done
 set_cols(); // done
 S21Matrix Transpose() // done
void MulNumber(const double num) // done
void MulMatrix(const S21Matrix& other) // done
void SubMatrix(const S21Matrix& other)
 S21Matrix(const S21Matrix& other) // done
S21Matrix(S21Matrix&& other) // done
 + // done
- // done
 = // done
 = // done
    void SumMatrix(const S21Matrix& other) // done
    void SubMatrix(const S21Matrix& other) // done
 get_rows() // done
 get+cols() // done
 S21Matrix(int rows, int cols) done
 S21Matrix() // done
 += done
    -= done
    == done
 (int i, int j) // done
 bool EqMatrix(const S21Matrix& other) // done
 ~S21Matrix() // done
*/