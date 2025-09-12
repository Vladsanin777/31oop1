#include <multiset>
#include <ostream>
#include <iostream>

template<typename Tp>
void subSumMinAndMax(std::multiset<Tp> &multiset) {
    Tp sum {*multiset.begin() + *multiset.end()};
    for (auto &element : multiset)
        element -= sum;
}

template<typename Tp>
std::ostream &operator<<(std::ostream &out, 
        std::multiset<Tp> &multiset) {
    for (auto &element : multiset)
        out << element << ' ';
    out << std::endl;
    return out;
}

int main(void) {
    int rmElement {123};
    std::multiset<int> multiset1 {10, 100, 1, 8, 9, rmElement};
    std::cout << multiset1 << std::endl;
    multiset1.erase(rmElement);
    multiset1.erase(multiset1.begin());
    subSumMinAndMax(multiset1);
    std::cout << multiset1 << std::endl;
    return 0;
}
