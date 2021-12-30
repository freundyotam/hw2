//
// Created by yotam freund on 29/12/2021.
//

#ifndef UNTITLED_EMPLOYEE_H
#define UNTITLED_EMPLOYEE_H

#include <set>
#include "citizen.h"
#include "skill.h"
namespace mtm{
    class Employee : private mtm::Citizen{
        long salary;
        int score;
    public:
        long getSalary() const;
        void setSalary(long salary);
        void setScore(int score);
        int getScore() const;
        void learnSkill(Skill skill);
        void forgetSkill(Skill skill);
        void hasSkill(Skill skill);
        void printShort(std::ostream) const;
        void printLong(std::ostream) const;
        Employee* clone();

    private:
        std::set<Skill> skills;
    public:

    };
}

#endif //UNTITLED_EMPLOYEE_H
