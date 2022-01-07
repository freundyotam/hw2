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
const mtm::Employee &mtm::City::getEmployeeById(long id)
{
    std::set<Employee>::iterator iterator = employees.find(Employee(id, "", "", 0));
    if (iterator == employees.end())
        throw std::string("CitizenDoesNotExist");

    return *iterator;
}

const mtm::Manager &mtm::City::getManagerById(long id)
{
    std::set<Manager>::iterator iterator = managers.find(Manager(id, "", "", 0));
    if (iterator == managers.end())
        throw std::string("CitizenDoesNotExist");

    return *iterator;
}

const mtm::Faculty<mtm::Condition> &mtm::City::getFacultyById(long id)
{
    std::set<Faculty<Condition>>::iterator iterator = faculties.find(Faculty<Condition>(id));
    if (iterator == faculties.end())
        throw std::string("FacultyDoesNotExist");

    return *iterator;
}

const mtm::Workplace &mtm::City::getWorkplaceById(long id)
{
    std::set<Workplace>::iterator iterator = workplaces.find(Workplace(id, "", 0, 0));
    if (iterator == workplaces.end())
        throw std::string("WorkplaceDoesNotExist");

    return *iterator;
}
