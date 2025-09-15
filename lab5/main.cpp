#include <vector>
#include <cmath>
#include <iostream>
#include <ostream>

template<typename Tp>
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
        return acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / M_PI;
    }
};

template<typename Tp>
class triangle {
private:
    point<Tp> _a, _b, _c;
public:
    triangle(point<Tp> a, point<Tp>b, point<Tp> c) : \
        _a{a}, _b{b}, _c{c} {}
    virtual bool is(void) {
        Tp a{lenA()}, b{lenB()}, c{lenC()};
        return a + b > c && a + c > b && b + c > a;
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
    Tp angleC(void) {
        return _c.angle(_b, _a);
    }
    Tp perimetr(void) {
        return lenA() + lenB() + lenC();
    }
    Tp square(void) {
        return ((Tp)(lenA() * lenB() * sin(angleC()))) / 2;
    }
};
template<typename Tp>
class right_triangle : public triangle<Tp> {
public:
    right_triangle(point<Tp> a, point<Tp> b, point<Tp> c) : \
        triangle<Tp>{a, b, c} {}
    bool is(void) override {
        Tp len_a{this->lenA()}, len_b{this->lenB()}, \
            len_c{this->lenC()};
        len_a *= len_a, len_b *= len_b, len_c *= len_c;
        return len_a + len_b == len_c || \
            len_b + len_c == len_a || \
            len_c + len_a == len_b;
    }
};

template<typename Tp>
void test(std::vector<Tp> &vec) {
    for (auto &element : vec)
        std::cout << "Is " << element.is() << "\tlenA " << \
            element.lenA() << "\tlenB " << element.lenB() << "\tlenC " << \
            element.lenC() << "\tangleA " << element.angleA() << "\tangelB " << \
            element.angleB() << "\tangelC " << element.angleC() << "\tperimeter " << \
            element.perimetr() << "\tsquare " << element.square() << std::endl;
    std::cout << "next" << std::endl;
}

int main(void) {
    std::vector<triangle<int>> N{{{3, 9}, {4, 5}, {9, 0}}, {{9, 0}, {9, 1}, {8, 3}}};
    std::vector<right_triangle<int>> M{{{3, 4}, {5, 8}, {9, 2}}, {{9, 0}, {1, 2}, {9, 8}}};
    test(N);
    test(M);
    return 0;
}
