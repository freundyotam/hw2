//
// Created by yotam freund on 30/12/2021.
//

#ifndef UNTITLED_CITIZEN_H
#define UNTITLED_CITIZEN_H

#include <string>
namespace mtm{
    class Citizen {
        long id;
        std::string name;
        std::string last_name;
        int year_of_birth;
        bool compare(const Citizen* citizen1, const Citizen* citizen2) const;
    public:
        Citizen(long id, const std::string &name, const std::string &lastName, int yearOfBirth);
        long getId() const;
        const std::string &getFirstName() const;
        const std::string &getLastName() const;
        int getBirthYear() const;
        virtual void printShort(std::ostream) const = 0;
        virtual void printLong(std::ostream) const = 0;
        virtual Citizen* clone() = 0;
        bool operator<(const Citizen &rhs) const;
        bool operator>(const Citizen &rhs) const;
        bool operator<=(const Citizen &rhs) const;
        bool operator>=(const Citizen &rhs) const;
        bool operator==(const Citizen &rhs) const;
        bool operator!=(const Citizen &rhs) const;
    };

}

#endif //UNTITLED_CITIZEN_H
