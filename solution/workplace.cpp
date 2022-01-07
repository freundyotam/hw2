#include "workplace.h"
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

// template <class Condition>
// void mtm::Workplace::hireEmployee(Condition isHirable, Employee *employee, int managerId)
// {
//     if (!isHirable(employee))
//         throw std::string("EmployeeNotSelected"); // TODO: EmployeeNotSelected exception
// }

void mtm::Workplace::fireEmployee(long employeeId, long managerId)
{
    std::map<long, Manager *>::iterator iterator = managers.find(managerId);
    if (iterator == managers.end())
        throw std::string("ManagerIsNotHired"); // TODO: ManagerIsNotHired exception

    (*iterator).second->removeEmployee(employeeId);
}

void mtm::Workplace::hireManager(Manager *manager)
{
    if (!managers.insert({manager->getId(), manager}).second)
        throw std::string("ManagerAlreadyHired"); // TODO: ManagerAlreadyHired exception

    manager->setSalary(this->manager_salary);
}

void mtm::Workplace::fireManager(long managerId)
{
    std::map<long, Manager *>::iterator iterator = managers.find(managerId);
    if (iterator == managers.end())
        throw std::string("ManagerIsNotHired"); // TODO: ManagerIsNotHired exception

    (*iterator).second->setSalary(-this->manager_salary);

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
        manager_pair.second->printLong(os);
    }

    return os;
}