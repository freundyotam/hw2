//
// Created by yotam freund on 13/01/2022.
//

#include "manager_test.h"
#include <sstream>
#include <iostream>
#include "../solution/exceptions.h"
#include <cassert>
#include "employee_test.h"
#include "../solution/manager.h"

void check_manager_clone();

using namespace std;
using namespace mtm;


void test_manager()
{
    check_manager_clone();
    check_manager_salary();
    check_add_employees_to_manager();
    check_manager_printing();
    cout << "[*] manager tests succeeded\n";
}

void check_manager_clone()
{
    Manager m1(2, "a", "b", 10);
    Employee e1(3, "e", "1", 1111);
    Skill s1(1, "name1", 0);
    e1.learnSkill(s1);
    m1.addEmployee(&e1);

    Manager *m2 = m1.clone();
    Employee* e2 = m2->getEmployeeById(3);

    assert(e1.getId() == e2->getId());
    assert(e1.getScore() == e2->getScore());
    assert(e1.getBirthYear() == e2->getBirthYear());
    assert(e1.getFirstName() == e2->getFirstName());
    assert(e1.getLastName() == e2->getLastName());
    assert(e1.getSalary() == e2->getSalary());
    assert(e1.hasSkill(1));
    assert(e2->hasSkill(1));

    // Test deleting skill
    e1.forgetSkill(1);
    assert(!e1.hasSkill(1));
    assert(e2->hasSkill(1));

    // Test deleting employee
    m1.removeEmployee(3);
    assert(m2->getEmployeeById(3));
}

void check_manager_printing()
{
    // Check short print
    Manager m1(2, "a", "b", 10);
    Employee e(3, "e", "1", 1111);
    m1.addEmployee(&e);
    m1.setSalary(3);
    std::ostringstream out;
    m1.printShort(out);
    assert("a b\nSalary: 3\n" == out.str());

    //Check long print
    std::ostringstream out2;
    m1.printLong(out2);
    assert("a b\nid - 2 birth_year - 10\nSalary: 3\nEmployees: \ne 1\nSalary: 0 Score: 0\n" == out2.str());
}

void check_add_employees_to_manager()
{
    Manager m1(2, "a", "b", 10);
    Employee e(3, "e", "1", 1111);

    // Check add employee
    m1.addEmployee(&e);
    assert(m1.getEmployeeById(3) == &e);

    // Check add employee twice
    ASSERT_EXCEPTION(m1.addEmployee(&e), EmployeeAlreadyHired);

    // Check remove employee twice
    m1.removeEmployee(3);
    ASSERT_EXCEPTION(m1.getEmployeeById(3), EmployeeIsNotHired);
    ASSERT_EXCEPTION(m1.removeEmployee(3), EmployeeIsNotHired);
}

void check_manager_salary()
{
    Manager m1(1, "f", "l", 10);
    assert(m1.getSalary() == 0);
    m1.setSalary(23);
    assert(m1.getSalary() == 23);
    m1.setSalary(3);
    assert(m1.getSalary() == 26);
}
