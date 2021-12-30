#include "skill.h"

#include <iostream>

long skill::getId() const
{
    return id;
}

const std::string &skill::getName() const
{
    return name;
}

int skill::getRequiredSkillPoints() const
{
    return required_skill_points;
}
