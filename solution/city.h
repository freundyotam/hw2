#ifndef CITY_H
#define CITY_H

#include <string>
#include <set>

#include "citizen.h"
#include "faculty.h"
#include "workplace.h"
#include "exceptions.h"
#include "skill.h"

namespace mtm
{
    class City
    {
    private:
        std::string name;
        std::map<long, Employee> employees;
        std::map<long, Manager> managers;
        std::map<long, Faculty<Condition>> faculties;
        std::map<long, Workplace> workplaces;

        Employee &getEmployeeById(long id);
        Manager &getManagerById(long id);
        Faculty<Condition> &getFacultyById(long id);
        Workplace &getWorkplaceById(long id);

    public:
        City(std::string name);
        void addEmployee(long id, std::string name, std::string lastName, int yearOfBirth);
        void addManager(long id, std::string name, std::string lastName, int yearOfBirth);
        void addFaculty(long id, Skill skill, int addedPoints, Condition *canTeach);
        void createWorkplace(long id, std::string name, long employeeSalary, long managerSalary);
        void teachAtFaculty(long employeeId, long facultyId);
        template <class TCondition>
        void hireEmployeeAtWorkplace(TCondition isHireable, long employeeId, long managerId, long workplaceId);
        void hireManagerAtWorkplace(long managerId, long workplaceId);
        void fireEmployeeAtWorkplace(long employeeId, long managerId, long workplaceId);
        void fireManagerAtWorkplace(long managerId, long workplaceId);
        void getAllAboveSalary(std::ostream &os, long salary);
        bool isWorkingInTheSameWorkplace(long employeeOneId, long employeeTwoId);
        void printAllEmployeesWithSkill(std::ostream &os, long skillId);
    };

    template <class TCondition>
    void City::hireEmployeeAtWorkplace(TCondition isHireable, long employeeId, long managerId, long workplaceId)
    {
        Employee &employee = getEmployeeById(employeeId);
        getManagerById(managerId);
        Workplace &workplace = getWorkplaceById(workplaceId);

        workplace.hireEmployee(isHireable, &employee, managerId);
    }

} // namespace mtm

#endif // CITY_H