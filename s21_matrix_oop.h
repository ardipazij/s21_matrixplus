#ifndef CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H
#define CPP1_S21_MATRIXPLUS_SRC_S21_MATRIX_OOP_H

class S21Matrix {
public:
    S21Matrix(); // tested
    S21Matrix(int rows, int cols); // tested
    S21Matrix(const S21Matrix &other); //tested
    S21Matrix(S21Matrix&& other) noexcept; //tested

    int GetRows() const; // tested
    int GetCols() const; // tested

    bool EqMatrix(const S21Matrix &other); //tested
    void SumMatrix(const S21Matrix &other);//tested
    void SubMatrix(const S21Matrix &other);//tested
    void MulNumber(const double num); // tested
    void MulMatrix(const S21Matrix& other); //tested
    S21Matrix Transpose();

    double &operator()(int i, int j) const; // tested
    double &operator()(int i, int j); // override tested
    S21Matrix operator+(const S21Matrix &other); // tested
    S21Matrix operator-(const S21Matrix &other); //tested
    bool operator==(const S21Matrix &other); //tested
    S21Matrix &operator+=(const S21Matrix &other); //tested
    S21Matrix &operator-=(const S21Matrix &other); // tested
    S21Matrix operator=(const S21Matrix& other);// tested
    S21Matrix& operator=(S21Matrix&& other); //tested
    S21Matrix& operator*(S21Matrix&& other);
    S21Matrix& operator*=(S21Matrix&& other);

    ~S21Matrix(); //tested
private:
    int rows_ = 0, cols_ = 0;
    double **matrix_ = nullptr;

    void DestroyMatrix();

    void MemoryAllocation();

    void Blank();

    void Arithmetic(const S21Matrix &other, const int sign);

    bool NonEqualitySizeCheck(const S21Matrix &other);

    void CopyMatrix(const S21Matrix &other);
};

#endif
/*

S21Matrix Transpose()
S21Matrix CalcComplements()
double Determinant()
S21Matrix InverseMatrix()
 set_rows();
 set_cols();

*
*=
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