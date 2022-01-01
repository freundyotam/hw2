#include "skill.h"

#include <iostream>


namespace mtm{
    long Skill::getId() const
    {
        return id;
    }

    const std::string &mtm::Skill::getName() const
    {
        return name;
    }

    int Skill::getRequiredSkillPoints() const
    {
        return required_skill_points;
    }

    bool Skill::operator==(const Skill &rhs) const
    {
        return id == rhs.id &&
               name == rhs.name &&
               required_skill_points == rhs.required_skill_points;
    }

    bool Skill::operator!=(const Skill &rhs) const
    {
        return !(rhs == *this);
    }

    bool Skill::operator<(const Skill &rhs) const
    {
        if (id < rhs.id)
            return true;
        if (rhs.id < id)
            return false;
        if (name < rhs.name)
            return true;
        if (rhs.name < name)
            return false;
        return required_skill_points < rhs.required_skill_points;
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

    Skill::Skill(long id, const std::string &name, int requiredSkillPoints) : id(id), name(name),
                                                                                   required_skill_points(requiredSkillPoints)
    {}

}
int main(int argc, char** s){
    return 0;
}