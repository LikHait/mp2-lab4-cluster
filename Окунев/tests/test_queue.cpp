#include "queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_pos_size)
{
    ASSERT_NO_THROW(TQueue<int> queue(25));
}

TEST(TQueue, can_add_new_node)
{
    TQueue<int> queue(5);
    int a = 5;
    ASSERT_NO_THROW(queue.InsFirst(a));
}

TEST(TQueue, can_get_real_size_of_queue)
{
    TQueue<int> queue(5);
    EXPECT_EQ(queue.GetCount(), 0);
}

TEST(TQueue, add_new_node_increases_size_of_queue)
{
    TQueue<int> queue((size_t)5);
    int a = 5;
    queue.InsFirst(a);
    EXPECT_EQ(queue.GetCount(), 1);
}

TEST(TQueue, can_delete_node)
{
    TQueue<int> queue((size_t)5);
    int a = 5;
    queue.InsFirst(a);
    ASSERT_NO_THROW(queue.DelFirst());
}

TEST(TQueue, delete_node_reduces_size_of_queue)
{
    TQueue<int> queue((size_t)5);
    int a = 5;
    queue.InsFirst(a);
    queue.DelFirst();
    EXPECT_EQ(queue.GetCount(), 0);
}

TEST(TQueue, IsEmpty_is_correct)
{
    TQueue<int> queue((size_t)5);
    EXPECT_EQ(queue.IsEmpty(), 1);
}

TEST(TQueue, IsFull_is_correct)
{
    size_t b = 3;
    TQueue<int> queue(b);
    int a = 5;
    for (int i = 0; i < b; i++)
        queue.InsFirst(a);
    EXPECT_EQ(queue.IsFull(), 1);
}

TEST(TQueue, can_get_element)
{
    size_t b = 3;
    TQueue<int> queue(b);
    int a = 5;
    for (int i = 0; i < b; i++)
        queue.InsFirst(a);
    EXPECT_EQ(queue.GetElement(0), a);
}

TEST(TQueue, can_get_priority_of_node)
{
    size_t b = 3;
    TQueue<int> queue(b);
    int a = 5;
    for (int i = 0; i < b; i++)
        queue.InsFirst(a);
    EXPECT_EQ(queue.GetPriority(0), 0);
}

TEST(TQueue, can_increase_priority)
{
    size_t b = 3;
    TQueue<int> queue(b);
    int a = 5;
    for (int i = 0; i < b; i++)
        queue.InsFirst(a);
    queue.IncPriority(0);
    EXPECT_EQ(queue.GetPriority(0), 1);
}

TEST(TQueue, can_change_element)
{
    size_t b = 3;
    TQueue<int> queue(b);
    int a = 5;
    for (int i = 0; i < b; i++)
        queue.InsFirst(a);
    int d = 10;
    queue.SetElement(d, 0);
    EXPECT_EQ(queue.GetElement(0), d);
}
