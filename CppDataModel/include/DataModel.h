#pragma once
#include <vector>
#include <string>

#include "IField.h"
#include "IDataModel.h"

namespace DataModel
{

class DataModel : public IDataModel
{
private:
    std::string name;
    FieldList fields;

public:
    DataModel(std::string const& name, FieldList const& fields);

    virtual ~DataModel() {}

    virtual std::vector<std::string> getFieldNames() const;
    virtual FieldList getFields() const;

    IField const& getField(std::string const&) const override;
    IField& getField(std::string const&) override;
};

#

#define MODEL_GENERATOR(DM_name, ...) \
class DM_name : public DataModel \
{ \
public: \
    DM_name () : name(DM_name) {} \
}






}