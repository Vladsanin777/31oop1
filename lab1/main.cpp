#include <string>
#include <ostream>
#include <vector>
#include <iostream>

template<typename Tp>
bool isRepeat(const std::vector<Tp> &vec) {
    const auto itEnd {vec.end()};
    for (auto it1 {vec.begin()}; it1 < itEnd; it1++)
        for (auto it2 {it1+1}; it2 < itEnd; it2++)
            if (*it1 == *it2) return true;
    return false;
}

template<typename Tp>
std::vector<Tp> &endToBegin(std::vector<Tp> &vec) {
    vec.at(0) = vec.back();
    return vec;
}

template<typename Tp>
void test(std::vector<Tp> &vec) {
    std::cout << isRepeat(vec) << std::endl;
    std::cout << endToBegin(vec) << std::endl;
}

template<typename Tp>
std::ostream &operator<<(std::ostream& out,
        const std::vector<Tp> &vec) {
    for (const auto& element : vec)
        out << element << ' ';
    out << std::endl;
    return out;
}

int main(void) {
    std::vector<int> vec1{1, 3, 4, 9};
    std::vector<int> vec2{1, 3, 4, 9, 3};
    std::vector<std::verctor<int>> vec3{{1, 3, 4}, {9, 3}};
    std::vector<std::string> vec4{"kl", "alds", "psdf", "djkl", "owpk,"};
    std::vector<std::string> vec5{"kl", "alds", "psdf", "djkl", "owpk,", "kl"};
    std::vector<std::vector<std::string>> vec6{{"kl", "alds", "psdf", }, {"djkl", "owpk,", "kl"}};
    test(vec1); test(vec2); test(vec3); test(vec4); test(vec5); test(vec6);
    return 0;
}
