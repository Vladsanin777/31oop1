#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <list>

template<typename T>
class vector : public std::vector<T> {
public:
    vector(std::initializer_list<T> il) : std::vector<T>(il) {}
    size_t calcMaxOddIndex(void) {
        int maxOdd { std::numeric_limits<int>::min() };
        size_t maxOddIndex { (size_t)-1 };

        for (size_t i { 0 }; i < this->size(); ++i) {
            if (this->operator[](i) % 2 != 0 && this->operator[](i) > maxOdd) {
                maxOdd = this->operator[](i);
                maxOddIndex = i;
            }
        }
        return maxOddIndex;
    }
    vector<T> &operator>>(size_t index) {
        if (index < this->size() - 1) {
            typename std::vector<T>::iterator \
                startRight { this->begin() + index + 1 }, \
                endRight { this->end() };
            long int rightSize { std::distance(startRight, endRight) };

            if (rightSize > 0) {
                std::rotate(startRight, startRight + (1 % rightSize), endRight);
            }
        }
        return *this;
    }
    vector<T> &operator<<(size_t index) {
        if (index > 0) {
            typename std::vector<T>::iterator \
                startLeft { this->begin() }, \
                endLeft { this->begin() + index };
            long int leftSize { std::distance(startLeft, endLeft) };

            if (leftSize > 0) {
                std::rotate(startLeft, endLeft - (3 % leftSize), endLeft);
            }
        }
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, const std::vector<T>& vec) {
        const typename std::vector<T>::const_iterator itEnd{ vec.cend() };
        for (typename std::vector<T>::const_iterator it { vec.cbegin() }; \
                it != itEnd; it++) out << *it << ' ';
        out << std::endl;
        return out;
    }
};

template<typename T>
class list : public std::list<T> {
public:
    list(std::initializer_list<T> il) : std::list<T>(il) {}

    list(const list<T> &listOld) {
        size_t size { listOld.size() };
        typename std::list<T>::const_iterator itEnd { listOld.cend() };
        switch (size % 3) {
            case 2: itEnd--;
            case 1: itEnd--;
        }
        for (typename std::list<T>::const_iterator it { listOld.cbegin() }; \
                it != itEnd; it++) ++it, ++it, this->push_back(*it);
    }

    friend std::ostream &operator<<(std::ostream &out, const std::list<T>& vec) {
        const typename std::list<T>::const_iterator itEnd{ vec.cend() };
        for (typename std::list<T>::const_iterator it { vec.cbegin() }; 
                it != itEnd; it++) out << *it << ' ';
        out << std::endl;
        return out;
    }
};


int main() {
    vector<int> vec {1, 2, 8, 5, 4, 3, 9, 6, 7};

    std::cout << "Исходный вектор: " << vec;

    size_t maxOddIndex { vec.calcMaxOddIndex() };

    if (maxOddIndex == -1) {
        std::cout << "В векторе нет нечетных чисел." << std::endl;
        return 0;
    }

    vec >> maxOddIndex << maxOddIndex;

    std::cout << "Итоговый вектор после сдвигов: " << vec;

    list<int> list1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    std::cout << "Исходный лист: " << list1;
    
    list<int> list2 { list1 };

    std::cout << "Конечный лист: " << list2;

    return 0;
}
