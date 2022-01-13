#include <sstream>
#include "../solution/employee.h"
#include "employee_test.h"
#include <iostream>
#include "../solution/exceptions.h"
#include <cassert>

using namespace std;
using namespace mtm;

void test_employee()
{
    check_employee_members();
    check_employees_skill_functionality();
    check_employee_printing();
    test_employee_clone();
    cout << "[*] Skill tests succeeded\n";
}

void check_employee_members()
{
    long id = 1;
    string first = "first";
    string last = "last";
    int yearOfBirth = 1909;
    Employee e1(id, first, last, yearOfBirth);
    assert(e1.getId() == id);
    assert(first == e1.getFirstName());
    assert(last == e1.getLastName());
    assert(yearOfBirth == e1.getBirthYear());
    assert(e1.getSalary() == 0);
    assert(e1.getScore() == 0);
}


void check_employees_skill_functionality()
{
    Employee e1(1, "first", "last", 1880);
    Skill s(0, "hiking", 0);
    // Check learn skill twice
    e1.learnSkill(s);
    ASSERT_EXCEPTION(e1.learnSkill(s), SkillAlreadyLearned);

    //Check has skill
    assert(e1.hasSkill(0));

    // Check forget skill
    e1.forgetSkill(s.getId());

    // Check forget skill again
    ASSERT_EXCEPTION(e1.forgetSkill(s.getId()), DidNotLearnSkill);

    // Check not enough points
    Skill s2(1, "hiking", 6);
    ASSERT_EXCEPTION(e1.learnSkill(s2), CanNotLearnSkill);

    // Check get score
    e1.setScore(6);
    assert(e1.getScore() == 6);

    // Check learn skill with enough points
    e1.learnSkill(s2);
    assert(e1.getScore() == 6);

    // Check set salary
    e1.setSalary(100);
}

void check_employee_printing(){
    // Check print short
    Employee e1(1, "first", "last", 1880);
    std::ostringstream out;
    e1.setScore(5);
    e1.setSalary(9);
    e1.printShort(out);
    assert("first last\nSalary: 9 Score: 5\n" == out.str());

    // Check print long
    std::ostringstream out2;
    e1.learnSkill(Skill(12,"m", 0));
    e1.printLong(out2);
    assert("first last\nid - 1 birth_year - 1880\nSalary: 9 Score: 5 Skills:\nm\n" == out2.str());
}
void test_employee_clone(){
    Employee e1(1, "first", "last", 1880);
    e1.learnSkill(Skill(1, "hiking", 0));
    e1.learnSkill(Skill(2, "biking", 0));
    Employee* e2 = e1.clone();
    // Check members
    assert(e1.getId() == e2->getId());
    assert(e1.getScore() == e2->getScore());
    assert(e1.getBirthYear() == e2->getBirthYear());
    assert(e1.getFirstName() == e2->getFirstName());
    assert(e1.getLastName() == e2->getLastName());
    assert(e1.getSalary() == e2->getSalary());

    //Check skills copied
    assert(e2->hasSkill(1));
    assert(e2->hasSkill(2));

    // Check Skills not pointing the same thing
    e2->learnSkill(Skill(3, "9GAG", 0));
    assert(!e1.hasSkill(3));
    e1.forgetSkill(1);
    assert(e2->hasSkill(1));
}