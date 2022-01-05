#include <string>

#include "city.h"

mtm::City::City(std::string name) : name(name)
{
}

void mtm::City::addEmployee(long id, std::string name, std::string lastName, int yearOfBirth)
{
    throw std::string("NotImplemented");
}

void mtm::City::addManager(long id, std::string name, std::string lastName, int yearOfBirth)
{
    throw std::string("NotImplemented");
}

template <class Condition>
void mtm::City::addFaculty(long id, Skill skill, int addedPoints, Condition canTeach)
{
    throw std::string("NotImplemented");
}

void mtm::City::createWorkplace(long id, std::string name, long workerSalary, long managerSalary)
{
    throw std::string("NotImplemented");
}

void mtm::City::teachAtFaculty(long workerId, long facultyId)
{
    throw std::string("NotImplemented");
}

template <class Condition>
void mtm::City::hireEmployeeAtWorkplace(Condition isHireable, long employeeId, long managerId, long workplaceId)
{
    throw std::string("NotImplemented");
}

void mtm::City::hireManagerAtWorkplace(long managerId, long workplaceId)
{
    throw std::string("NotImplemented");
}

void mtm::City::fireEmployeeAtWorkplace(long employeeId, long workplaceId)
{
    throw std::string("NotImplemented");
}

void mtm::City::fireManagerAtWorkplace(long managerId, long workplaceId)
{
    throw std::string("NotImplemented");
}

void mtm::City::getAllAboveSalary(std::ostream &os, long salary)
{
    throw std::string("NotImplemented");
}

bool mtm::City::isWorkingInTheSameWorkplace(long employeeOneId, long employeeTwoId)
{
    throw std::string("NotImplemented");
}

void mtm::City::printAllEmployeesWithSkill(std::ostream &os, Skill skill)
{
    throw std::string("NotImplemented");
}
