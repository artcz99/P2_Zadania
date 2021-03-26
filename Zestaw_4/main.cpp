//Artur Czarnik, Zestaw 4

#include <iostream>

using namespace std;

class Complex {
public:
    Complex();

    Complex(double a, double b);

    friend Complex operator+(Complex, Complex);

    friend Complex operator-(Complex, Complex);

    friend Complex operator*(Complex, Complex);

    friend Complex operator/(Complex, Complex);

    friend bool operator==(Complex, Complex);

    friend bool operator!=(Complex, Complex);

    Complex &operator=(Complex &x) {
        this->re = x.re;
        this->im = x.im;
        return *this;
    }

    Complex &operator+=(Complex &x) {
        this->re = this->re + x.re;
        this->im = this->im + x.im;
        return *this;
    }

    Complex &operator-=(Complex x) {
        this->re = this->re - x.re;
        this->im = this->im - x.im;
        return *this;
    }

    Complex &operator*=(Complex &x) {
        double temp;
        temp = this->re * x.re - this->im * x.im;
        this->im = this->re * x.im + x.re * this->im;
        this->re = temp;
        return *this;
    }

    Complex &operator/=(Complex &x) {
        double temp;
        temp = (this->re * x.re + this->im * x.im) / (x.re * x.re + x.im * x.im);
        this->im = (x.re * this->im - this->re * x.im) / (x.re * x.re + x.im * x.im);
        this->re = temp;
        return *this;
    }

    friend ostream &operator<<(ostream &, Complex &);

    friend istream &operator>>(istream &, Complex &);

    Complex& operator-() {
        this->re = -this->re;
        this->im = -this->im;
       return *this;
    }

    Complex& operator!() {
        this->im = -this->im;
        return *this;
    }

    Complex& operator++() { //++z
        this->re++;
        return *this;
    }

    Complex& operator--() { //--z
        this->re--;
        return *this;
    }

    Complex& operator++(int) { //z++
        this->im++;
        return *this;

    }

    Complex& operator--(int){ //z--
        this->im--;
        return *this;
    }

private:
    double re, im;
};

Complex::Complex(double a, double b) {
    re = a;
    im = b;
}

Complex::Complex() {
    re = 0;
    im = 0;
}

Complex operator+(Complex x, Complex y) {
    return Complex(x.re + y.re, x.im + y.im);
}

Complex operator-(Complex x, Complex y) {
    return Complex(x.re - y.re, x.im - y.im);
}

Complex operator*(Complex x, Complex y) { //(a+bi)*(c+di) = ac + adi + cbi - bd
    double temp;
    temp = x.re * y.re - x.im * y.im;
    return Complex(temp, (x.re * y.im + y.re * x.im));
}

Complex operator/(Complex x, Complex y) { //https://socratic.org/questions/how-do-you-write-a-bi-c-di-in-standard-form
    double temp;
    temp = (x.re * y.re + x.im * y.im) / (y.re * y.re + y.im * y.im);
    return Complex(temp, (y.re * x.im - x.re * y.im) / (y.re * y.re + y.im * y.im));
}

ostream &operator<<(ostream &stream, Complex &x) {
    stream << x.re << " + " << x.im << "i";
    return stream;
}

istream &operator>>(istream &stream, Complex &x) {
    stream >> x.re;
    stream >> x.im;
    return stream;
}

bool operator==(Complex x, Complex y) {
    return x.re == y.re && x.im == y.im;
}

bool operator!=(Complex x, Complex y) {
    return x.re != y.re || x.im != y.im;
}

int main() {
    Complex a(12, -3);
    Complex c(-6, 4);
    Complex d = a + c;
    Complex e = a - c;
    Complex f = a / c;
    Complex g = a * c;
    cout << "a = " << a << endl;
    cout << "c = " << c << endl;
    cout << "d = a + c = " << d << endl;
    cout << "e = a - c = " << e << endl;
    cout << "f = a / c = " << f << endl;
    cout << "g = a * c = " << g << endl;
    Complex h;
    cout << "Podaj dwie liczby oddzielone spacja" << endl;
    cin >> h;
    cout << "h = " << h << endl;
    h += a;
    g -= c;
    f *= a;
    e /= c;
    cout << "(h += a) => " << "h = " << h << endl;
    cout << "(g -= c) => " << "g = " << g << endl;
    cout << "(f *= a) => " << "f = " << f << endl;
    cout << "(e /= c) => " << "e = " << e << endl;

    cout << "a = " << a << endl;
    cout << "c = " << c << endl;

    cout << "-a = " << -a << endl;
    cout << "!c = " << !c << endl;

    cout << "a = " << a << endl;
    cout << "c = " << c << endl;

    cout << "a++ = " << a++ << endl;
    cout << "c-- = " << c-- << endl;

    cout << "d = " << d << endl;
    cout << "e = " << e << endl;

    cout << "++d = " << ++d << endl;
    cout << "--e = " << --e << endl;
}
