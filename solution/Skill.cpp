#include "Skill.h"
#include "exceptions.h"

#include <iostream>


namespace mtm{
    Skill::Skill(long id, const std::string &name, int requiredSkillPoints) : id(id), name(name),
                                                                              required_skill_points(requiredSkillPoints)
    {

    }
    long Skill::getId() const
    {
        return id;
    }

    const std::string &mtm::Skill::getName() const
    {
        return name;
    }

    int Skill::getRequiredPoints() const
    {
        return required_skill_points;
    }

    bool Skill::operator==(const Skill &rhs) const
    {
        return id == rhs.id;
    }

    bool Skill::operator!=(const Skill &rhs) const
    {
        return !(rhs == *this);
    }

    bool Skill::operator<(const Skill &rhs) const
    {
        return id < rhs.getId();
    }

    bool Skill::operator>(const Skill &rhs) const
    {
        return rhs < *this;
    }

    bool Skill::operator<=(const Skill &rhs) const
    {
        return !(rhs < *this);
    }

    bool Skill::operator>=(const Skill &rhs) const
    {
        return !(*this < rhs);
    }

    Skill &Skill::operator+=(const int rhs)
    {
        if(rhs < 0){
            throw NegativePoints();
        }
        this->required_skill_points += rhs;
        return *this;
    }

    Skill Skill::operator++(int)
    {
        Skill copy1 = *this; // default copy c'tor
        this->required_skill_points++;
        return copy1;
    }

    Skill Skill::operator+(int points)
    {
        if(points < 0){
            throw NegativePoints();
        }
        this->required_skill_points += points;
        return *this;
    }

    std::ostream& operator<<(std::ostream &os, const Skill &skill)
    {
        return os << skill.getName() << std::endl;
    }

     Skill operator+(int i, Skill& skill)
    {
        if (i < 0){
            throw NegativePoints();
        }
        skill.required_skill_points += i;
        return skill;
    }
}