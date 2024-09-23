#include <gtest/gtest.h>
#include <Field.h>
#include <DataModel.h>

namespace
{
// Local Constants
const std::string name = "test field";
const std::string name2 = "test field 2";
const int value = 42;
const int value2 = 89;
}

namespace DataModel
{
TEST(FieldTest, EmptyField_getName)
{
    Field<int> field(name);
    ASSERT_EQ(name, field.getName());
}
TEST(FieldTest, EmptyField_getType)
{
    Field<int> field(name);
    ASSERT_EQ(typeid(int), field.getType());
}
TEST(FieldTest, EmptyField_isDefined)
{
    Field<int> field(name);
    ASSERT_FALSE(field.isDefined());
}
TEST(FieldTest, EmptyField_getValue)
{
    Field<int> field(name);
    ASSERT_THROW(field.getValue(), FieldError);
}
TEST(FieldTest, EmptyField_getValueVoid)
{
    Field<int> field(name);
    ASSERT_THROW(field.getValueVoid(), FieldError);
}
TEST(FieldTest, EmptyField_setValue)
{
    Field<int> field(name);

    ASSERT_FALSE(field.isDefined());
    field.setValue(value);
    ASSERT_TRUE(field.isDefined());
    ASSERT_EQ(value, field.getValue());
}
TEST(FieldTest, NonEmptyField_getName)
{
    Field<int> field(name, value);
    ASSERT_EQ(name, field.getName());
}
TEST(FieldTest, NonEmptyField_getType)
{
    Field<int> field(name, value);
    ASSERT_EQ(typeid(int), field.getType());
}
TEST(FieldTest, NonEmptyField_isDefined)
{
    Field<int> field(name, value);
    ASSERT_TRUE(field.isDefined());
}
TEST(FieldTest, NonEmptyField_getValue)
{
    Field<int> field(name, value);
    ASSERT_EQ(value, field.getValue());
}
TEST(FieldTest, NonEmptyField_getValueVoid)
{
    Field<int> field(name, value);

    const int* deref_value = reinterpret_cast<const int*>(field.getValueVoid());
    ASSERT_EQ(value, *deref_value);
}
TEST(FieldTest, NonEmptyField_setValue)
{
    Field<int> field(name, value);

    ASSERT_TRUE(field.isDefined());
    ASSERT_EQ(value, field.getValue());

    field.setValue(value2);

    ASSERT_TRUE(field.isDefined());
    ASSERT_EQ(value2, field.getValue());
}

TEST(FieldTest, operatorEq_IField)
{
    Field<int>  field(name);
    Field<int>  field2(name2);
    Field<int>  field3(name);
    Field<bool> field4(name);

    Field<int>  field_value (name, value);
    Field<int>  field_value2(name, value2);
    Field<int>  field_value3(name, value);
    Field<int>  field_value4(name2, value);
    Field<bool> field_value5(name, true);

    ASSERT_TRUE (field == static_cast<IField&>(field));
    ASSERT_FALSE(field == static_cast<IField&>(field2));
    ASSERT_TRUE (field == static_cast<IField&>(field3));
    ASSERT_FALSE(field == static_cast<IField&>(field4));

    ASSERT_TRUE (field_value == static_cast<IField&>(field_value));
    ASSERT_FALSE(field_value == static_cast<IField&>(field_value2));
    ASSERT_TRUE (field_value == static_cast<IField&>(field_value3));
    ASSERT_FALSE(field_value == static_cast<IField&>(field_value4));
    ASSERT_FALSE(field_value == static_cast<IField&>(field_value5));
}
TEST(FieldTest, operatorEq_Field)
{
    const std::string name = "test field";
    const std::string name2 = "test field 2";
    const int value  = 42;
    const int value2 = 89;
    Field<int>  field(name);
    Field<int>  field2(name2);
    Field<int>  field3(name);
    Field<bool> field4(name);

    Field<int>  field_value (name, value);
    Field<int>  field_value2(name, value2);
    Field<int>  field_value3(name, value);
    Field<int>  field_value4(name2, value);
    Field<bool> field_value5(name, true);

    ASSERT_TRUE (field == field);
    ASSERT_FALSE(field == field2);
    ASSERT_TRUE (field == field3);
    ASSERT_FALSE(field == field4);

    ASSERT_TRUE (field_value == field_value);
    ASSERT_FALSE(field_value == field_value2);
    ASSERT_TRUE (field_value == field_value3);
    ASSERT_FALSE(field_value == field_value4);
    ASSERT_FALSE(field_value == field_value5);
}
}