//
// Created by yotam freund on 29/12/2021.
//

#include "manager.h"

namespace mtm{
    Manager::Manager(long id, const std::string &name, const std::string &lastName, int yearOfBirth, long salary) :
    Citizen(
            id, name, lastName, yearOfBirth), salary(salary)
    {}

    long Manager::getSalary() const
    {
        return salary;
    }

    void Manager::setSalary(long salary)
    {
        Manager::salary = salary;
    }
    void Manager::printShort(std::ostream) const
    {

    }
    void Manager::printLong(std::ostream) const
    {

    }
}
