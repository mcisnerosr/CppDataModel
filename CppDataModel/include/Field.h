#pragma once
#include <vector>
#include <string>

#include "IField.h"
#include "FieldErrors.h"

namespace DataModel
{
template<typename T>
class Field : public IField
{
private:
    T value;
    std::string name;
    bool defined;

public:
    Field(std::string const& name) : IField(),
        name(name), defined(false), value(T())
    {}
    Field(std::string const& name, T value) : IField(),
        name(name), defined(true), value(value)
    {}

    std::string getName() const override;
    std::type_info const& getType() const override;
    void const* getValueVoid() const override;
    bool isDefined() const override;

    T getValue() const;
    void setValue(T v);

    bool operator==(const IField& other) const override;
    bool operator==(const Field<T>& other) const;
    template<typename T2>
    bool operator==(const Field<T2>& other) const;
};

template<typename T>
void const* Field<T>::getValueVoid() const
{
    if (!isDefined())
    {
        throw FieldError("Field value not defined for field: " + name);
    }
    return &value;
}

template<typename T>
std::string Field<T>::getName() const
{
    return name;
}
template<typename T>
std::type_info const& Field<T>::getType() const
{
    return typeid(T);
}
template<typename T>
bool Field<T>::isDefined() const
{
    return defined;
}

template<typename T>
T Field<T>::getValue() const
{
    if (!isDefined())
    {
        throw FieldError("Field value not defined for field: " + name);
    }
    return value;
}
template<typename T>
void Field<T>::setValue(T v)
{
    value = v;
    defined = true;
}

template<typename T>
bool Field<T>::operator==(const Field<T>& other) const
{
    if (other.getType() == getType()
        && other.getName() == getName()
        && other.isDefined() == isDefined())
    {
        if (!isDefined())
        {
            return true;
        }
        return other.getValue() == getValue();
    }
    return false;
}

template<typename T>
bool Field<T>::operator==(const IField& other) const
{
    if (other.getType() == getType()
        && other.getName() == getName()
        && other.isDefined() == isDefined())
    {
        if (!isDefined())
        {
            return true;
        }
        const T* other_value = reinterpret_cast<const T*>(other.getValueVoid());
        return getValue() == *other_value;
    }
    return false;
}

template<typename T> template<typename T2>
bool Field<T>::operator==(const Field<T2>& other) const
{
    return false;
}
}
