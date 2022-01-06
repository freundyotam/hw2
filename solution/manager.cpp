//
// Created by yotam freund on 29/12/2021.
//

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
    void Manager::printShort(std::ostream) const
    {

    }
    void Manager::printLong(std::ostream) const
    {

    }

    Manager *Manager::clone() const
    {
        return NULL;
    }

    bool Manager::isEmployeeExists(Employee* employee)
    {
        return employees.find(*employee) != employees.end();
    }
    bool Manager::isEmployeeExists(long id)
    {
        set<Employee>::iterator it = employees.begin();
        while (it != employees.end())
        {
            if((*it).getId() == id){
                return true;
            }
            it++;
        }
        return false; //Code duplicates??
    }
    void Manager::addEmployee(Employee* employee)
    {
        if(isEmployeeExists(employee)){
            //raise EmployeeAlreadyHired
        } else {
            employees.insert(*employee);
        }
    }
    void Manager::removeEmployee(long id)
    {
        if(!isEmployeeExists(id)){
            //Raise EmployeeNotHired
        } else {
            employees.erase(employees.find())
        }
    }

}
