#pragma once
#include <string>
#include <typeinfo>

namespace DataModel
{
class IField
{
protected:
    IField() {}

public:
    /// <summary>
    /// Get the name of the field
    /// </summary>
    virtual std::string getName() const = 0;
    /// <summary>
    /// Get the type of this field
    /// </summary>
    virtual std::type_info const& getType() const = 0;
    /// <summary>
    /// Returns if this field has a defined value
    /// </summary>
    virtual bool isDefined() const = 0;
    /// <summary>
    /// Comparation operator
    /// </summary>
    virtual bool operator==(const IField& other) const = 0;
    /// <summary>
    /// Gets the field value, if defined
    /// </summary>
    /// <exception cref="FieldError">
    /// When value not defined
    /// </exception>
    /// <returns>Pointer to the value as void*</returns>
    virtual void const* getValueVoid() const = 0;
};
}
