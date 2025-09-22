#include <string>
#include <ostream>
#include <iostream>
#include <iterator>
#include <queue>
#include <deque>


using u8 = unsigned char;
using u16 = unsigned short;

class event {
private:
    u8 _day, _month;
    u16 _year;
    std::string _label;
public:
    event(u8 day, u8 month = 0, u16 year = 0, \
            std::string label = {}) : _day{day}, \
            _month{month}, _year{year}, _label{label} {}
    event() : _day{0}, _month{0}, _year{0}, _label{""} {}
    event(const event &eventOld) : _day{eventOld._day}, \
        _month{eventOld._month}, _year{eventOld._year}, \
        _label{eventOld._label} {}
    u8 getDay(void) const {
        return _day;
    }
    u8 getMonth(void) const {
        return _month;
    }
    u8 getYear(void) const {
        return _year;
    }
    std::string getLabel(void) const {
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
    void setLabel(const std::string &label) {
        _label = label;
    }
    friend std::ostream &operator<<(std::ostream &out, const event &event1) {
        out << "event address: " << &event1 << ", day: " << (short)event1._day << \
            ", month: " << (short)event1._month << ", year: " << event1._year << \
            ", label: " << event1._label << std::endl;
        return out;
    }
};

class deque : public std::deque<event> {
public:
    deque(std::initializer_list<event> il) : std::deque<event>() {}
    deque searchDay(const u8 &day) const {
        deque result{};
        const typename std::deque<event>::const_iterator itEnd { this->cend() };
        for (typename std::deque<event>::const_iterator it { this->cbegin() }; \
            it != itEnd; it++) if ((*it).getDay() == day) result.push_back(*it);
        return result;
    }
    deque searchMonth(const u8 &month) const {
        deque result{};
        const typename std::deque<event>::const_iterator itEnd { this->cend() };
        for (typename std::deque<event>::const_iterator it { this->cbegin() }; \
            it != itEnd; it++) if ((*it).getMonth() == month) result.push_back(*it);
        return result;
    }
    deque searchYear(const u16 &year) const {
        deque result{};
        const typename std::deque<event>::const_iterator itEnd { this->cend() };
        for (typename std::deque<event>::const_iterator it { this->cbegin() }; \
            it != itEnd; it++) if ((*it).getYear() == year) result.push_back(*it);
        return result;
    }
    deque searchLabel(const std::string &label) const {
        deque result{};
        const typename std::deque<event>::const_iterator itEnd { this->cend() };
        for (typename std::deque<event>::const_iterator it { this->cbegin() }; \
            it != itEnd; it++) if ((*it).getLabel() == label) result.push_back(*it);
        return result;
    }
    friend std::ostream &operator<<(std::ostream &out, const deque &deque1) {
        out << "deque address: " << &deque1 << std::endl;
        const typename std::deque<event>::const_iterator itEnd { deque1.cend() };
        for (typename std::deque<event>::const_iterator it { deque1.cbegin() }; \
            it != itEnd; it++) out << *it;
        out << std::endl;
        return out;
    }
};

int main(void) {
    deque deque1 {};
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
