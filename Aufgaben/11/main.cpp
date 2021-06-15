//
// Created by basti on 02.06.2021.
//

#include <string>
#include <iostream>
#include <cassert>
#include <memory>

namespace hfu_09 {
    class Person {
    private:
        int id;
        std::string last_name, first_name;
    public:
        int getId() const {
            return id;
        }

        const std::string &getLastName() const {
            return last_name;
        }

        const std::string &getFirstName() const {
            return first_name;
        }

        Person(int id, const std::string &lastName, const std::string &firstName) : id(id), last_name(lastName),
                                                                                    first_name(firstName) {};
    };

    class Guest : public Person {
    private:
        int days, room_rate;
    public:
        int getDays() const {
            return days;
        }

        int getRoomRate() const {
            return room_rate;
        }

        int check() {
            return days * room_rate;
        }

        Guest(int id, const std::string &lastName, const std::string &firstName, int days, int roomRate) : Person(id,
                                                                                                                  lastName,
                                                                                                                  firstName),
                                                                                                           days(days),
                                                                                                           room_rate(
                                                                                                                   roomRate) {}
    };

    //Sollte imho abstract sein, wenn die salary-methode eh quasi nichts macht
    class Employee : public Person {
    public:
        virtual int salary() {
            std::cout << "Employee salary()" << std::endl;
            return 0;
        }

        virtual ~Employee() = default;

        Employee(int id, const std::string &lastName, const std::string &firstName) : Person(id, lastName, firstName) {}
    };

    class Worker : public Employee {
    private:
        int hourly_rate, hours_worked;
    public:
        int salary() override {
            std::cout << "Worker salary()" << std::endl;
            return hourly_rate * hours_worked;
        }

        int getHourlyRate() const {
            return hourly_rate;
        }

        int getHoursWorked() const {
            return hours_worked;
        }

        Worker(int id, const std::string &lastName, const std::string &firstName, int hourlyRate, int hoursWorked)
                : Employee(id, lastName, firstName), hourly_rate(hourlyRate), hours_worked(hoursWorked) {}
    };

    class Seller : public Employee {
    private:
        int pay, commission;
    public:
        int salary() override {
            std::cout << "Seller salary()" << std::endl;
            return pay + commission;
        }

        int getPay() const {
            return pay;
        }

        int getCommission() const {
            return commission;
        }

        Seller(int id, const std::string &lastName, const std::string &firstName, int pay, int commission) : Employee(
                id, lastName, firstName), pay(pay), commission(commission) {}
    };

    void test_1_a() {
        std::cout << " --- Test 1a start --- " << std::endl;

        auto employee = new Employee(4, "Duck", "Tick");
        assert(employee->salary() == 0);
        auto worker = new Worker(4, "Duck", "Tick", 9, 40);
        employee = worker;
        assert(employee->salary() == 9 * 40);
        auto seller = new Seller(5, "Duck", "Trick", 1000, 2000);
        employee = seller;
        assert(employee->salary() == 1000+2000);

        std::cout << " --- Test 1d end --- " << std::endl;
    }

    void test_3() {
        std::cout << " --- Test 3 start --- " << std::endl;

        auto employee = std::make_shared<Employee>(4, "Duck", "Tick");
        assert(employee->salary() == 0);
        auto worker = std::make_shared<Worker>(4, "Duck", "Tick", 9, 40);
        employee = worker;
        assert(employee->salary() == 9 * 40);
        auto seller = std::make_shared<Seller>(5, "Duck", "Trick", 1000, 2000);
        employee = seller;
        assert(employee->salary() == 1000+2000);

        // Wenn kein virtual destructor: "destructor called on non-final 'hfu_09::Employee' that has virtual functions but non-virtual destructor"

        std::cout << " --- Test 3 end --- " << std::endl;
    }
}

int main() {

    std::cout << "starting..." << std::endl;

    hfu_09::test_1_a();
    hfu_09::test_3();

    std::cout << "terminating..." << std::endl;

    return 0;
}
