#include "city.h"

mtm::City::City(std::string name) : name(name)
{
}

void mtm::City::addEmployee(long id, std::string name, std::string lastName, int yearOfBirth)
{
    Employee employee(id, name, lastName, yearOfBirth);
    if (!employees.insert({id, employee}).second)
        throw CitizenAlreadyExists();
}

void mtm::City::addManager(long id, std::string name, std::string lastName, int yearOfBirth)
{
    Manager manager(id, name, lastName, yearOfBirth);
    if (!managers.insert({id, manager}).second)
        throw CitizenAlreadyExists();
}

void mtm::City::addFaculty(long id, Skill skill, int addedPoints, Condition *canTeach)
{
    Faculty<Condition> faculty(id, skill, addedPoints, canTeach);
    if (!faculties.insert({id, faculty}).second)
        throw CitizenAlreadyExists();
}

void mtm::City::createWorkplace(long id, std::string name, long employeeSalary, long managerSalary)
{
    Workplace workplace(id, name, employeeSalary, managerSalary);
    if (!workplaces.insert({id, workplace}).second)
        throw CitizenAlreadyExists();
}

void mtm::City::teachAtFaculty(long employeeId, long facultyId)
{

    Employee &employee = getEmployeeById(employeeId);
    Faculty<Condition> &faculty = getFacultyById(facultyId);

    faculty.teach(&employee);
}

void mtm::City::hireManagerAtWorkplace(long managerId, long workplaceId)
{
    Manager &manager = getManagerById(managerId);
    Workplace &workplace = getWorkplaceById(workplaceId);

    workplace.hireManager(&manager);
}

void mtm::City::fireEmployeeAtWorkplace(long employeeId, long managerId, long workplaceId)
{
    getEmployeeById(employeeId);
    getManagerById(managerId);
    Workplace &workplace = getWorkplaceById(workplaceId);

    workplace.fireEmployee(employeeId, managerId);
}

void mtm::City::fireManagerAtWorkplace(long managerId, long workplaceId)
{
    Manager &manager = getManagerById(managerId);
    Workplace &workplace = getWorkplaceById(workplaceId);

    for (auto employee_pair : manager.getEmployeeSet())
    {
        workplace.fireEmployee(employee_pair.second->getId(), managerId);
    }

    workplace.fireManager(managerId);
}

int mtm::City::getAllAboveSalary(std::ostream &os, long salary)
{

    std::map<long, Citizen *> citizen_map;
    for (auto manager_pair : managers)
    {
        if (manager_pair.second.getSalary() > salary)
            citizen_map.insert({manager_pair.first, &manager_pair.second});
    }

    for (auto employee_pair : employees)
    {
        if (employee_pair.second.getSalary() > salary)
            citizen_map.insert({employee_pair.first, &employee_pair.second});
    }

    for (auto citizen_pair : citizen_map)
    {
        citizen_pair.second->printShort(os);
    }

    return citizen_map.size();
}

bool mtm::City::isWorkingInTheSameWorkplace(long employeeOneId, long employeeTwoId)
{
    for (std::pair<long, Workplace> id_workplace_pair : workplaces)
    {
        Workplace &workplace = id_workplace_pair.second;

        if (workplace.isEmployed(employeeOneId) && workplace.isEmployed(employeeTwoId))
            return true;
    }

    return false;
}

void mtm::City::printAllEmployeesWithSkill(std::ostream &os, long skillId)
{
    for (std::pair<long, Employee> id_employee_pair : employees)
    {
        if (id_employee_pair.second.hasSkill(skillId))
            id_employee_pair.second.printShort(os);
    }
}

mtm::Employee &mtm::City::getEmployeeById(long id)
{
    std::map<long, Employee>::iterator iterator = employees.find(id);
    if (iterator == employees.end())
        throw CitizenDoesNotExist();

    return (*iterator)
        .second;
}

mtm::Manager &mtm::City::getManagerById(long id)
{
    std::map<long, Manager>::iterator iterator = managers.find(id);
    if (iterator == managers.end())
        throw CitizenDoesNotExist();

    return (*iterator).second;
}

mtm::Faculty<mtm::Condition> &mtm::City::getFacultyById(long id)
{
    std::map<long, Faculty<Condition>>::iterator iterator = faculties.find(id);
    if (iterator == faculties.end())
        throw FacultyDoesNotExist();

    return (*iterator).second;
}

mtm::Workplace &mtm::City::getWorkplaceById(long id)
{
    std::map<long, Workplace>::iterator iterator = workplaces.find(id);
    if (iterator == workplaces.end())
        throw WorkplaceDoesNotExist();

    return (*iterator)
        .second;
}
