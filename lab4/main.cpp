#include <iostream>

template <typename T> class vector;
template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& vec);

template<typename Tp>
class vector {
private:
    Tp _x, _y, _z;
public:
    vector(Tp x = 0, Tp y = 0, Tp z = 0) : \
        _x{x}, _y{y}, _z{z} {}
    friend std::ostream &operator<< <Tp>(std::ostream &out, \
            const vector<Tp> &vec);
    vector<Tp> operator+(const vector<Tp> operand2) {
        return vector<Tp>{_x + operand2._x, \
            _y + operand2._y, _z + operand2._z};
    }
    Tp operator%(const vector<Tp> operand2) {
        return Tp{_x * operand2._x + _y * \
            operand2._y + _z * operand2._z};
    }
    vector<Tp> operator*(const vector<Tp> operand2) {
        return vector<Tp>{_y * operand2._z - _z * operand2._y, \
            _z * operand2._x - operand2._x * _z, \
                _x * operand2._y - _y * operand2._x};
    }
    bool operator||(const vector<Tp> operand2) {
        return _x / operand2._x == _y / operand2._y == _z / operand2._z;
    }
};

template<typename Tp>
std::ostream &operator<<(std::ostream &out, const vector<Tp> &vec) {
    out << "Vector: address = " << &vec << ", X = " << vec._x << \
        ", Y = " << vec._y << ", Z = " << vec._z << std::endl;
    return out;
}

int main(void) {
    vector<int> vec1{0, 9, 7}, vec2{-2, 7, 5};
    std::cout << vec1 << vec2 << (vec1 + vec2) << \
        (vec1 % vec2) << std::endl << (vec1 * vec2) << \
        (vec1 || vec2) << std::endl;
    return 0;
}
