#include <iostream>
#include <string>
#include <vector>
using u8 = unsigned char;

template<typename T>
std::ostream& operator<<(std::ostream& out, \
    const std::vector<T> &set) {
    const typename std::vector<T>::const_iterator itEnd { set.cend() };
    out << '{';
    for (typename std::vector<T>::const_iterator it{ set.cbegin() }; \
        it != itEnd; it++) out << *it << ", ";
    out << '}';
    return out;
}

class Time {
private:
    u8 _hours{ 0 }, _minutes{ 0 }, _seconds{ 0 };
public:
    Time(u8 hours = 0, u8 minutes = 0, \
        u8 seconds = 0) : _hours{ hours }, \
        _minutes{ minutes }, _seconds{ seconds } {}
    u8 getHours(void) const  { return _hours; }
    u8 getMinutes(void) const  { return _minutes; }
    u8 getSeconds(void) const { return _seconds; }
    void setHours(u8 hours) { _hours = hours; }
    void setMinutes(u8 minutes) { _minutes = minutes; }
    void setSeconds(u8 seconds) { _seconds = seconds; }
    friend std::ostream& operator<<(std::ostream& out, \
        const Time& time) {
        out << "Time:" << &time << " { hours = " << (short)time._hours << \
            ", minutes = " << (short)time._minutes << ", seconds = " << \
            (short)time._seconds << " }";
        return out;
    }
};
class Schedule {
private:
    Time _dayBegin{}, _dayEnd{}, \
        _dinnerBegin{}, _dinnerEnd{}; // Агрегация Ассоциация Зависимость
public:
    Schedule(void) : _dayBegin{}, _dayEnd{}, \
        _dinnerBegin{}, _dinnerEnd{} {}
    Schedule(Time dayBegin = Time{}, Time dayEnd = Time{}, \
        Time dinnerBegin = Time{}, Time dinnerEnd = Time{}) : \
        _dayBegin{ dayBegin }, _dayEnd{ dayEnd }, \
        _dinnerBegin{ dayBegin }, _dinnerEnd{ dinnerEnd } {}
    Schedule(const Schedule &schedule) : _dayBegin{ schedule._dayBegin }, \
        _dayEnd{ schedule._dayEnd }, _dinnerBegin{ schedule._dinnerBegin }, \
        _dinnerEnd{ schedule._dinnerEnd } {}
    Time getDayBegin(void) const { return _dayBegin; }
    Time getDayEnd(void) const { return _dayEnd; }
    Time getDinnerBegin(void) const { return _dinnerBegin; }
    Time getDinnerEnd(void) const { return _dinnerEnd; }
    void setDayBegin(Time dayBegin) { _dayBegin = dayBegin; }
    void setDayEnd(Time dayEnd) { _dayEnd = dayEnd; }
    void setDinnerBegin(Time dinnerBegin) { _dinnerBegin = dinnerBegin; }
    void setDinnerEnd(Time dinnerEnd) { _dinnerEnd = dinnerEnd; }
    friend std::ostream& operator<<(std::ostream& out, \
        const Schedule& schedule) {
        out << "Schedule:" << &schedule << " { day begin = " << \
            schedule._dayBegin << ", day end = " << schedule._dinnerBegin << \
            ", dinner begin = " << schedule._dinnerBegin << ", dinner end = " << \
            schedule._dinnerEnd << " }";
        return out;
    }
};

class Worker {
private:
    std::vector<Schedule> _schedule; // Агрегация Ассоциация Зависимость
public:
    Worker(void) : _schedule{} {}
    Worker(std::vector<Schedule> schedule) : \
        _schedule{ schedule } {}
    Worker(const Worker &worker) : \
        _schedule{ worker._schedule} {}
    size_t addSchedule(Schedule newSchedule) {
        _schedule.push_back(newSchedule);
        return _schedule.size() - 1;
    }
    void removeSchedule(size_t index) {
        _schedule.erase(_schedule.begin() + index);
    }
    Schedule operator[](size_t index) {
        return _schedule[index];
    }
    friend std::ostream& operator<<(std::ostream& out, \
        const Worker& worker) {
        out << "Worker:" << &worker << " { schedule = " << worker._schedule << " }";
        return out;
    }
};

