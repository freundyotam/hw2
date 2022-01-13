//
// Created by yotam freund on 29/12/2021.
//


#ifndef UNTITLED_MANAGER_H
#define UNTITLED_MANAGER_H

#include "citizen.h"
#include "employee.h"
#include <map>
namespace mtm{
    class Manager : public Citizen{
    public:
        Manager(long id, const std::string &name, const std::string &lastName, int yearOfBirth);
        ~Manager() = default;
        long getSalary() const;
        std::map<long, Employee *> getEmployeeSet() const;
        void addEmployee(Employee* employee);
        void removeEmployee(long citizen_id);
        void setSalary(long salary);
        void printShort(std::ostream&) const;
        void printLong(std::ostream&) const;
        Employee *getEmployeeById(long id);
        Manager* clone() override;
    private:
        bool isEmployeeExists(Employee* employee);
        bool isEmployeeExists(long id);
        long salary;
        std::map<long, Employee *> employees;
    };
}


#endif //UNTITLED_MANAGER_H
