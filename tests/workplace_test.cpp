//
// Created by yotam freund on 13/01/2022.
//

#include "workplace_test.h"

#include "../solution/workplace.h"
#include "cassert"
#include "../solution/exceptions.h"
#include <iostream>
using namespace std;

using namespace mtm;

bool hireEmployeeTrue(Employee* e){ return true;}
bool hireEmployeeFalse(Employee* e){ return false;}

void test_workplace(){
    Workplace w1(1, "ibm", 90, 100);

    // Check members
    assert(w1.getId() == 1);
    assert(w1.getName() == "ibm");
    assert(w1.getManagerSalary() == 100);
    assert(w1.getWorkerSalary() == 90);

    // Check hire manager with employees
    Skill s(2,"skill", 0);
    Employee e1(3, "first", "employee", 112);
    e1.learnSkill(&s);
    Manager m1(4, "first", "manager", 9999);
    m1.addEmployee(&e1);

    w1.hireManager(&m1);
    // Check hire twice
    ASSERT_EXCEPTION(w1.hireManager(&m1), ManagerAlreadyHired);

    // Check manager work somewhere else
    Workplace w2(2, "google", 90, 100);
    ASSERT_EXCEPTION(w2.hireManager(&m1), CanNotHireManager);

    // Check fire manager twice
    w1.fireManager(4);
    ASSERT_EXCEPTION(w1.fireManager(m1.getId()), ManagerIsNotHired);

    // Check hire employee
    w1.hireEmployee(hireEmployeeTrue, &e1, m1.getId());
    assert(w1.isEmployed(e1.getId()));

    // Check hire employee twice
    ASSERT_EXCEPTION(w1.hireEmployee(hireEmployeeTrue, &e1, m1.getId()), EmployeeAlreadyHired);

    // Check employee not selected
    w1.fireEmployee(e1.getId(), m1.getId());
    ASSERT_EXCEPTION(w1.hireEmployee(hireEmployeeFalse, &e1, m1.getId()), EmployeeNotSelected);

    // Check manager is not hired
    ASSERT_EXCEPTION(w1.hireEmployee(hireEmployeeTrue, &e1, 9090), ManagerIsNotHired);
}