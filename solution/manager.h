//
// Created by yotam freund on 29/12/2021.
//

#ifndef UNTITLED_MANAGER_H
#define UNTITLED_MANAGER_H

#include "citizen.h"
#include "employee.h"
#include <set>
namespace mtm{
    class Manager : public mtm::Citizen{
    public:
        Manager(long id, const std::string &name, const std::string &lastName, int yearOfBirth, long salary);
        long getSalary() const;
        void addEmployee(Employee* employee);
        void removeEmployee(long citizen_id);
        void setSalary(long salary);
        void printShort(std::ostream) const;
        void printLong(std::ostream) const;
        Manager* clone();
    private:
        long salary;
        std::set<Employee> employees;
    };
}


#endif //UNTITLED_MANAGER_H
