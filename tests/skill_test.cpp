//
// Created by yotam freund on 11/01/2022.
//
#include <sstream>
#include "../solution/skill.h"
#include "skill_test.h"
#include <cassert>
#include <iostream>
using namespace std;

void check_members();
void check_logic_operators();
void check_printing();

using namespace mtm;

void test_skill(){
    check_members();
    check_logic_operators();
    check_printing();
    cout << "[*] Skill tests succeeded\n";
}

void check_printing()
{
    Skill s1(12, "a", 1);
    std::ostringstream out;
    out << s1;
    assert("a\n" == out.str());
}

void check_logic_operators()
{
    long id1 = 1;
    std::string name1 = "Playing chess";
    int points1 = 102;
    long id2 = 1;
    std::string name2 = "Playing soccer";
    int points2 = 103;
    Skill s1(id1, name1, points1);
    Skill s2(id2, name2, points2);
    assert(s1 == s2);
    assert(s1 == s1);
    assert(s2 == s2);
    assert(s1 <= s2);
    assert(s1 >= s2);
    assert((s1++).getRequiredSkillPoints() == 102);
    assert(s1.getRequiredSkillPoints() == 103);
    assert(!(s1 > s2));
    assert(!(s2 < s1));
    s1+=3;
    assert(s1.getRequiredSkillPoints() == 106);
    s1 = s2 + 3;
    assert(s1.getRequiredSkillPoints() == 106);

}

void check_members()
{
    long id1 = 1;
    std::string name1 = "Playing chess";
    int points1 = 102;
    Skill s1(id1, name1, points1);
    assert(s1.getId() == id1);
    assert(s1.getName() == name1);
    assert(s1.getRequiredSkillPoints() == points1);
}

int main(int argc, char** argv){
    test_skill();

    return 0;
}