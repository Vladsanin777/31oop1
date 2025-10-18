
#define _USE_MATH_DEFINES
#include <vector>
#include <cmath>
#include <iostream>
#include <ostream>
#include <numbers>

using namespace std;


template<typename Tp>
class point {
private:
    Tp _x, _y;
public:
    point(void) : _x{ 0 }, _y{ 0 } {}
    point(Tp x, Tp y) : _x{ x }, _y{ y } {}
    point(const point<Tp> &pont) : _x{pont._x}, _y{pont._y} {}
    Tp getX(void) const { return _x; }
    Tp getY(void) const { return _y; }
    void setX(Tp x) { _x = x; }
    void setY(Tp y) { _y = y; }
    Tp len(const point<Tp>& point2) const {
        Tp x{ _x - point2._x }, y{ _y - point2._y };
        return sqrt(x * x + y * y);
    }
    Tp angle(const point<Tp>& point2, \
        const point<Tp>& point3) const {
        Tp a{ point2.len(point3) }, b{ point3.len(*this) }, \
            c{ point2.len(*this) };
        return acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / M_PI;
    }
};

template<typename Tp>
class triangle {
private:
    point<Tp> _a, _b, _c;
public:
    triangle(void) : _a{}, _b{}, _c{} {}
    triangle(point<Tp> a, point<Tp>b, point<Tp> c) : \
        _a{ a }, _b{ b }, _c{ c } {}
    triangle(const triangle &triang) : _a{ triang._a }, \
        _b{ triang._b }, _c{ triang._c } {}
    virtual bool is(void) const {
        Tp a{ lenA() }, b{ lenB() }, c{ lenC() };
        return a + b > c && a + c > b && b + c > a;
    }
    Tp lenA(void) const {
        return _c.len(_b);
    }
    Tp lenB(void) const {
        return _c.len(_a);
    }
    Tp lenC(void) const {
        return _a.len(_b);
    }
    Tp angleA(void) const {
        return _a.angle(_b, _c);
    }
    Tp angleB(void) const {
        return _b.angle(_a, _c);
    }
    Tp angleC(void) const {
        return _c.angle(_b, _a);
    }
    Tp perimetr(void) const {
        return lenA() + lenB() + lenC();
    }
    Tp square(void) const {
        return ((Tp)(lenA() * lenB() * sin(angleC()))) / 2;
    }
    point<Tp> getA(void) const { return _a; }
    point<Tp> getB(void) const { return _b; }
    point<Tp> getC(void) const { return _c; }
    friend std::ostream &operator<<(std::ostream &out, const triangle& tri) {
        out << "Is " << tri.is() << "\tlenA " << \
            tri.lenA() << "\tlenB " << tri.lenB() << "\tlenC " << \
            tri.lenC() << "\tangleA " << tri.angleA() << "\tangelB " << \
            tri.angleB() << "\tangelC " << tri.angleC() << "\tperimeter " << \
            tri.perimetr() << "\tsquare " << tri.square() << std::endl;
        return out;
    }
};
template<typename Tp>
class right_triangle : public triangle<Tp> {
public:
    right_triangle(void) : triangle<Tp>{} {}
    right_triangle(point<Tp> a, point<Tp> b, point<Tp> c) : \
        triangle<Tp>{a, b, c} {}
    right_triangle(const right_triangle<Tp> &ri_tri) : \
        triangle<Tp>{ ri_tri.getA(), ri_tri.getB(), ri_tri.getC() } {}
    bool is(void) const override {
        Tp len_a{ this->lenA() }, len_b{ this->lenB() }, \
            len_c{ this->lenC() };
        len_a *= len_a, len_b *= len_b, len_c *= len_c;
        return len_a + len_b == len_c || \
            len_b + len_c == len_a || \
            len_c + len_a == len_b;
    }
    friend std::ostream &operator<<(std::ostream &out, const right_triangle<Tp>& ri_tri) {
        out << "Is " << ri_tri.is() << "\tlenA " << \
            ri_tri.lenA() << "\tlenB " << ri_tri.lenB() << "\tlenC " << \
            ri_tri.lenC() << "\tangleA " << ri_tri.angleA() << "\tangelB " << \
            ri_tri.angleB() << "\tangelC " << ri_tri.angleC() << "\tperimeter " << \
            ri_tri.perimetr() << "\tsquare " << ri_tri.square() << std::endl;
        return out;
    }
};

template<typename Tp>
void test(std::vector<Tp>& vec) {
    typename std::vector<Tp>::iterator itEnd{vec.end()};
    for (typename std::vector<Tp>::iterator it{vec.begin()}; it != itEnd; it++)
        std::cout << *it << std::endl;
    std::cout << "next" << std::endl;
}

int main(void) {
    std::vector<triangle<int>> N{ {{3, 9}, {4, 5}, {9, 0}}, {{9, 0}, {9, 1}, {8, 3}} };
    std::vector<right_triangle<int>> M{ {{3, 4}, {5, 8}, {9, 2}}, {{9, 0}, {1, 2}, {9, 8}} };
    test(N);
    test(M);
    return 0;
}
