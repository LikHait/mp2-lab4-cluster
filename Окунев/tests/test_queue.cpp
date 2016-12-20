#include "queue.h"
#include <gtest.h>

TEST(TPostfix, can_create_queue_with_pos_size)
{
    ASSERT_NO_THROW(TQueue<int> queue(25));
}

TEST(TPostfix, can_add_new_node)
{
    TQueue<int> queue(5);
    int a = 5;
    ASSERT_NO_THROW(queue.InsFirst(a));
}

TEST(TPostfix, can_get_size_of_queue)
{
    TQueue<int> queue(5);
    EXPECT_EQ(queue.GetCount(), 0);
}

TEST(TPostfix, add_new_node_increases_size_of_queue)
{
    TQueue<int> queue((size_t)5);
    int a = 5;
    queue.InsFirst(a);
    EXPECT_EQ(queue.GetCount(), 1);
}

TEST(TPostfix, can_delete_node)
{
    TQueue<int> queue((size_t)5);
    int a = 5;
    queue.InsFirst(a);
    ASSERT_NO_THROW(queue.DelFirst());
}

TEST(TPostfix, delete_node_reduces_size_of_queue)
{
    TQueue<int> queue((size_t)5);
    int a = 5;
    queue.InsFirst(a);
    queue.DelFirst();
    EXPECT_EQ(queue.GetCount(), 0);
}

TEST(TPostfix, IsEmpty_is_correct)
{
    TQueue<int> queue((size_t)5);
    EXPECT_EQ(queue.IsEmpty(), 1);
}

TEST(TPostfix, IsFull_is_correct)
{
    size_t b = 3;
    TQueue<int> queue(b);
    int a = 5;
    for (int i = 0; i < b; i++)
        queue.InsFirst(a);
    EXPECT_EQ(queue.IsFull(), 1);
}

TEST(TPostfix, can_get_priority_of_node)
{
    size_t b = 3;
    TQueue<int> queue(b);
    int a = 5;
    for (int i = 0; i < b; i++)
        queue.InsFirst(a);
    EXPECT_EQ(queue.GetPriority(0), 0);
}

