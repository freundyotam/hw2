#ifndef CITY_H
#define CITY_H

#include <string>
#include <map>

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
        std::map<long, Citizen> citizens;
        std::map<long, Faculty> faculties;
        std::map<long, Workplace> workplaces;

    public:
        City(std::string name);
        void addFaculty();
        void createWorkplace();
        void teachAtFaculty(long workerId, long facultyId);
        template <class Condition>
        void hireEmployeeAtWorkplace(Condition isHireable, long employeeId, long managerId, long workplaceId);
        void hireManagerAtWorkplace(long managerId, long workplaceId);
        void fireEmployeeAtWorkplace(long employeeId, long workplaceId);
        void fireManagerAtWorkplace(long managerId, long workplaceId);
        void getAllAboveSalary(std::ostream &os, long salary);
        bool isWorkingInTheSameWorkplace(long employeeOneId, long employeeTwoId);
        void prointAllEmployeesWithSkill(std::ostream &os, Skill skill);
    };

} // namespace mtm

#endif // CITY_H