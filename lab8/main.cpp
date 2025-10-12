#include <iostream>
#include <string>

using u32 = unsigned int;

// Abstract Base Class: Organization
class Organization {
private:
    std::string m_name;
    u32 m_employeeCount;
    u32 m_clientCount;

public:
    Organization(const std::string &name = {}, \
            const u32 &employeeCount = 0, \
            const u32 &clientCount = 0) : \
        m_name{name}, m_employeeCount{employeeCount}, \
        m_clientCount{clientCount} {}

    u32 getEmployeeCount(void) const {
        return m_employeeCount;
    }
    u32 getClientCount(void) const {
        return m_clientCount;
    }
    std::string getName(void) const {
        return m_name;
    }
    void setEmployeeCount(u32 newEmployeeCount) {
        m_employeeCount = newEmployeeCount;
    }
    void setClientCount(u32 newClientCount) {
        m_clientCount = newClientCount;
    }
    void setName(std::string newName) {
        m_name = newName;
    }
    virtual void calculateCounts(void) = 0;
    friend std::ostream& operator<<(std::ostream& out, \
            const Organization& org) {
        out << "Name: " << org.m_name << ", Employees: " << \
            org.m_employeeCount << ", Clients: " << org.m_clientCount;
        return out;
    }
    friend std::istream& operator>>(std::istream& in, \
            Organization& org) {
        std::cout << "Enter name: ";
        in >> org.m_name;
        std::cout << "Enter number of employees: ";
        in >> org.m_employeeCount;
        std::cout << "Enter number of clients: ";
        in >> org.m_clientCount;
        return in;
    }
};

class InsuranceCompany : public Organization {
public:
    InsuranceCompany(const std::string& name = {}, \
            const u32 &employeeCount = 0) : \
    Organization{name, employeeCount, employeeCount / 8} {}
    void calculateCounts(void) override {
        setClientCount(getEmployeeCount() / 8);
    }
    friend std::ostream &operator<<(std::ostream &out, \
            const InsuranceCompany &insuranceCompany) {
        out << (const Organization&)insuranceCompany;
        return out;
    }
    friend std::istream &operator>>(std::istream &in, \
            InsuranceCompany &insuranceCompany) {
        in >> (Organization&)insuranceCompany;
        return in;
    }
};

class ShipbuildingCompany : public Organization {
public:
    ShipbuildingCompany(const std::string& name = {}, \
            const u32 &employeeCount = 0) : \
        Organization{name, employeeCount, employeeCount * 6} {}
    void calculateCounts(void) override {
        setClientCount(getEmployeeCount() * 6);
    }
    friend std::ostream &operator<<(std::ostream &out, \
            const ShipbuildingCompany &shipbuildingCompany) {
        out << (const Organization&)shipbuildingCompany;
        return out;
    }
    friend std::istream &operator>>(std::istream &in, \
            ShipbuildingCompany &shipbuildingCompany) {
        in >> (Organization&)shipbuildingCompany;
        return in;
    }
};

class Factory : public Organization {
public:
    Factory(const std::string& name, \
            const u32 &employeeCount) : \
        Organization{name, employeeCount, \
            employeeCount * 4 / 3} {}
    void calculateCounts(void) override {
       setClientCount(getEmployeeCount() * 4 / 3);
    }
    friend std::ostream &operator<<(std::ostream &out, \
            const Factory &factory) {
        out << (const Organization&)factory;
        return out;
    }
    friend std::istream &operator>>(std::istream &in, \
            Factory &factory) {
        in >> (Organization&)factory;
        return in;
    }
};

int main() {
    InsuranceCompany ins("Global Protect", 500);
    ShipbuildingCompany ship("Ocean Builders", 2000);
    Factory factory("Auto Parts Inc.", 1500);

    ins.calculateCounts();
    ship.calculateCounts();
    factory.calculateCounts();

    std::cout << "\n--- Initial Objects ---\n";
    std::cout << ins << std::endl;
    std::cout << ship << std::endl;
    std::cout << factory << std::endl;

    // Demonstrate operator overloading for input
    std::cout << "\n--- Input New Data for Insurance Company ---\n";
    std::cin >> ins;
    
    // Recalculate and display the new data
    ins.calculateCounts();
    std::cout << "\n--- Updated Insurance Company ---\n";
    std::cout << ins << std::endl;

    return 0;
}
