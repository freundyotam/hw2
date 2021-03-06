//
// Created by yotam freund on 29/12/2021.
//

#include <map>
#include "exceptions.h"
#include "Manager.h"
using namespace std;

namespace mtm{
    Manager::Manager(long id, const std::string &name, const std::string &lastName, int yearOfBirth) :
            Citizen(
                    id, name, lastName, yearOfBirth), salary(0)
    {}

    long Manager::getSalary() const
    {
        return salary;
    }

    void Manager::setSalary(long salary)
    {
        if(this->salary + salary < 0){
            this->salary = 0;
            return;
        }
        this->salary += salary;
    }
    void Manager::printShort(std::ostream& ostream) const
    {
        ostream << getFirstName() << " " << getLastName() << endl << "Salary: " << getSalary() << endl;
    }
    void Manager::printLong(std::ostream& ostream) const
    {
        ostream << getFirstName() << " " << getLastName() << endl
                << "id - " << getId() << " birth_year - "
                << getBirthYear() << endl
                << "Salary: " << getSalary() << endl;

        if (employees.size() > 0)
            ostream << "Employees: " << endl;

        for (const std::pair<long, Employee *> employee_pair : this->employees)
        {
            employee_pair.second->printShort(ostream);
        }
    }

    Manager *Manager::clone()
    {
        Manager* copy = new Manager(getId(), getFirstName(), getLastName(), getBirthYear());
        copy->setSalary(this->getSalary());
        map<long, Employee *> copy_employees = map<long, Employee *>(this->employees);
        copy->employees = copy_employees;
        return copy;
    }

    bool Manager::isEmployeeExists(Employee* employee)
    {
        return isEmployeeExists(employee->getId());
    }

    bool Manager::isEmployeeExists(long id)
    {
        return employees.count(id) > 0;
    }
    void Manager::addEmployee(Employee* employee)
    {
        if(isEmployeeExists(employee)){
            throw EmployeeAlreadyHired();
        } else {
            employees.insert({employee->getId(), employee});
        }
    }
    void Manager::removeEmployee(long id)
    {
        if(!isEmployeeExists(id)){
            throw EmployeeIsNotHired();
        } else {
            employees.erase(id);
        }
    }

    Employee *Manager::getEmployeeById(long id)
    {
        if (!isEmployeeExists(id)) {
            throw EmployeeIsNotHired();
    }
        return (*employees.find(id)).second;
    }

    std::map<long, Employee *> Manager::getEmployeeSet() const
    {
        return this->employees;
    }


}
