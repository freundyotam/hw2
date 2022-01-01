//
// Created by yotam freund on 29/12/2021.
//

#include "employee.h"
#include <set>


mtm::Employee::Employee(long salary, int rank, const std::set<Skill> &skills) : salary(salary), rank(rank), skills(skills)
{}

long mtm::Employee::getSalary() const
{
    return salary;
}

int mtm::Employee::getScore() const
{
    return score;
}

void mtm::Employee::setSalary(long salary)
{
    Employee::salary = salary;
}

void mtm::Employee::setScore(int score)
{
    Employee::score = score;
}

