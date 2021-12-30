//
// Created by yotam freund on 29/12/2021.
//

#include "employee.h"

Employee::Employee(long salary, int rank, const set <Skill> &skills) : salary(salary), rank(rank), skills(skills)
{}

long Employee::getSalary() const
{
    return salary;
}

int Employee::getScore() const
{
    return score;
}

void Employee::setSalary(long salary)
{
    Employee::salary = salary;
}

void Employee::setScore(int score)
{
    Employee::score = score;
}
