#ifndef FACULTY_H
#define FACULTY_H

#include "skill.h"
#include "employee.h"
#include <string>

namespace mtm
{
    class Condition
    {
    public:
        virtual bool operator()(Employee *employee) = 0;
    };

    template <class TCondition>
    class Faculty
    {
    private:
        long id;
        int added_points;
        Skill skill;
        TCondition *canTeach;

    public:
        Faculty(long id);
        Faculty(long id, Skill skill, int addedPoints, TCondition *canTeach);

        Skill getSkill() const
        {
            return skill;
        }

        int getId() const
        {
            return id;
        }

        int getAddedPoints() const
        {
            return added_points;
        }

        void teach(Employee employee) const;

        template <class RHSCondition>
        bool operator<(const Faculty<RHSCondition> &faculty) const
        {
            return this->id < faculty.getId();
        }
    };

    template <class TCondition>
    Faculty<TCondition>::Faculty(long id, Skill skill, int addedPoints, TCondition *canTeach) : id(id),
                                                                                                added_points(addedPoints),
                                                                                                skill(skill),
                                                                                                canTeach(canTeach)
    {
    }

    template <class TCondition>
    Faculty<TCondition>::Faculty(long id) : id(id)
    {
    }

    template <class TCondition>
    void Faculty<TCondition>::teach(Employee employee) const
    {
        if (!canTeach(employee))
            throw std::string("EmployeeNotAccepted"); // TODO: EmployeeNotAccepted Exception

        if (employee.hasSkill(skill.getId()))
            return;

        employee.learnSkill(skill);
        employee.setScore(employee.getScore() + this->added_points);
    }
}
#endif // FACULTY_H