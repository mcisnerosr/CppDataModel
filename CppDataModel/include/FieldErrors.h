#pragma once
#include <string>
#include <stdexcept>

namespace DataModel
{
class FieldError: public std::invalid_argument
{
public:
    FieldError(std::string const& message): std::invalid_argument(message)
    {}
};

class FieldInvalidType: public std::invalid_argument
{
public:
    FieldInvalidType(std::string const& message): std::invalid_argument(message)
    {}
};
}
