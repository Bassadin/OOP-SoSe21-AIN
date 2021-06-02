//
// Created by basti on 02.06.2021.
//

#include <string>
#include <iostream>
#include <cassert>

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
        int salary() {
            std::cout << "Employee salary()" << std::endl;
            return 0;
        }

        Employee(int id, const std::string &lastName, const std::string &firstName) : Person(id, lastName, firstName) {}
    };

    class Worker : public Employee {
    private:
        int hourly_rate, hours_worked;
    public:
        int salary() {
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
        int salary() {
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

    void test_1_d() {
        std::cout << " --- Test 1d start --- " << std::endl;

        Guest donaldGuest = Guest(0, "Duck", "Donald", 7, 200);
        assert(donaldGuest.getId() == 0);
        assert(donaldGuest.getFirstName() == "Donald");
        assert(donaldGuest.getLastName() == "Duck");
        assert(donaldGuest.getDays() == 7);
        assert(donaldGuest.getRoomRate() == 200);
        assert(donaldGuest.check() == 1400);

        std::cout << " --- Test 1d end --- " << std::endl;
    }

    void test_1_e() {
        std::cout << " --- Test 1e start --- " << std::endl;

        Guest donaldGuest = Guest(0, "Duck", "Donald", 7, 200);
        Person person = donaldGuest;

        //Joa, geht
        assert(person.getFirstName() == "Donald");

        std::cout << " --- Test 1e end --- " << std::endl;
    }

    // 1e) Ich denke, es ist sinnvoll, Guest aus Person abzuleiten, da hier eine Ist-Ein-Beziehung besteht. Auch ein Gast sollte Vornamen, Nachnamen und ID haben

    void test_2_e() {
        std::cout << " --- Test 2e start --- " << std::endl;

        Worker testWorker = Worker(0, "Donald", "Duck", 20, 40);
        assert(testWorker.salary() == 800);

        Seller testSeller = Seller(0, "Donald", "Duck", 1000, 300);
        assert(testSeller.salary() == 1300);

        Employee employee = Employee(0, "Gustav", "Gans");
        Worker worker = Worker(0, "Dagobert", "Duck", 10, 7);
        employee = worker;
        std::cout << " - Which salary method? - " << std::endl;
        int salary = employee.salary();
        //Ja, entspricht meinen Erwartungen, was soll er sonst machen? :D
        std::cout <<salary << std::endl;

        std::cout << " --- Test 2e end --- " << std::endl;
    }
}

int main() {

    std::cout << "starting..." << std::endl;

    hfu_09::test_1_d();
    hfu_09::test_1_e();
    hfu_09::test_2_e();

    std::cout << "terminating..." << std::endl;

    return 0;
}
