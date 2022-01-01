//
// Created by yotam freund on 30/12/2021.
//

#include "citizen.h"
#include <ostream>
namespace mtm{
    long Citizen::getId() const
    {
        return id;
    }

    const std::string &Citizen::getName() const
    {
        return name;
    }

    const std::string &Citizen::getLastName() const
    {
        return last_name;
    }

    int Citizen::getYearOfBirth() const
    {
        return year_of_birth;
    }

    Citizen::Citizen(long id, const std::string &name, const std::string &lastName, int yearOfBirth) : id(id), name(name),
                                                                                                            last_name(lastName),
                                                                                                            year_of_birth(
                                                                                                                    yearOfBirth)
    {}

    void Citizen::printShort(std::ostream) const
    {

    }
    void Citizen::printLong(std::ostream) const
    {

    }

}
