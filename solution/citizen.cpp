//
// Created by yotam freund on 30/12/2021.
//

#include "citizen.h"

long mtm::Citizen::getId() const
{
    return id;
}

const std::string &mtm::Citizen::getName() const
{
    return name;
}

const std::string &mtm::Citizen::getLastName() const
{
    return last_name;
}

int mtm::Citizen::getYearOfBirth() const
{
    return year_of_birth;
}

mtm::Citizen::Citizen(long id, const std::string &name, const std::string &lastName, int yearOfBirth) : id(id), name(name),
                                                                                                   last_name(lastName),
                                                                                                   year_of_birth(
                                                                                                           yearOfBirth)
{}
