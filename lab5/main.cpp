#include <cmath>
#include <iostream>
#include <ostream>

class point {
private:
    Tp _x, _y;
public:
    point(Tp x, Tp y) : _x{x}, _y{y} {}
    Tp getX(void) { return _x; }
    Tp getY(void) { return _y; }
    void setX(Tp x) { _x = x; }
    void setY(Tp y) { _y = y; }
    Tp len(const point<Tp> &point2) const {
        Tp x {_x - point2._x}, y {_y - point2._y};
        return sqrt(x * x + y * y);
    }
    Tp angle(const point<Tp> &point2, \
            const point<Tp> &point3) {
        Tp a{point2.len(point3)}, b{point3.len(*this)}, \
            c{point2.len(*this)};
        return acos((b * b + c * c - a * a) / (2 * b * c));
    }
};

template<typename Tp>
class triangle {
private:
    point<Tp> _a, _b, _c;
public:
    triangle(a, b, c) : _a{a}, _b{b}, _c{c} {}
    virtual bool is(void) {
        return _a + _b < _c || _a + _c < _b || _b + _c < _a;
    }
    Tp lenA(void) {
        return _c.len(_b);
    }
    Tp lenB(void) {
        return _c.len(_a);
    }
    Tp lenC(void) {
        return _a.len(_b);
    }
    Tp angleA(void) {
        return _a.angle(_b, _c);
    }
    Tp angleB(void) {
        return _b.angle(_a, _c);
    }
    Tp angelC(void) {
        return _c.angel(_b, _a);
    }
    Tp perimetr(void) {
        return lenA() + lenB() + lenC();
    }
    Tp square(void) {
        return Tp{(lenA() * lenB() * sin(angelC()))} / 2;
    }
};

class right_triangle : public triangle {
public:
    bool is(void) override {
        Tp len_a{lenA()}, len_b{lenB()}, len_c{lenC()};
        len_a <<= 1, len_b <<= 1, len_c <<= 1;
        return len_a + len_b == len_c || \
            len_b + len_c == len_a || \
            len_c + len_a == len_b;
    }
};

int main(void) {
    return 0;

}