class Product {
private:
    unsigned _weight;
    std::string _name; // Агрегация Ассоциация Зависимость
public:
    Product(void) : _weight{ 0 }, _name{ "" } {}
    Product(unsigned weight, std::string name) : \
        _weight{ weight }, _name{ name } {}
    Product(const Product &product) : \
        _weight{ product._weight }, \
        _name { product._name } {}
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
    friend std::ostream& operator<<(std::ostream& out, \
        const Product& product) {
        out << "Product:" << &product << " { weight = " << product._weight << \
            ", name = " << product._name << " }";
        return out;
    }
};

class Order {
private:
    unsigned _number;
    std::vector<Product> _products; // Агрегация Ассоциация Зависимость
public:
    Order(void) : _number{ 0 }, _products{} {}
    Order(unsigned number, \
        std::vector<Product> products) : \
        _number{ number }, _products{ products } {}
    Order(const Order &order) : _number{ order._number }, \
        _products{ order._products } {}
    unsigned getNumber(void) const {
        return _number;
    }
    void setNumber(unsigned newNumber) {
        _number = newNumber;
    }
    size_t addProduct(Product newProduct) {
        _products.push_back(newProduct);
        return _products.size() - 1;
    }
    Product operator[](size_t index) {
        return _products[index];
    }
    void removeProduct(size_t index) {
        _products.erase(_products.begin() + index);
    }
    friend std::ostream& operator<<(std::ostream &out, \
        const Order& order) {
        out << "Order:" << &order << " { number = " << order._number << \
            ", products = " << order._products << " }";
        return out;
    }
};

class Buyer {
private:
    long long int _numberCreaditCart{ 0 };
    std::string _name;
    std::vector<Order> _orders; // Агрегация Ассоциация Зависимость
public:
    Buyer(void) : _numberCreaditCart{ 0 }, \
        _name{}, _orders{} {}
    Buyer(long long int numberCreaditCart, \
        std::string name, std::vector<Order> orders) : \
        _numberCreaditCart{ numberCreaditCart }, \
        _name{ name }, _orders{ orders } {}
    Buyer(const Buyer &buyer) : _numberCreaditCart{ \
        buyer._numberCreaditCart }, _name{ buyer._name }, \
        _orders{ buyer._orders } {}
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
    size_t addOrder(Order order) {
        _orders.push_back(order);
        return _orders.size() - 1;
    }
    Order operator[](size_t index) {
        return _orders[index];
    }
    void removeOrder(size_t index) {
        _orders.erase(_orders.begin() + index);
    }
    friend std::ostream& operator<<(std::ostream& out, \
        const Buyer &buyer) {
        out << "Buyer:" << &buyer << " { name = " << buyer._name << ", number credit cart = " << 
            buyer._numberCreaditCart << ", orders = " << buyer._orders << " }";
        return out;
    }
};

class Delivery {
private:
    Order _order; // Агрегация Ассоциация Зависимость
    Buyer _buyer;
    Worker _worker;
public:
    Delivery(void) : _order{}, _buyer{}, _worker{} {}
    Delivery(Order order, Buyer buyer, Worker worker) : \
        _order{ order }, _buyer{ buyer }, \
        _worker{ worker } {}
    Delivery(Delivery &delivery) : \
        _order{delivery._order}, _buyer{delivery._buyer}, \
        _worker{ delivery._worker } {}
    void setOrder(Order order) {
        _order = order;
    }
    void setBuyer(Buyer buyer) {
        _buyer = buyer;
    }
    Order getOrder(void) const {
        return _order;
    }
    Buyer getBuyer(void) const {
        return _buyer;
    }
    friend std::ostream& operator << (std::ostream& out, \
        const Delivery& delivery) {
        out << "Delivary: { order = " << delivery._order << ", buyer = " 
            << delivery._buyer << ", worker = " << delivery._worker << '}';
        return out;
    }
};

int main(void) {
    Product product {9, "tomat"};
    Order order {8, {product}};
    Buyer buyer {19, "name", {order}};
    Worker worker {{{9, 0, 0}, {17, 0, 0}, {12, 0, 0}, {13, 0, 0}}};
    Delivery delivery{order, buyer, worker};
    std::cout << delivery << std::endl;
    return 0;
}
