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
    Fraction(Fraction& frac) : \
        _integer{ frac._integer }, _fraction{ frac._fraction } {}
    Fraction(void) : _integer{ 0 }, _fraction{ 0 } {}
    Fraction(int integer = 0, u8 fraction = 0) : \
        _integer{ integer }, _fraction{ (u8)(fraction % 100) } {}
    friend std::ostream& operator<<(std::ostream& out,
        const Fraction &frac);
    Fraction add(const Fraction operand2) const {
        u32 fraction{ (u32)(_fraction + operand2._fraction) };
        return Fraction{ (int)(_integer + operand2._integer + \
            (fraction / 100)), (u8)(fraction % 100) };
    }
    Fraction& operator+=(const Fraction operand2) {
        u32 fraction{ (u32)(_fraction + operand2._fraction) };
        _integer += operand2._integer + (fraction / 100);
        _fraction = fraction % 100;
        return *this;
    }
    Fraction sub(const Fraction operand2) const {
        int fraction{ _fraction - operand2._fraction };
        int integer{ _integer - operand2._integer };
        if (fraction < 0)
            fraction += 100, integer--;
        return Fraction{ integer, (u8)fraction };
    }
    Fraction& operator-=(const Fraction operand2) {
        int fraction{ _fraction - operand2._fraction };
        if (fraction < 0)
            fraction += 100, _integer--;
        _integer -= operand2._integer;
        return *this;
    }
    Fraction imul(const Fraction operand2) const {
        int fraction{ _integer * operand2._fraction + \
            _fraction * operand2._integer + \
                _fraction * operand2._fraction / 100 };
        return Fraction{ _integer * operand2._integer + \
            fraction / 100, (u8)(fraction % 100) };
    }
    Fraction& operator*=(const Fraction operand2) {
        int fraction{ _integer * operand2._fraction + \
            _fraction * operand2._integer + \
                _fraction * operand2._fraction / 100 };
        _integer *= operand2._integer;
        _integer += fraction / 100;
        _fraction = fraction % 100;
        return *this;
    }
    Fraction div(const Fraction operand2) const {
        long long result_denominator \
        {(long long)operand2._integer* \
            100 + operand2._fraction};
        if (result_denominator == 0) {
            return Fraction{ 0, 0 };
        }
        long long result_numerator{ ((long long)_integer * \
                100 + _fraction) * 100 / result_denominator };
        return Fraction{ (int)(result_numerator / 100), \
                (u8)(result_numerator % 100) };
    }
    Fraction& operator/=(const Fraction operand2) {
        long long result_denominator \
        {(long long)operand2._integer* \
            100 + operand2._fraction};
        if (result_denominator == 0) {
            _integer = 0; _fraction = 0;
        }
        else {
            long long result_numerator{ ((long long)_integer * \
                    100 + _fraction) * 100 / result_denominator };
            _integer = result_numerator / 100;
            _fraction = result_numerator % 100;
        }
        return *this;
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

std::ostream& operator<<(std::ostream& out, const Fraction &frac) {
    out << frac._integer << '.' << std::setfill('0') << \
        std::setw(2) << (short)frac._fraction;
    return out;
}

int main(void) {
    Fraction frac1{ 9, 8 }, frac2{ 7, 9 };
    std::cout << (frac1.add(frac2)) << std::endl;
    std::cout << (frac1.sub(frac2)) << std::endl;
    std::cout << (frac1.imul(frac2)) << std::endl;
    std::cout << (frac1.div(frac2)) << std::endl;
    std::cout << (frac1 == frac2) << std::endl;
    std::cout << (frac1 != frac2) << std::endl;
    std::cout << (frac1 <= frac2) << std::endl;
    std::cout << (frac1 >= frac2) << std::endl;
    std::cout << (frac1 < frac2) << std::endl;
    std::cout << (frac1 > frac2) << std::endl;
    return 0;
}
