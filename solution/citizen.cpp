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

    const std::string &Citizen::getFirstName() const
    {
        return name;
    }

    const std::string &Citizen::getLastName() const
    {
        return last_name;
    }

    int Citizen::getBirthYear() const
    {
        return year_of_birth;
    }

    Citizen::Citizen(long id, const std::string &name, const std::string &lastName, int yearOfBirth) : id(id), name(name),
                                                                                                            last_name(lastName),
                                                                                                            year_of_birth(
                                                                                                                    yearOfBirth)
    {}

    bool Citizen::operator==(const Citizen &rhs) const
    {
        return id == rhs.id;
    }

    bool Citizen::operator!=(const Citizen &rhs) const
    {
        return !(rhs == *this);
    }

    bool Citizen::operator<(const Citizen &rhs) const
    {
        return id < rhs.id;
    }

    bool Citizen::operator>(const Citizen &rhs) const
    {
        return rhs < *this;
    }

    bool Citizen::operator<=(const Citizen &rhs) const
    {
        return !(rhs < *this);
    }

    bool Citizen::operator>=(const Citizen &rhs) const
    {
        return !(*this < rhs);
    }
}
