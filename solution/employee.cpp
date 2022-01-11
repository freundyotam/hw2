//
// Created by yotam freund on 29/12/2021.
//

#include "employee.h"
#include "exceptions.h"
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
    void Employee::printShort(ostream& stream) const
    {
        stream << getFirstName() << " " << getLastName() << endl << "Salary: " << getSalary() << " Score : "
                                                                                                << getScore() << endl;
    }
    void Employee::printLong(ostream& stream) const
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
        if(this->hasSkill(skill.getId())){
            throw SkillAlreadyLearned();
        }
        else
        {
            skills.insert(skill);
        }
    }

    bool Employee::hasSkill(long skill_id)
    {
        set<Skill>::iterator it = skills.begin();
        while (it != skills.end())
        {
            if((*it).getId() == skill_id)
                return true;
            it++;
        }
        return false;
    }

    void Employee::forgetSkill(long skill_id)
    {
        if(!hasSkill(skill_id)){
            throw DidNotLearnSkill();
        }
        else
        {
            skills.erase(Skill(skill_id,"",0));
        }
    } // todo Is this the right way to erase?

    Employee *Employee::clone()
    {
        Employee* copy = new Employee(getId(), getFirstName(), getLastName(),getBirthYear());
        copy->skills = skills;
        return copy; // Is this the right way to implement this? what about copy ctor for skill (that isn't implemented)?
    }
}
