#include "pch.h"
#include "../lab4-cluster/queue.h"


TEST(Queue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(Queue<int> q(5));
}

TEST(Queue, cant_create_queue_with_negative_length)
{
	EXPECT_ANY_THROW(Queue<int> q(-1));
}

TEST(Queue, method_empty_for_empty_queue_return_true)
{
	Queue<int> q(5);

	EXPECT_TRUE(q.Empty());
}

TEST(Queue, method_empty_for_not_empty_queue_return_false)
{
	Queue<int> q(5);
	q.Push(1);
	EXPECT_FALSE(q.Empty());
}

TEST(Queue, method_full_for_full_queue_return_true)
{
	Queue<int> q(5);
	for (int i = 0; i < 5; ++i)
		q.Push(1);
	EXPECT_TRUE(q.Full());
}

TEST(Queue, method_full_for_not_full_queue_return_false)
{
	Queue<int> q(5);
	for (int i = 0; i < 4; ++i)
		q.Push(1);
	EXPECT_FALSE(q.Full());
}

TEST(Queue, can_get_size_of_queue)
{
	Queue<int> q(10);

	EXPECT_EQ(q.Size(), 0);

	for (int i = 0; i < 4; ++i)
		q.Push(1);

	EXPECT_EQ(q.Size(), 4);

	for (int i = 0; i < 6; ++i)
		q.Push(3);

	EXPECT_EQ(q.Size(), 10);
}

TEST(Queue, can_push_element_into_not_full_queue)
{
	Queue<int> q(5);
	ASSERT_NO_THROW(q.Push(1));
}

TEST(Queue, cant_push_element_into_full_queue)
{
	Queue<int> q(5);
	for (int i = 0; i < 5; ++i)
		q.Push(1);
	ASSERT_ANY_THROW(q.Push(1));
}

TEST(Queue, can_pop_and_top_element_from_not_empty_queue)
{
	Queue<int> q(3);
	q.Push(1);

	ASSERT_NO_THROW(q.Pop());

	q.Push(1);

	ASSERT_NO_THROW(q.Top());
}

TEST(Queue, cant_pop_and_top_element_from_empty_queue)
{
	Queue<int> q(3);
	ASSERT_ANY_THROW(q.Pop());
	ASSERT_ANY_THROW(q.Top());
}

TEST(Queue, method_top_return_top_element)
{
	Queue<int> q(3);
	for (int i = 0; i < 3; ++i)
		q.Push(i);

	EXPECT_EQ(q.Top(), 0);
	q.Pop();
	EXPECT_EQ(q.Top(), 1);
	q.Pop();
	EXPECT_EQ(q.Top(), 2);
}

TEST(Queue, method_pop_decrement_size)
{
	Queue<int> q(10);
	for (int i = 0; i < 5; ++i)
		q.Push(1);
	q.Pop();

	EXPECT_EQ(q.Size(), 4);
}

TEST(Queue, method_top_doesnt_change_size)
{
	Queue<int> q(10);
	for (int i = 0; i < 5; ++i)
		q.Push(1);
	q.Top();

	EXPECT_EQ(q.Size(), 5);
}





