#ifndef CITY_H
#define CITY_H

#include <string>
#include <set>

#include "citizen.h"
#include "faculty.h"
#include "workplace.h"
#include "skill.h"

namespace mtm
{
    class City
    {
    private:
        std::string name;
        std::set<Employee> employees;
        std::set<Manager> managers;
        std::set<Faculty<Condition>> faculties;
        std::set<Workplace> workplaces;

        const Employee &getEmployeeById(long id);
        const Manager &getManagerById(long id);
        const Faculty<Condition> &getFacultyById(long id);
        const Workplace &getWorkplaceById(long id);

    public:
        City(std::string name);
        void addEmployee(long id, std::string name, std::string lastName, int yearOfBirth);
        void addManager(long id, std::string name, std::string lastName, int yearOfBirth);
        template <class Condition>
        void addFaculty(long id, Skill skill, int addedPoints, Condition canTeach);
        void createWorkplace(long id, std::string name, long workerSalary, long managerSalary);
        void teachAtFaculty(long workerId, long facultyId);
        template <class Condition>
        void hireEmployeeAtWorkplace(Condition isHireable, long employeeId, long managerId, long workplaceId);
        void hireManagerAtWorkplace(long managerId, long workplaceId);
        void fireEmployeeAtWorkplace(long employeeId, long workplaceId);
        void fireManagerAtWorkplace(long managerId, long workplaceId);
        void getAllAboveSalary(std::ostream &os, long salary);
        bool isWorkingInTheSameWorkplace(long employeeOneId, long employeeTwoId);
        void printAllEmployeesWithSkill(std::ostream &os, Skill skill);
    };

} // namespace mtm

#endif // CITY_H