#include <vector>
#include <iostream>
#include <ostream>

template<typename T>
class Vector : public std::vector<T> {
public:
    bool operator<(const T &num) const {
        const typename std::vector<T>::const_iterator itEnd { this->cend() };
        for (typename std::vector<T>::const_iterator it { this->cbegin() }; \
            it != itEnd; it++) if (*it == num) return true;
        return false;
    }
    Vector<T> operator+(const int& num) const  {
        Vector<T> vec{};
        vec.insert(vec.begin(), this->cbegin()+num, this->cend());
        return vec;
    }
    friend std::ostream &operator<<( \
            std::ostream &out, const Vector<T> &vec) {
        const typename std::vector<T>::const_iterator \
            itEnd { vec.cend() };
        for (typename std::vector<T>::const_iterator \
                it { vec.begin() }; it != itEnd; it++)
            out << *it << ' ';
        out << std::endl;
        return out;
    }
};

int main(void) {
    Vector<int> vecA;
    vecA.push_back(1);
    vecA.push_back(2);
    vecA.push_back(3);
    std::cout << "Vec A: " << vecA;

    Vector<int> vecB;
    vecB.push_back(3);
    vecB.push_back(4);
    vecB.push_back(5);
    std::cout << "Vec B: " << vecB;

    Vector<int> vecC {vecA + 1};
    std::cout << "\nVec A + 1: " << vecC;

    std::cout << "\nIs Vec A have number 3? " << (vecC < 3 ? "Yes" : "No") << std::endl;
    std::cout << "Is Vec A not equal to Vec B? " << (vecA != vecB ? "Yes" : "No") << std::endl;

    std::cout << "Get Vec B [1]: " << vecB[1] << std::endl;

    return 0;
}
