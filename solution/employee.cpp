//
// Created by yotam freund on 29/12/2021.
//

#include "employee.h"
#include <set>
using namespace std;

namespace mtm{
    Employee::Employee(long id, const string &name, const string &lastName, int yearOfBirth) : Citizen(id, name, lastName, yearOfBirth),
                       salary(0), rank(0)
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

    void Employee::setSalary(long add_salary)
    {
        Employee::salary += add_salary;
    }

    void Employee::setScore(int score)
    {
        Employee::rank += score;
    }
    void Employee::printShort(ostream stream) const
    {
        stream << getFirstName() << " " << getLastName() << endl << "Salary: " << getSalary() << " Score : "
                                                                                                << getScore() << endl;
    }
    void Employee::printLong(ostream stream) const
    {
        stream << getFirstName() << " " << getLastName() << endl << "id - " << getId() << " birth_year - " << getBirthYear()
        << endl << "Salary: " << getSalary() << " Score: " << getScore() << " Skills:" << endl;
        set<Skill>::iterator it = skills.begin();
        while (it != skills.end())
        {
            stream << (*it).getName() << endl;
            it++;
        }
    }

    void Employee::learnSkill(const Skill& skill)
    {
        if(this->hasSkill(skill)){
            // raise already here
        } else {
            skills.insert(skill);
        }
    }

    bool Employee::hasSkill(const Skill& skill)
    {
        return skills.find(skill) != skills.end();
    }

    void Employee::forgetSkill(const Skill& skill)
    {
        if(!hasSkill(skill)){
            // raise DidNotLearnSkill
        } else {
            skills.erase(skill);
        }
    }

    Employee *Employee::clone()
    {
        Employee* copy = new Employee(getId(), getFirstName(), getLastName(),getBirthYear());
        copy->skills = skills;
        return copy; // Is this the right way to implement this? what about copy ctor for skill (that isn't implemented)?
    }
}
