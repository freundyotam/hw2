//
// Created by yotam freund on 11/01/2022.
//

#ifndef UNTITLED_EMPLOYEE_TEST_H
#define UNTITLED_EMPLOYEE_TEST_H

void check_employee_members();
void check_employees_skill_functionality();
void check_employee_printing();
void test_employee_clone();


#define ASSERT_EXCEPTION(f, e)                                                                                    \
try {                                                                                                             \
    f;                                                                                                            \
    cout << __FILE__ ":" << __LINE__ << " Exception: " #e " was not thrown when calling " << endl;                \
    assert(false);                                                                                                \
} catch (const e& exception) {}                                                                                           \

#endif //UNTITLED_EMPLOYEE_TEST_H
