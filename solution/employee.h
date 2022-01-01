//
// Created by yotam freund on 29/12/2021.
//

#ifndef UNTITLED_EMPLOYEE_H
#define UNTITLED_EMPLOYEE_H

#include <set>
#include "citizen.h"
#include "skill.h"
namespace mtm{
    class Employee : public mtm::Citizen{
        long salary;
        int rank;
    public:
        long getSalary() const;
        void setSalary(long salary);
        void setScore(int score);
        int getScore() const;
        void learnSkill(Skill skill);
        void forgetSkill(Skill skill);
        void hasSkill(Skill skill);
        void printShort(std::ostream) const override;
        void printLong(std::ostream) const override;
        Employee* clone();
        Employee(long id, const std::string &name, const std::string &lastName, int yearOfBirth, long salary, int rank, const std::set<Skill> &skills);
    private:
        std::set<Skill> skills;
    public:

    };
}

#endif //UNTITLED_EMPLOYEE_H
