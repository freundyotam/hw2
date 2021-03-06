//
// Created by yotam freund on 29/12/2021.
//

#ifndef UNTITLED_EMPLOYEE_H
#define UNTITLED_EMPLOYEE_H

#include <map>
#include "Citizen.h"
#include "Skill.h"
namespace mtm{
    class Employee : public mtm::Citizen{
        long salary;
        int rank;
    public:
        ~Employee() = default;
        long getSalary() const;
        void setSalary(long salary);
        void setScore(int score);
        int getScore() const;
        void learnSkill(Skill skill);
        void forgetSkill(long skill_id);
        bool hasSkill(long skill_id);
        void printShort(std::ostream&) const override;
        void printLong(std::ostream&) const override;
        Employee* clone() override;
        Employee(long id, const std::string &name, const std::string &lastName, int yearOfBirth);
    private:
        std::map<long, const Skill> skills;
    public:

    };
}

#endif //UNTITLED_EMPLOYEE_H
