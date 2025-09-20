#include <string>
#include <ostream>
#include <list>
#include <iostream>

template<typename Tp>
bool isRepeat(std::list<Tp>& list) {
    typename std::list<Tp>::iterator itEnd{ list.end() };
    for (typename std::list<Tp>::iterator it1{ list.begin() }; 
        it1 != itEnd; it1++)
        for (typename std::list<Tp>::iterator it2{ next(it1) }; 
            it2 != itEnd; it2++)
            if (*it1 == *it2) return true;
    return false;
}

template<typename Tp>
std::list<Tp>& endToBegin(std::list<Tp>& list) {
    list.begin() = list.end();
    return list;
}

template<typename Tp>
void test(std::list<Tp>& vec) {
    std::cout << isRepeat(vec) << std::endl;
    std::cout << endToBegin(vec) << std::endl;
}

template<typename Tp>
std::ostream& operator<<(std::ostream& out,
    const std::list<Tp>& list) {
    typename std::list<Tp>::const_iterator itEnd{ list.cend() };
    for (typename std::list<Tp>::const_iterator it{ list.cbegin() };
        it != itEnd; it++) out << *it << ' ';
    out << std::endl;
    return out;
}

int main(void) {
    std::list<int> vec1{ 1, 3, 4, 9 };
    std::list<int> vec2{ 1, 3, 4, 9, 3 };
    std::list<std::list<int>> vec3{ {1, 3, 4}, {9, 3} };
    std::list<std::string> vec4{ "kl", "alds", "psdf", "djkl", "owpk," };
    std::list<std::string> vec5{ "kl", "alds", "psdf", "djkl", "owpk,", "kl" };
    std::list<std::list<std::string>> vec6{ {"kl", "alds", "psdf", }, {"djkl", "owpk,", "kl"} };
    test(vec1); test(vec2); test(vec3); test(vec4); test(vec5); test(vec6);
    return 0;
}


