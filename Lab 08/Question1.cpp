#include <iostream>
using namespace std;

class complex
{
    double real;
    double img;

public:
    complex() {}
    complex(double real, double img) : real(real), img(img) {}

    complex operator+(const complex &C)
    {
        complex cc;
        cc.real = real + C.real;
        cc.img = img + C.img;
        return cc;
    }
    complex operator-(const complex &C)
    {
        complex cc;
        cc.real = real - C.real;
        cc.img = img - C.img;
        return cc;
    }
    complex operator*(const complex &C)
    {
        complex cc;
        cc.real = real * C.real - img * C.img;
        cc.img = img * C.real + real * C.img;
        return cc;
    }
    complex operator/(const complex &C)
    {
        complex cc;
        int denominator = C.real * C.real + C.img * C.img;
        cc.real = (real * C.real + img * C.img) / denominator;
        cc.img = (img * C.real - real * C.img) / denominator;
        return cc;
    }
    friend void magnitude(complex cc);

    friend ostream &operator<<(ostream &, const complex &);
};

ostream &operator<<(ostream &OO, const complex &cc)
{
    OO << cc.real << " + " << cc.img << "i" << endl;
    return OO;
}

void magnitude(complex cc)
{
    cout << cc.real << " + " << cc.img << "i" << endl;
}

int main()
{
    complex C1(4, 4);
    complex C2(2, 6);
    complex C3_add = C1 + C2;
    complex C3_sub = C1 - C2;
    complex C3_mult = C1 * C2;
    complex C3_div = C1 / C2;
    cout << "Magnitude of actual numbers" << endl;
    magnitude(C1);
    magnitude(C2);
    cout << "<------------------------------>" << endl;
    cout << C1;
    cout << C2;
    cout << "<------------------------------>" << endl;
    cout << "After Arthmetic operations.." << endl;
    cout << C3_add;
    cout << C3_sub;
    cout << C3_mult;
    cout << C3_div;
    cout << "<------------------------------>" << endl;
}
