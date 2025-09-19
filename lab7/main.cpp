#include <string>
#include <set>
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
    Schedule(Time dayBegin = Time{}, Time dayEnd = Time{}, \
            Time dinnerBegin = Time{}, Time dinnerEnd = Time{}) : \
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

class Worker {
    std::set<Schedule *> _schedule;
    Worker(std::set<Schedule *> schedule = {}) : \
        _schedule{schedule} {}
    void addSchedule(Schedule *newSchedule) {
        _schedule.insert(newSchedule);
    }
    void removeSchedule(Schedule *removeSchedule) {
        _schedule.erase(removeSchedule);
    }
};

class Product {
    unsigned _weight;
    std::string _name;
    Product(unsigned weight, std::string name) : \
        _weight{weight}, _name{name} {}
    void setWeight(unsigned newWeight) {
        _weight = newWeight;
    }
    void setName(std::string newName) {
        _name = newName;
    }
    unsigned getWeight(void) const {
        return _weight;
    }
    std::string getName(void) {
        return _name;
    }
};

class Order {
    unsigned _number;
    std::set<Product *> _products;
    Order(unsigned number, \
            std::set<Product *> product = {}) : \
        _number{number}, _products{product} {}
    unsigned getNumber(void) {
        return _number;
    }
    void setNumber(unsigned newNumber) {
        _number = newNumber;
    }
    void addProduct(Product *newProduct) {
        _products.insert(newProduct);
    }
    void removeProduct(Product *product) {
        _products.erase(product);
    }
};

class Buyer {
    long long int _numberCreaditCart{0};
    std::string _name;
    std::set<Order *> _orders;
    Buyer(long long int numberCreaditCart = 0, \
        std::string name = "") : _numberCreaditCart{ \
        numberCreaditCart}, _name{name} {}
    void setName(std::string newName) {
        _name = newName;
    }
    std::string getName(void) const {
        return _name;
    }
    void setNumberCreditCart(long long int \
            newNumberCreaditCart) {
        _numberCreaditCart = newNumberCreaditCart;
    }
    long long int getNumberCreditCart(void) const {
        return _numberCreaditCart;
    }
    void addOrder(Order *order) {
        _orders.insert(order);
    }
    void removeOrder(Order *order) {
        _orders.erase(order);
    }
};

class Delivery {
    Order * _order;
    Buyer * _buyer;
    Delivery(Order * order, Buyer * buyer) : \
        _order{order}, _buyer{buyer} {}
    void setOrder(Order * order) {
        _order = order;
    }
    void setBuyer(Buyer * buyer) {
        _buyer = buyer;
    }
    Order * getOrder(void) const {
        return _order;
    }
    Buyer * getBuyer(void) const {
        return _buyer;
    }
};

int main(void) {
    return 0;
}
