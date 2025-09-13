#include <iostream>
#include <iomanip>
#include <ostream>


using u8 = unsigned char;
using u32 = unsigned int;

class Fraction {
private:
    int _integer;
    u8 _fraction;
public:
    Fraction(int integer, u8 fraction) : \
        _integer{integer}, _fraction{fraction} {}
    friend std::ostream &operator<<(std::ostream &out, 
            const Fraction frac);
    Fraction operator+(const Fraction operand2) const {
        u32 fraction {(u32)(_fraction + operand2._fraction)};
        return Fraction{(int)(_integer + operand2._integer + \
            (fraction / 100)), (u8)(fraction % 100)};
    }
    Fraction &operator+=(const Fraction operand2) {
        u32 fraction {(u32)(_fraction + operand2._fraction)};
        _integer += operand2._integer + (fraction / 100);
        _fraction = fraction % 100;
        return *this;
    }
    Fraction operator-(const Fraction operand2) const {
        int fraction {_fraction - operand2._fraction};
        int integer {_integer - operand2._integer};
        if (fraction < 0)
            fraction += 100, integer--;
        return Fraction{integer, (u8)fraction};
    }
    Fraction &operator-=(const Fraction operand2) {
        int fraction {_fraction - operand2._fraction};
        if (fraction < 0)
            fraction += 100, _integer--;
        _integer -= operand2._integer;
        return *this;
    }
    Fraction operator*(const Fraction operand2) const {
        return Fraction{_integer * operand2._integer, \
            (u8)(_fraction * operand2._fraction)};
    }
    Fraction operator/(const Fraction operand2) const {
        return Fraction{_integer / operand2._integer, \
            (u8)(_fraction / operand2._fraction)};
    }
    bool operator==(const Fraction operand2) const {
        return _integer == operand2._integer && \
            _fraction == operand2._fraction;
    }
    bool operator!=(const Fraction operand2) const {
        return _integer != operand2._integer || \
            _fraction != operand2._fraction;
    }
    bool operator<=(const Fraction operand2) const {
        return _integer < operand2._integer || \
            _integer == operand2._integer && \
            _fraction <= operand2._fraction;
    }
    bool operator>=(const Fraction operand2) const {
        return _integer > operand2._integer || \
            _integer == operand2._integer && \
            _fraction >= operand2._fraction;
    }
    bool operator>(const Fraction operand2) const {
        return _integer > operand2._integer || \
            _integer == operand2._integer && \
            _fraction > operand2._fraction;
    }
    bool operator<(const Fraction operand2) const {
        return _integer < operand2._integer || \
            _integer == operand2._integer && \
            _fraction < operand2._fraction;
    }
};

std::ostream &operator<<(std::ostream &out, const Fraction frac) {
    out << frac._integer << '.' << std::setfill('0') << \
        std::setw(2) << (short)frac._fraction;
    return out;
}

int main(void) {
    Fraction frac1{9, 8}, frac2{7, 9};
    std::cout << (frac1 + frac2) << std::endl;
    std::cout << (frac1 - frac2) << std::endl;
    std::cout << (frac1 * frac2) << std::endl;
    std::cout << (frac1 / frac2) << std::endl;
    std::cout << (frac1 == frac2) << std::endl;
    std::cout << (frac1 != frac2) << std::endl;
    std::cout << (frac1 <= frac2) << std::endl;
    std::cout << (frac1 >= frac2) << std::endl;
    std::cout << (frac1 < frac2) << std::endl;
    std::cout << (frac1 > frac2) << std::endl;
    return 0;
}
