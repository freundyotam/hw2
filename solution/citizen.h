//
// Created by yotam freund on 30/12/2021.
//

#ifndef UNTITLED_CITIZEN_H
#define UNTITLED_CITIZEN_H


#include <string>

class Citizen {
    long id;
    std::string name;
    std::string last_name;
    int year_of_birth;
public:
    Citizen(long id, const std::string &name, const std::string &lastName, int yearOfBirth);

public:
    long getId() const;
    const std::string &getName() const;
    const std::string &getLastName() const;
    int getYearOfBirth() const;
    virtual void printShort(std::ostream) const;
    virtual void printLong(std::ostream) const;
    Citizen* clone();
};


#endif //UNTITLED_CITIZEN_H
