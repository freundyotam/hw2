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
        long worker_salary;
        long manager_salary;
        std::string name;

        std::map<long, Manager *> managers;

    public:
        Workplace(long id, std::string workplaceName, long workerSalary, long managerSalary);

        long getId();
        std::string getName();
        long getWorkerSalary();
        long getManagerSalary();

        template <class Condition>
        void hireEmployee(Condition isHirable, Employee *employee, int managerId);
        void fireEmployee(long employeeId, long managerId);

        void hireManager(Manager *manager);
        void fireManager(long managerId);

        friend std::ostream &operator<<(std::ostream &os, const Workplace &workplace);
    };
}

#endif // WORKPLACE_H