//
// Created by yotam freund on 29/12/2021.
//

#include "manager.h"
mtm::Manager::Manager(long id, const std::string &name, const std::string &lastName, int yearOfBirth, long salary) : Citizen(
        id, name, lastName, yearOfBirth), salary(salary)
{}

long mtm::Manager::getSalary() const
{
    return salary;
}

void mtm::Manager::setSalary(long salary)
{
    Manager::salary = salary;
}
