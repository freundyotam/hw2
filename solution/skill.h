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
        ~Skill() = default;
        long getId() const;
        const std::string &getName() const;
        int getRequiredPoints() const;
        bool operator==(const Skill &rhs) const;
        bool operator!=(const Skill &rhs) const;
        bool operator<(const Skill &rhs) const;
        bool operator>(const Skill &rhs) const;
        bool operator<=(const Skill &rhs) const;
        bool operator>=(const Skill &rhs) const;
        Skill operator++(int);
        Skill& operator+=(int rhs);
        Skill operator+(int point);
        friend std::ostream& operator<<(std::ostream& os, const Skill& skill);
        friend Skill operator+(int i, Skill& skill);
    };

}

#endif //UNTITLED_SKILL_H
