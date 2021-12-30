#ifndef UNTITLED_SKILL_H
#define UNTITLED_SKILL_H

#include <string>

class skill{
    long id;
    std::string name;
    int required_skill_points;
public:
    long getId() const;
    const std::string &getName() const;
    int getRequiredSkillPoints() const;

};
#endif //UNTITLED_SKILL_H
