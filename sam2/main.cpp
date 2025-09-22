#include <list>
#include <ostream>
#include <iostream>

template<typename T>
class list : public std::list<T> {
public:
    list(std::initializer_list<T> il) : std::list<T>(il) {}

    list(const list<T> &listOld) {
        size_t size { listOld.size() };
        typename std::list<T>::const_iterator itEnd { listOld.cend() };
        switch (size % 2) {
            case 1: itEnd--;
        }
        for (typename std::list<T>::const_iterator it { listOld.cbegin() }; \
                it != itEnd; it++) ++it, this->push_back(*it);
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
    list<int> list1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    std::cout << "Исходный лист: " << list1;
    
    list<int> list2 { list1 };

    std::cout << "Конечный лист: " << list2;

    return 0;
}
