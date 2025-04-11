#include <iostream>
using namespace std;

class Matrix2x2
{
    int a, b;
    int c, d;

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) : a(a), b(b), c(c), d(d) {}

    Matrix2x2 operator+(const Matrix2x2 &obj) const
    {
        return Matrix2x2(a + obj.a, b + obj.b,
                        c + obj.c, d + obj.d);
    }
    
    Matrix2x2 operator-(const Matrix2x2 &obj) const
    {
        return Matrix2x2(a - obj.a, b - obj.b,
                        c - obj.c, d - obj.d);
    }
    
    Matrix2x2 operator*(const Matrix2x2 &obj) const
    {
        return Matrix2x2(a * obj.a + b * obj.c, a * obj.b + b * obj.d,
                        c * obj.a + d * obj.c, c * obj.b + d * obj.d);
    }

    friend int determinent(const Matrix2x2 &matrix1);
    friend ostream &operator<<(ostream &obj, const Matrix2x2 &matrix1);
    friend class MatrixHelper;
};

int determinent(const Matrix2x2 &matrix1)
{
    return matrix1.a * matrix1.d - matrix1.b * matrix1.c;
}

class MatrixHelper
{
public:
    static void modifyElement(Matrix2x2 &obj1, int row, int col, int val)
    {
        if (row == 0 && col == 0)
            obj1.a = val;
        else if (row == 0 && col == 1)
            obj1.b = val;
        else if (row == 1 && col == 0)
            obj1.c = val;
        else if (row == 1 && col == 1)
            obj1.d = val;
        else
            cerr << "Invalid matrix dimensions" << endl;
    }
};

ostream &operator<<(ostream &oprt, const Matrix2x2 &obj2)
{
    oprt << "( " << obj2.a << " " << obj2.b << " )" << endl;
    oprt << "( " << obj2.c << " " << obj2.d << " )" << endl;
    return oprt;
}

int main()
{
    Matrix2x2 M1(1, 2, 3, 4);
    Matrix2x2 M2(5, 6, 7, 8);

    cout << "Matrix 1: " << endl << M1 << endl;
    cout << "Matrix 2: " << endl << M2 << endl;

    cout << "Addition:" << endl << M1 + M2 << endl;
    cout << "Subtraction: " << endl << M1 - M2 << endl;
    cout << "Multiplication: " << endl << M1 * M2 << endl;

    cout << "Determinant of Matrix1: " << determinent(M1) << "\n\n";

    cout << "Before update: " << endl << M1 << endl;
    MatrixHelper::modifyElement(M1, 0, 1, 10);
    cout << "After updating element (0,1) to 10: " << endl << M1 << endl;

    return 0;
}
