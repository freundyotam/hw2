//
// Created by yotam freund on 29/12/2021.
//

#include "exceptions.h"
#include "manager.h"
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
        Manager::salary = +salary;
    }
    void Manager::printShort(std::ostream& ostream) const
    {
        ostream << getFirstName() << " " << getLastName() << endl << "Salary: " << getSalary() << endl;
    }
    void Manager::printLong(std::ostream& ostream) const
    {
        ostream << getFirstName() << " " << getLastName() << endl << "id - " << getId() << "birth_year - "
        << getBirthYear() <<  " Salary: " << getSalary() << "Employees:" << endl;
        for (const std::pair<long, Employee *> employee_pair : this->employees)
        {
            employee_pair.second->printShort(ostream);
        }
    }

    Manager *Manager::clone()
    {
        Manager* copy = new Manager(getId(), getFirstName(), getLastName(), getBirthYear());
        copy->employees = employees;
        return copy; // Is this the correct way?
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
            employees.erase(id); // Is this the correct way?
        }
    }

    Employee *Manager::getEmployeeById(long id)
    {
        if (isEmployeeExists(id))
            throw; // EmployeeDoesNotExist();

        return (*employees.find(id)).second;
    }

    std::map<long, Employee *> Manager::getEmployeeSet() const
    {
        return this->employees;
    }


}
