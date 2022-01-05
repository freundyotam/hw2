//
// Created by yotam freund on 29/12/2021.
//

#include "employee.h"
#include <set>

namespace mtm{
    Employee::Employee(long id, const std::string &name, const std::string &lastName, int yearOfBirth, long salary,
                       int rank, const std::set<Skill> &skills) : Citizen(id, name, lastName, yearOfBirth),
                       salary(salary), rank(rank), skills(skills)
    {

    }

    long Employee::getSalary() const
    {
        return salary;
    }

    int Employee::getScore() const
    {
        return rank;
    }

    void Employee::setSalary(long salary)
    {
        Employee::salary = salary;
    }

    void Employee::setScore(int score)
    {
        Employee::rank += score;
    }
    void Employee::printShort(std::ostream) const
    {

    }
    void Employee::printLong(std::ostream) const
    {

    }

}
