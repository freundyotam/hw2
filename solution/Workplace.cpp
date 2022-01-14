#include "Workplace.h"
#include "exceptions.h"

#include <ostream>
#include <string>
#include <map>

mtm::Workplace::Workplace(long id, const std::string &workplaceName, long workerSalary, long managerSalary) : id(id),
                                                                                                              name(workplaceName),
                                                                                                              worker_salary(workerSalary),
                                                                                                              manager_salary(managerSalary)
{
}

std::string mtm::Workplace::getName() const
{
    return name;
}
long mtm::Workplace::getId() const
{
    return id;
}

long mtm::Workplace::getWorkerSalary() const
{
    return worker_salary;
}

long mtm::Workplace::getManagerSalary() const
{
    return manager_salary;
}

bool mtm::Workplace::isEmployed(long id)
{
    for (auto manager_pair : managers)
    {
        if (manager_pair.second->getEmployeeSet().count(id) > 0)
            return true;
    }

    return false;
}

void mtm::Workplace::fireEmployee(long employeeId, long managerId)
{
    std::map<long, Manager *>::iterator manager_it = managers.find(managerId);
    if (manager_it == managers.end())
        throw ManagerIsNotHired();

    if ((*manager_it).second->getEmployeeSet().count(employeeId) == 0)
        throw EmployeeIsNotHired();
    Employee *emp = (*manager_it).second->getEmployeeById(employeeId);
    emp->setSalary(-this->worker_salary);
    (*manager_it).second->removeEmployee(employeeId);
}

void mtm::Workplace::hireManager(Manager *manager)
{
    if (managers.count(manager->getId()) > 0)
        throw ManagerAlreadyHired();

    if (manager->getSalary() > 0)
        throw CanNotHireManager();

    managers.insert({manager->getId(), manager});

    manager->setSalary(this->manager_salary);

    for (auto employee_pair : manager->getEmployeeSet())
    {
        employee_pair.second->setSalary(this->worker_salary);
    }
}

void mtm::Workplace::fireManager(long managerId)
{
    std::map<long, Manager *>::iterator iterator = managers.find(managerId);
    if (iterator == managers.end())
        throw ManagerIsNotHired();

    (*iterator).second->setSalary(-this->manager_salary);

    for (auto employee_pair : (*iterator).second->getEmployeeSet())
    {
        employee_pair.second->setSalary(-this->worker_salary);
    }

    managers.erase(iterator);
}

std::ostream &mtm::operator<<(std::ostream &os, const Workplace &workplace)
{
    os << "Workplace name - " << workplace.getName();

    if (!workplace.managers.empty())
        os << " Groups:";

    os << std::endl;

    for (const std::pair<long, Manager *> &manager_pair : workplace.managers)
    {
        os << "Manager ";
        manager_pair.second->printLong(os);
    }

    return os;
}