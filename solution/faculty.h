#ifndef FACULTY_H
#define FACULTY_H

#include "skill.h"
#include "employee.h"

namespace mtm
{
    template <class Condition>
    class Faculty
    {
    private:
        long id;
        int added_points;
        Skill skill;
        Condition canTeach;

    public:
        Faculty(long id, Skill skill, int addedPoints, Condition canTeach);

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
    };

    template <class Condition>
    Faculty<Condition>::Faculty(long id, Skill skill, int addedPoints, Condition canTeach) : id(id),
                                                                                             added_points(addedPoints),
                                                                                             skill(skill),
                                                                                             canTeach(canTeach)
    {
    }

    template <class Condition>
    void Faculty<Condition>::teach(Employee employee) const
    {
        if (!canTeach(employee))
            throw string("EmployeeNotAccepted"); // TODO: EmployeeNotAccepted Exception

        if (employee.hasSkill(skill))
            return;

        employee.learnSkill(skill);
        employee.setScore(employee.getScore() + this->added_points);
    }
}
#endif // FACULTY_H