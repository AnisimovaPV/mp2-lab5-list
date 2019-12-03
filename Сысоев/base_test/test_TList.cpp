#include "TList.h"
#include <gtest.h>

//INDICATOR
TEST(TIndicator, can_create_indicator)
{
	ASSERT_NO_THROW(TList<int>::TIndicator ind);
}

TEST(TIndicator, can_create_copied_indicator)
{
	TList<int>::TIndicator ind1;
	TList<int>::TIndicator ind2(ind1);

	ASSERT_NO_THROW(ind2);
}

TEST(TIndicator, can_assign_indicator)
{
	TList<int>::TIndicator ind1;
	TList<int>::TIndicator ind2;
	ind2 = ind1;
	ASSERT_NO_THROW(ind2);
}

TEST(TIndicator, can_rename_indicator)
{
	TList<int> list;
	TList<int>::TIndicator ind;
	list.AddNodeInEnd(5);
	ind = list.Begin();
	EXPECT_TRUE(&(ind)==5 );
}

TEST(TIndicator, can_increment_indicator)
{
	TList<int> list;
	list.AddNodeInEnd(5);
	list.AddNodeInEnd(55);
	TList<int>::TIndicator ind;
	ind = list.Begin();
	++ind;
	EXPECT_TRUE(&(ind) == 55);
}

//LIST
TEST(TList, can_create_double_list)
{
	ASSERT_NO_THROW(TList<double> list);
}
TEST(TList, can_create_int_list)
{
	ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, can_add_node_in_end)
{
	TList<int> list;
	ASSERT_NO_THROW(list.AddNodeInEnd(5));
}

TEST(TList, can_compare_two_same_lists)
{
	TList<int> list1;
	TList<int> list2;

	list1.AddNodeInEnd(5);
	list2.AddNodeInEnd(5);
	EXPECT_TRUE(list1 == list2);
}
TEST(TList, can_compare_two_different_lists)
{
	TList<int> list1;
	TList<int> list2;

	list1.AddNodeInEnd(5);
	list2.AddNodeInEnd(55);
	EXPECT_TRUE(list1 != list2);
}
TEST(TList, can_check_for_empty_ex_1)
{
	TList<int> list;
	EXPECT_TRUE(list.IsEmpty());
}
TEST(TList, can_check_for_empty_ex_2)
{
	TList<int> list;
	for (int i = 0; i < 5; i++)
	{
		list.AddNodeInEnd(i);
	}
	list.DeleteAllNodes();
	EXPECT_TRUE(list.IsEmpty());
}

TEST(TList, two_lists_with_different_sizes_are_not_equal)
{
	TList<int> list1;
	TList<int> list2;
	for (int i = 1; i < 5; i++)
	{
		list1.AddNodeInEnd(i);
	}
	list2.AddNodeInEnd(5);
	EXPECT_TRUE(list1 != list2);
}

TEST(TList, can_assign_list)
{
	TList<int> list1;
	TList<int> list2;
	list1.AddNodeInEnd(5);
	ASSERT_NO_THROW(list2 = list1);
}

TEST(TList, can_return_size_of_list_ex_1)
{
	TList<int> list;
	for (int i = 0; i < 5; i++)
	{
		list.AddNodeInEnd(i);
	}
	EXPECT_TRUE(5 == list.GetSize());
}
TEST(TList, can_return_size_of_list_ex_2)
{
	TList<int> list;
	for (int i = 0; i < 8; i++)
	{
		list.AddNodeInEnd(i);
	}
	EXPECT_TRUE(8 == list.GetSize());
}

TEST(TList, method_del_delete_all_nodes_of_list)
{
	TList<int> list;
	for (int i = 0; i < 5; i++)
	{
		list.AddNodeInEnd(i);
	}
	list.DeleteAllNodes();
	EXPECT_TRUE(list.IsEmpty());
}

TEST(TList, can_delete_node_by_indicator)
{
	TList<int> list;
	TList<int>::TIndicator i;
	list.AddNodeInEnd(5);
	i = list.Begin();
	ASSERT_NO_THROW(list.Delete(i));
}

TEST(TList, can_insert_node_by_indicator)
{
	TList<int> list;
	TList<int>::TIndicator i;
	i = list.Begin();
	list.Insert(i, 3);
	EXPECT_TRUE(1 == list.GetSize());
}