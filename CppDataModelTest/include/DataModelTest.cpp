#include <gtest/gtest.h>
#include <Field.h>
#include <DataModel.h>
#include <DataModelErrors.h>

namespace
{
// Local Constants
const std::vector<std::string> fieldnames {
	"testfield1",
	"testfield2",
	"testfield3",
	"testfield4" 
};
}

namespace DataModel
{
TEST(DataModel, ManualModel_getFields)
{
	Field<int>  field1(fieldnames[0]);
	Field<bool> field2(fieldnames[1], false);

	FieldList fields{
		field1,
		field2
	};

	DataModel testmodel("testmodel", fields);

	auto validNames = std::vector<std::string>(fieldnames.begin(), fieldnames.begin() + 2);

	ASSERT_EQ(validNames, testmodel.getFieldNames());
	for (int i = 0; i < fields.size(); ++i)
	{
		auto const f1 = fields[i];
		auto const f2 = testmodel.getFields()[i];
		ASSERT_TRUE(f1.get() == f2.get());
	}
}

TEST(DataModel, ManualModel_getField)
{
	Field<int>   field1(fieldnames[0]);
	Field<bool>  field2(fieldnames[1]);
	Field<float> field3(fieldnames[2]);
	Field<int>   field4(fieldnames[3]);

	FieldList fields{
		field1,
		field2,
		field3,
		field4
	};

	DataModel testmodel("testmodel", fields);

	ASSERT_EQ(field1, testmodel.getField(fieldnames[0]));
	ASSERT_EQ(field2, testmodel.getField(fieldnames[1]));
	ASSERT_EQ(field3, testmodel.getField(fieldnames[2]));
	ASSERT_EQ(field4, testmodel.getField(fieldnames[3]));
}

TEST(DataModel, ManualModel_getField_dont_exist)
{
	Field<int>   field1(fieldnames[0]);
	Field<bool>  field2(fieldnames[1]);
	Field<float> field3(fieldnames[2]);

	FieldList fields{
		field1,
		field2,
		field3
	};

	DataModel testmodel("testmodel", fields);

	ASSERT_THROW(testmodel.getField(fieldnames[3]), DMInvalidFieldError);
}

TEST(DataModel, ManualModel_getField_const)
{
	Field<int>   field1(fieldnames[0]);
	Field<bool>  field2(fieldnames[1]);
	Field<float> field3(fieldnames[2]);
	Field<int>   field4(fieldnames[3]);

	FieldList fields{
		field1,
		field2,
		field3,
		field4
	};

	const DataModel testmodel("testmodel", fields);

	ASSERT_EQ(field1, testmodel.getField(fieldnames[0]));
	ASSERT_EQ(field2, testmodel.getField(fieldnames[1]));
	ASSERT_EQ(field3, testmodel.getField(fieldnames[2]));
	ASSERT_EQ(field4, testmodel.getField(fieldnames[3]));
}

TEST(DataModel, ManualModel_getField_const_dont_exist)
{
	Field<int>   field1(fieldnames[0]);
	Field<bool>  field2(fieldnames[1]);
	Field<float> field3(fieldnames[2]);

	FieldList fields{
		field1,
		field2,
		field3
	};

	const DataModel testmodel("testmodel", fields);

	ASSERT_THROW(testmodel.getField(fieldnames[3]), DMInvalidFieldError);
}


/// <summary>
/// Get field should return first if more than 1 with the same name;
/// To be reviewed if requisite change
/// </summary>
TEST(DataModel, ManualModel_getField_duplicated_name)
{
	Field<int>   field1(fieldnames[0]);
	Field<bool>  field2(fieldnames[1]);
	Field<float> field3(fieldnames[1]);

	FieldList fields{
		field1,
		field2,
		field3
	};

	DataModel testmodel("testmodel", fields);

	ASSERT_EQ(field1, testmodel.getField(fieldnames[0]));
	ASSERT_EQ(field2, testmodel.getField(fieldnames[1]));
}

/// <summary>
/// Get field should return first if more than 1 with the same name;
/// To be reviewed if requisite change
/// </summary>
TEST(DataModel, ManualModel_getField_const_duplicated_name)
{
	Field<int>   field1(fieldnames[0]);
	Field<bool>  field2(fieldnames[1]);
	Field<float> field3(fieldnames[1]);

	FieldList fields{
		field1,
		field2,
		field3
	};

	DataModel testmodel("testmodel", fields);

	ASSERT_EQ(field1, testmodel.getField(fieldnames[0]));
	ASSERT_EQ(field2, testmodel.getField(fieldnames[1]));
}
}