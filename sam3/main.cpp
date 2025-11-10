#include <string>
#include <ostream>
#include <iostream>
#include <iterator>
#include <queue>
#include <deque>
#include <cstring>


using u8 = unsigned char;
using u16 = unsigned short;

class event {
private:
    u8 _day, _month;
    u16 _year;
    char _label[50];
public:
    event(u8 day, u8 month = 0, u16 year = 0, \
            const char * label = "") : _day{day}, \
            _month{month}, _year{year}, _label{} {
        strcpy(_label, label);
    }
    event() : _day{0}, _month{0}, _year{0}, _label{""} {}
    event(const event &eventOld) : _day{eventOld._day}, \
        _month{eventOld._month}, _year{eventOld._year}, \
        _label{} {strcpy(_label, eventOld._label);}
    u8 getDay(void) const {
        return _day;
    }
    u8 getMonth(void) const {
        return _month;
    }
    u8 getYear(void) const {
        return _year;
    }
    const char * getLabel(void) const {
        return _label;
    }
    void setDay(const u8 &day) {
        _day = day;
    }
    void setMonth(const u8 &month) {
        _month = month;
    }
    void setYear(const u16 &year) {
        _year = year;
    }
    friend std::ostream &operator<<(std::ostream &out, const event &event1) {
        out << "event address: " << &event1 << ", day: " << (short)event1._day << \
            ", month: " << (short)event1._month << ", year: " << event1._year << \
            ", label: " << ((strlen(event1._label) == 0) ? "\"\"" : event1._label) << std::endl;
        return out;
    }
};

template<typename T>
class deque {
private:
    size_t _size{0};
    T *_arr{nullptr};
public:
    deque(void) : _size{0}, _arr{nullptr} {}
    deque(T* arr, size_t size) : _size{size}, _arr{malloc(sizeof(T) * size)} {
        _arr = (T*)memcpy((char *)_arr, (char *)arr, sizeof(T) * size);
    }
    deque(const deque<T> &deq) : _size{deq._size}, \
            _arr{(T *)malloc(sizeof(T) * deq._size)} {
        _arr = (T*)memcpy((char *)_arr, (char *)deq._arr, sizeof(T) * deq._size);
    }
    deque<T> searchDay(const u8 &day) const {
        deque<T> result{};
        const T* const itEnd { end() };
        for (const T *it { begin() }; \
            it != itEnd; it++) if ((*it).getDay() == day) result.push_back(*it);
        return result;
    }
    void push_back(T newVal) {
        size_t oldSize {_size};
        resize(_size+1);
        _arr[oldSize] = newVal;
    }
    void push_top(T newVal) {
        resize(_size+1);
        memcpy(_arr + 1, _arr, sizeof(T) * _size - 1);
        *_arr = newVal;
    }
    T pop_back(void) {
        T ret {_arr[_size-1]};
        resize(_size-1);
        return ret;
    }
    T pop_top(void) {
        T ret {_arr[0]};
        memcpy(_arr, _arr + 1, _size - 1);
        resize(_size-1);
        return ret;
    }
    const T *end(void) const {
        return _arr + _size;
    }
    const T *begin(void) const {
        return _arr;
    }
    bool empty(void) {
        return !_size;
    }
    deque<T> searchMonth(const u8 &month) const {
        deque<T> result{};
        const T* const itEnd { end() };
        for (const T *it{ begin() }; \
            it != itEnd; it++) if ((*it).getMonth() == month) result.push_back(*it);
        return result;
    }
    deque<T> searchYear(const u16 &year) const {
        deque<T> result{};
        const T* const itEnd { end() };
        for (const T *it{begin()}; \
            it != itEnd; it++) if ((*it).getYear() == year) result.push_back(*it);
        return result;
    }
    deque<T> searchLabel(const char *label) const {
        deque<T> result{};
        const T* const itEnd { end() };
        for (const T *it{begin()}; \
            it != itEnd; it++) if (!strcmp(it->getLabel(), label)) result.push_back(*it);
        return result;
    }

    friend std::ostream &operator<<(std::ostream &out, const deque<T> &deque1) {
        out << "deque address: " << &deque1 << std::endl;
        const T* const itEnd { deque1.end() };
        for (const T * it {deque1.begin()}; \
            it != itEnd; it++) out << *it;
        out << std::endl;
        return out;
    }
    ~deque(void) {
        if (_arr) free(_arr);
    }
private:
    void resize(size_t newSize) {
        _size = newSize;
        _arr = (T *)realloc(_arr, sizeof(T) * newSize);
    }
};

int main(void) {
    deque<event> deque1 {};
    deque1.push_back(event{}); deque1.push_back(event{20, 5, 2008, "jk"});
    deque1.push_back({12, 2, 3032, "al"}); deque1.push_back(event{});
    std::cout << "deque orig: " << deque1 << std::endl;
    deque1.push_back(event{}); deque1.push_back(event{}); 
    deque1.push_back(event{}); deque1.push_back(event{}); 
    deque1.push_back({12, 2, 3032, "al"}); deque1.push_back(event{});
    deque1.pop_back();
    std::cout << "deque res: " << deque1 \
        << "search 0 day: " << deque1.searchDay(0) \
        << ", search 0 month: " << deque1.searchMonth(0) \
        << ", search 0 year: " << deque1.searchYear(0) \
        << ", search \"\" label: " << deque1.searchLabel("") << std::endl;
    return 0;
}
