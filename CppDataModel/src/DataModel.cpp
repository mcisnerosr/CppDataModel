#include "DataModel.h"
#include "DataModelErrors.h"

namespace DataModel
{
DataModel::DataModel(std::string const& name, FieldList const& fields):
    name(name), fields(fields)
{
}

std::vector<std::string> DataModel::getFieldNames() const
{
    std::vector<std::string> fieldnames;
    fieldnames.reserve(fields.size());

    for (auto f: fields)
    {
        fieldnames.push_back(f.get().getName());
    }

    return fieldnames;
}

FieldList DataModel::getFields() const
{
    return fields;
}
IField const& DataModel::getField(std::string const& fname) const
{
    auto found = std::find_if(
        fields.begin(), fields.end(),
        [&fname](const IField& x) { return x.getName() == fname; });

    if (found == fields.end())
    {
        throw DMInvalidFieldError("Invalid field name " + fname + " in model " + name);
    }
    return *found;
}
IField& DataModel::getField(std::string const& fname)
{
    auto found = std::find_if(
        fields.begin(), fields.end(),
        [&fname](const IField& x) { return x.getName() == fname; });

    if (found == fields.end())
    {
        throw DMInvalidFieldError("Invalid field name " + fname + " in model " + name);
    }
    return *found;
}
}
