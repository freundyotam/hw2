//
// Created by yotam freund on 29/12/2021.
//

#include "employee.h"
#include "exceptions.h"
#include <map>

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
        if(this->salary + add_salary < 0){
            this->salary = 0;
            return;
        }
        this->salary += add_salary;
    }

    void Employee::setScore(int score)
    {
        if(this->getScore() + score < 0){
            this->rank = 0;
            return;
        }
        Employee::rank += score;
    }
    void Employee::printShort(ostream& stream) const
    {
        stream << getFirstName() << " " << getLastName() << endl << "Salary: " << getSalary() << " Score: "
                                                                                                << getScore() << endl;
    }
    void Employee::printLong(ostream& stream) const
    {
        stream << getFirstName() << " " << getLastName() << endl << "id - " << getId() << " birth_year - " << getBirthYear()
        << endl << "Salary: " << getSalary() << " Score: " << getScore() << " Skills:" << endl;

        for (const std::pair<long, const Skill> pair : this->skills)
        {
            stream << pair.second.getName() << endl;
        }
    }

    void Employee::learnSkill(const Skill skill)
    {

        if(this->hasSkill(skill.getId())){
            throw SkillAlreadyLearned();
        }
        else if (this->getScore() < skill.getRequiredPoints())
        {
            throw CanNotLearnSkill();
        }
        skills.insert({skill.getId(), skill});
    }

    bool Employee::hasSkill(long skill_id)
    {
        return skills.count(skill_id) > 0;
    }

    void Employee::forgetSkill(long skill_id)
    {
        if(!hasSkill(skill_id)){
            throw DidNotLearnSkill();
        }
        else
        {
            skills.erase(skill_id);
        }
    }

    Employee *Employee::clone()
    {
        Employee* copy = new Employee(getId(), getFirstName(), getLastName(),getBirthYear());
        copy->setScore(this->getScore());
        copy->salary = this->salary;
        map<long, const Skill> copy_skills;
        for (const std::pair<long, Skill> pair : this->skills)
        {
            copy_skills.insert({pair.first, pair.second});
        }

        copy->skills = copy_skills;
        return copy;
    }
}
