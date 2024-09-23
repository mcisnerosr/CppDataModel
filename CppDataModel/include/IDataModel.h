#pragma once
#include <vector>
#include <string>

#include "IField.h"

namespace DataModel
{
/// <summary>
/// Definition of the type used for lists of fields, extracted here for ease of refactoring
/// </summary>
typedef std::vector<std::reference_wrapper<IField>> FieldList;

/// <summary>
/// Basic interface that support the data modeling, offering access to all the fields of the model
/// </summary>
class IDataModel
{
public:
    virtual ~IDataModel() {}

    /// <summary>
    /// Get the list of the name of all the fields represented in this data model
    /// </summary>
    virtual std::vector<std::string> getFieldNames() const = 0;
    /// <summary>
    /// Get the list of all the fields represented in this data model
    /// </summary>
    virtual FieldList getFields() const = 0;
    /// <summary>
    /// Get field by name
    /// </summary>
    virtual IField const& getField(std::string const&) const = 0;
    /// <summary>
    /// Get field by name
    /// </summary>
    virtual IField& getField(std::string const&) = 0;
};
}
