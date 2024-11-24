#include "pch.h"
#include "../lab4-cluster/stack.h"

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(Stack<int> st(5));
}

TEST(Stack, cant_create_stack_with_negative_length)
{
	EXPECT_ANY_THROW(Stack<int> st(-1));
}

TEST(Stack, method_empty_for_empty_stack_return_true)
{
	Stack<int> st(5);
	EXPECT_TRUE(st.Empty());
}

TEST(Stack, method_empty_for_not_empty_stack_return_false)
{
	Stack<int> st(5);
	st.Push(1);
	EXPECT_FALSE(st.Empty());
}

TEST(Stack, method_full_for_full_stack_return_true)
{
	Stack<int> st(5);
	for (int i = 0; i < 5; ++i)
		st.Push(1);
	EXPECT_TRUE(st.Full());
}

TEST(Stack, method_full_for_not_full_stack_return_false)
{
	Stack<int> st(5);
	for (int i = 0; i < 4; ++i)
		st.Push(1);
	EXPECT_FALSE(st.Full());
}

TEST(Stack, can_get_size_of_stack)
{
	Stack<int> st(10);
	for (int i = 0; i < 4; ++i)
		st.Push(1);
	EXPECT_EQ(st.Size(), 4);
}

TEST(Stack, can_push_element_into_not_full_stack)
{
	Stack<int> st(5);
	ASSERT_NO_THROW(st.Push(1));
}

TEST(Stack, cant_push_element_into_full_stack)
{
	Stack<int> st(5);
	for (int i = 0; i < 5; ++i)
		st.Push(1);
	ASSERT_ANY_THROW(st.Push(1));
}

TEST(Stack, can_pop_and_top_element_from_not_empty_stack)
{
	Stack<int> st(3);
	st.Push(1);
	ASSERT_NO_THROW(st.Pop());
	st.Push(1);
	ASSERT_NO_THROW(st.Top());
}

TEST(Stack, cant_pop_and_top_element_from_empty_stack)
{
	Stack<int> st(3);
	ASSERT_ANY_THROW(st.Pop());
	ASSERT_ANY_THROW(st.Top());
}

TEST(Stack, method_top_return_top_element)
{
	Stack<int> st(3);
	st.Push(147);
	EXPECT_EQ(st.Top(), 147);
}

TEST(Stack, method_pop_decrement_size)
{
	Stack<int> st(10);
	for (int i = 0; i < 5; ++i)
		st.Push(1);
	st.Pop();
	EXPECT_EQ(st.Size(), 4);
}

TEST(Stack, method_top_doesnt_change_size)
{
	Stack<int> st(10);
	for (int i = 0; i < 5; ++i)
		st.Push(1);
	st.Top();
	EXPECT_EQ(st.Size(), 5);
}

TEST(Stack, can_clear_stack)
{
	Stack<int> st(10);
	ASSERT_NO_THROW(st.Clear());
}

TEST(Stack, size_equals_zero_after_clear_stack)
{
	Stack<int> st(10);
	for (int i = 0; i < 5; ++i)
		st.Push(1);
	st.Clear();
	EXPECT_EQ(st.Size(), 0);
}
