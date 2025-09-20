#include <iostream>
#include <set>
#include <algorithm>

template <typename T>
class Set : public std::set<T> {
public:
    Set() = default;

    Set(const std::set<T>& s) : std::set<T>(s) {}

    Set<T> operator+(const Set<T>& other) const {
        Set<T> newSet = *this; // Копируем текущее множество
        newSet.insert(other.begin(), other.end());
        return newSet;
    }
    bool operator==(const Set<T>& other) const {
        return static_cast<const std::set<T>&>(*this) == \
            static_cast<const std::set<T>&>(other);
    }
    bool operator!=(const Set<T>& other) const {
        return !(*this == other);
    }
    friend std::ostream &operator<<( \
            std::ostream &out, const Set<T> &set) {
        out << "set address: " << &set << ": { ";
        typename std::set<T>::const_iterator itEnd { set.cend() };
        for (typename std::set<T>::const_iterator it { set.cbegin() }; \
                it != itEnd; it++) std::cout << *it << " ";
        out << "}" << std::endl;
        return out;
    }
    friend Set<T> operator+(const T& item, const Set<T>& mySet) {
        Set<T> newSet = mySet;
        newSet.insert(item);
        return newSet;
    }
};

int main() {
    // Создаем два множества
    Set<int> setA;
    setA.insert(1);
    setA.insert(2);
    setA.insert(3);
    std::cout << "Set A: " << setA;

    Set<int> setB;
    setB.insert(3);
    setB.insert(4);
    setB.insert(5);
    std::cout << "Set B: " << setB;

    Set<int> unionSet = setA + setB;
    std::cout << "\nSet A + Set B (Union): " << unionSet;

    Set<int> newSetC = 6 + unionSet;
    std::cout << "\n6 + (Set A + Set B): " << newSetC;

    Set<int> setD;
    setD.insert(2);
    setD.insert(1);
    setD.insert(3);

    std::cout << "\nIs Set A equal to Set D? " << (setA == setD ? "Yes" : "No") << std::endl;
    std::cout << "Is Set A equal to Set B? " << (setA == setB ? "Yes" : "No") << std::endl;

    return 0;
}
