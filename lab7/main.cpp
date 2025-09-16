using u8 = unsigned char;

class Time {
private:
    u8 _hours{0}, _minutes{0}, _seconds{0};
public:
    Time(u8 hours = 0, u8 minutes = 0, \
        u8 seconds = 0) : _hours{hours}, \
        _minutes{minutes}, _seconds{seconds} {}
    u8 getHours(void) { return _hours; }
    u8 getMinutes(void) { return _minutes; }
    u8 getSeconds(void) { return _seconds; }
    void setHours(u8 hours) { _hours = hours; }
    void setMinutes(u8 minutes) { _minutes = minutes; }
    void setSeconds(u8 seconds) { _seconds = seconds; }
};
class Schedule {
private:
    Time _dayBegin{}, _dayEnd{}, \
        _dinnerBegin{}, _dinnerEnd{};
public:
    Schedule(Time dayBegin, Time dayEnd, \
            Time dinnerBegin, Time dinnerEnd) : \
            _dayBegin{dayBegin}, _dayEnd{dayEnd}, \
            _dinnerBegin{dayBegin}, _dinnerEnd{dinnerEnd} {}
    Time getDayBegin(void) { return _dayBegin; }
    Time getDayEnd(void) { return _dayEnd; }
    Time getDinnerBegin(void) { return _dinnerBegin; }
    Time getDinnerEnd(void) { return _dinnerEnd; }
    void setDayBegin(Time dayBegin) { _dayBegin = dayBegin; }
    void setDayEnd(Time dayEnd) { _dayEnd = dayEnd; }
    void setDinnerBegin(Time dinnerBegin) { _dinnerBegin = dinnerBegin; }
    void setDinnerEnd(Time dinnerEnd) { _dinnerEnd = dinnerEnd; }
};
