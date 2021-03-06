#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

namespace mtm
{
    class Exception : public std::exception
    {
    };

    class NegativePoints : public Exception
    {
    };

    class EmployeeDoesNotExist : public Exception
    {
    };

    class ManagerDoesNotExist : public Exception
    {
    };

    class WorkplaceAlreadyExists : public Exception
    {
    };

    class FacultyAlreadyExists : public Exception
    {
    };

    class CitizenAlreadyExists : public Exception
    {
    };

    class FacultyDoesNotExist : public Exception
    {
    };

    class WorkplaceDoesNotExist : public Exception
    {
    };

    class EmployeeNotAccepted : public Exception
    {
    };

    class ManagerIsNotHired : public Exception
    {
    };

    class ManagerAlreadyHired : public Exception
    {
    };

    class EmployeeNotSelected : public Exception
    {
    };

    class EmployeeIsNotHired : public Exception
    {
    };

    class EmployeeAlreadyHired : public Exception
    {
    };

    class SkillAlreadyLearned : public Exception
    {
    };

    class CanNotLearnSkill : public Exception
    {
    };

    class DidNotLearnSkill : public Exception
    {
    };

    class CanNotHireManager : public Exception
    {
    };
}

#endif // EXCEPTIONS_H