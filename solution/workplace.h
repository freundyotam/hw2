#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <string>
#include <map>

#include "employee.h"
#include "manager.h"

namespace mtm
{
    class Workplace
    {
    private:
        long id;
        std::string name;
        long worker_salary;
        long manager_salary;

        std::map<long, Manager *> managers;

    public:
        Workplace(long id, const std::string &workplaceName, long workerSalary, long managerSalary);

        long getId() const;
        std::string getName() const;
        long getWorkerSalary() const;
        long getManagerSalary() const;

        template <class Condition>
        void hireEmployee(Condition isHirable, Employee *employee, int managerId);
        void fireEmployee(long employeeId, long managerId);

        void hireManager(Manager *manager);
        void fireManager(long managerId);

        friend std::ostream &operator<<(std::ostream &os, const Workplace &workplace);
    };

    template <class Condition>
    void mtm::Workplace::hireEmployee(Condition isHirable, Employee *employee, int managerId)
    {
        if (!isHirable(employee))
            throw std::string("EmployeeNotSelected"); // TODO: EmployeeNotSelected exception

        std::map<long, Manager *>::iterator iterator = managers.find(managerId);
        if (iterator == managers.end())
            throw std::string("ManagerIsNotHired"); // TODO: ManagerIsNotHired exception

        (*iterator).second->addEmployee(employee);
        employee->setSalary(this->worker_salary);
    }

    std::ostream &operator<<(std::ostream &os, const Workplace &workplace);
}

#endif // WORKPLACE_H