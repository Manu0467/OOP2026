#include "complex.h"

bool double_equals_l(double l, double r) {
    return abs(l - r) < 0.001;
}

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag)
{
    this->real_data = real;
    this->imag_data = imag;
    return *this;
}

Complex& Complex::operator--()
{
    --this->real_data;
    return *this;
}

Complex& Complex::operator++()
{
    ++this->real_data;
    return *this;
}

Complex Complex::operator--(int)
{
    Complex aux = *this;
    --(*this);
    return aux;
}

Complex Complex::operator++(int)
{
    Complex aux = *this;
    ++(*this);
    return aux;
}

//+ - * operators
Complex operator+(const Complex& l, const Complex& r)
{
    double realrez = l.real() + r.real(),
        imgrez = l.imag() + r.imag();
    Complex rez{ realrez, imgrez };
    
    return rez;
}

Complex operator+(const Complex& l, double r)
{
    double realrez = l.real() + r;
    Complex rez{ realrez, l.imag()};
    return rez;
}

Complex operator+(double l, const Complex& r)
{
    double realrez = l + r.real();
    Complex rez{realrez, r.imag()};
    return rez;
}
Complex operator-(const Complex& l, const Complex& r)
{
    double realrez = l.real() - r.real(),
        imgrez = l.imag() - r.imag();
    Complex rez{ realrez, imgrez };

    return rez;
}

Complex operator-(const Complex& l, double r)
{
    double realrez = l.real() - r;
    Complex rez{ realrez, l.imag() };
    return rez;
}

Complex operator-(double l, const Complex& r)
{
    double realrez =l - r.real();
    Complex rez{ realrez, -r.imag() };
    return rez;
}
Complex operator*(const Complex& l, const Complex& r)
{
    double realrez = l.real() * r.real() - l.imag() * r.imag();
    double imgrez = l.real() * r.imag() + l.imag() * r.real();
    Complex rez{ realrez, imgrez };

    return rez;
}

Complex operator*(const Complex& l, double r)
{
    double realrez = l.real() * r,
        imagrez = l.imag() * r;
    Complex rez{ realrez, imagrez};
    return rez;
}

Complex operator*(double l, const Complex& r)
{
    double realrez = r.real() * l,
        imagrez = r.imag() * l;
    Complex rez{ realrez, imagrez};
    return rez;
}

//+ - * operators

Complex operator-(const Complex& obj)
{
    double real = -obj.real(),
        imag = -obj.imag();
    Complex rez{ real,imag };

    return rez;
}

bool operator==(const Complex& l, const Complex& r)
{
    return (l.real() == r.real()) and (l.imag() == r.imag());
}

bool operator!=(const Complex& l, const Complex& r)
{
    return !(l==r);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    if (complex.real() == 0 and complex.imag() == 0)
    {
        out << 0;
    }
    else if (complex.imag()==0)
    {
        out << complex.real();
    }
    else {
        if (complex.real() != 0)
        {
            out << complex.real();
            if (complex.imag() > 0) {
                     out << " + " << complex.imag() << "i";
             }
            else {
                out << " - " << abs(complex.imag()) << "i";
            }
        }
        else {
            out << complex.imag()<<"i";
        }
    }
    return out;
}
