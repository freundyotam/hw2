#include "skill_test.h"
#include "manager_test.h"
#include "employee_test.h"
#include "city_test.h"
#include "employee_print_test.h"
#include "manager_print_test.h"
#include "workplace_print_test.h"

int main(int argc, char** argv)
{
    main_city_test();
    main_employee_print_test();
    check_skill_members();
    check_skill_logic_operators();
    check_skill_printing();
    check_employee_members();
    check_employees_skill_functionality();
    check_employee_printing();
    test_employee_clone();
    manager_print_test();
    workplace_test();
    test_manager();
}

