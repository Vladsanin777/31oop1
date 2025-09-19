#include <iostream>
#include <istream>
#include <ostream>
#include <string>

class Organization {
public:
    virtual ~Organization() = default;
    virtual int getEmployeeCount() const = 0;
    virtual int getClientCount() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
};

template<typename Tp>
std::ostream& operator<<(std::ostream& os, const Tp& org) {
    org.print(os);
    return os;
}

template<typename Tp>
std::istream& operator>>(std::istream& is, Tp& org) {
    org.read(is);
    return is;
}

class InsuranceCompany : public Organization {
    int employees;
    int clients;
    std::string name;

public:
    InsuranceCompany() : employees(0), clients(0), name("") {}
    InsuranceCompany(int emp, int cli, const std::string& n) : \
        employees(emp), clients(cli), name(n) {}

    int getEmployeeCount() const override { return employees; }
    int getClientCount() const override { return clients; }

    void print(std::ostream& os) const override {
        os << "Insurance Company: " << name 
           << ", Employees: " << employees 
           << ", Clients: " << clients;
    }

    void read(std::istream& is) override {
        std::cout << "Enter name: ";
        getline(is, name);
        std::cout << "Enter employees: ";
        is >> employees;
        std::cout << "Enter clients: ";
        is >> clients;
        is.ignore();
    }
};

class ShipbuildingCompany : public Organization {
    int employees;
    int clients;
    int shipsBuilt;

public:
    ShipbuildingCompany(int emp = 0, int cli = 0, int ships = 0) : \
        employees(emp), clients(cli), shipsBuilt(ships) {}

    int getEmployeeCount() const override { return employees; }
    int getClientCount() const override { return clients; }

    void print(std::ostream& os) const override {
        os << "Shipbuilding Company: " 
           << ", Employees: " << employees 
           << ", Clients: " << clients 
           << ", Ships Built: " << shipsBuilt;
    }

    void read(std::istream& is) override {
        std::cout << "Enter employees: ";
        is >> employees;
        std::cout << "Enter clients: ";
        is >> clients;
        std::cout << "Enter ships built: ";
        is >> shipsBuilt;
        is.ignore();
    }
};

class Factory : public Organization {
    int employees;
    int clients;
    std::string product;

public:
    Factory() : employees(0), clients(0), product("") {}
    Factory(int emp, int cli, const std::string& prod) : \
        employees(emp), clients(cli), product(prod) {}

    int getEmployeeCount() const override { return employees; }
    int getClientCount() const override { return clients; }

    void print(std::ostream& os) const override {
        os << "Factory: Product: " << product 
           << ", Employees: " << employees 
           << ", Clients: " << clients;
    }

    void read(std::istream& is) override {
        std::cout << "Enter product: ";
        getline(is, product);
        std::cout << "Enter employees: ";
        is >> employees;
        std::cout << "Enter clients: ";
        is >> clients;
        is.ignore();
    }
};

int main() {
    InsuranceCompany ic;
    std::cin >> ic;
    std::cout << ic << std::endl;
    std::cout << "Employees: " << ic.getEmployeeCount() << \
        ", Clients: " << ic.getClientCount() << std::endl;

    ShipbuildingCompany sc;
    std::cin >> sc;
    std::cout << sc << std::endl;

    Factory f;
    std::cin >> f;
    std::cout << f << std::endl;

    return 0;
}
