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
    void Manager::printShort(std::ostream& ostream) const
    {
        ostream << getFirstName() << " " << getLastName() << endl << "Salary: " << getSalary() << endl;
    }
    void Manager::printLong(std::ostream& ostream) const
    {
        ostream << getFirstName() << " " << getLastName() << endl << "id - " << getId() << "birth_year - "
        << getBirthYear() <<  " Salary: " << getSalary() << "Employees:" << endl;
        set<Employee>::iterator it = employees.begin();
        while (it != employees.end())
        {
            (*it).printShort(ostream);
            it++;
        } //Is this the correct way?
    }

    Manager *Manager::clone()
    {
        Manager* copy = new Manager(getId(), getFirstName(), getLastName(), getBirthYear());
        copy->employees = employees;
        return copy; // Is this the correct way?
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
            employees.erase(Employee(id, "", "", 0)); // Is this the correct way?
        }
    }

    const Employee* Manager::getEmployeeById(long id)
    {
        set<Employee>::iterator it = employees.begin();
        while (it != employees.end())
        {
            if((*it).getId() == id){
                return &(*it);
            }
            it++;
        }
        return NULL;
    }

    std::set<Employee> Manager::getEmployeeSet() const
    {
        return this->employees;
    }


}
