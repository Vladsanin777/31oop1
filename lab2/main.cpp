#include <ostream>
#include <iostream>
#include <set>
#include <iterator>


template<typename Tp>
std::multiset<Tp>& subSumMinAndMax(std::multiset<Tp>& multiset) {
    Tp sum{ *multiset.begin() + *(--multiset.end()) };
    std::multiset<Tp> newMultiset{};
    typename std::multiset<Tp>::iterator itEnd{ multiset.end() };
    for (typename std::multiset<Tp>::iterator it{ multiset.begin() };
        it != itEnd; it++) newMultiset.insert(*it - sum);
    multiset = newMultiset;
    return multiset;
}

template<typename Tp>
std::ostream& operator<<(std::ostream& out,
    std::multiset<Tp>& multiset) {
    typename std::multiset<Tp>::iterator itEnd{ multiset.end() };
    for (typename std::multiset<Tp>::iterator it { multiset.begin() }; \
        it != itEnd; it++) out << *it << ' ';
    out << std::endl;
    return out;
}

int main(void) {
    int rmElement{ 123 };
    std::multiset<int> multiset1{ 10, 100, 1, 8, 9, rmElement };
    std::cout << multiset1 << std::endl;
    multiset1.erase(rmElement);
    multiset1.erase(multiset1.begin());
    subSumMinAndMax(multiset1);
    std::cout << multiset1 << std::endl;
    return 0;
}