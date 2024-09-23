#pragma once
#include <string>
#include <stdexcept>

namespace DataModel
{
class DMInvalidFieldError: public std::invalid_argument
{
public:
    DMInvalidFieldError(std::string const& message): std::invalid_argument(message)
    {}
};
}
