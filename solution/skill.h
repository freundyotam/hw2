#ifndef UNTITLED_SKILL_H
#define UNTITLED_SKILL_H

#include <string>
#include <iostream>
namespace mtm{
    class Skill{
        long id;
        std::string name;
        int required_skill_points;
    public:
        Skill(long id, const std::string &name, int requiredSkillPoints);

        long getId() const;
        const std::string &getName() const;
        int getRequiredSkillPoints() const;
        bool operator==(const Skill &rhs) const;
        bool operator!=(const Skill &rhs) const;
        bool operator<(const Skill &rhs) const;
        bool operator>(const Skill &rhs) const;
        bool operator<=(const Skill &rhs) const;
        bool operator>=(const Skill &rhs) const;
        Skill operator++(int);
        Skill& operator+=(const Skill& rhs);
        Skill operator+(int point);
//        friend std::ostream& operator<<(std::ostream& os, const Skill& skill);
    };
}

#endif //UNTITLED_SKILL_H
