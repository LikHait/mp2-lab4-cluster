#include "queue.h"
#include <gtest.h>

TEST(TPostfix, can_create_queue_with_pos_size)
{
    ASSERT_NO_THROW(TQueue<int> queue(25));
}

TEST(TPostfix, can_add_new_note)
{
    TQueue<int> queue(5);
    ASSERT_NO_THROW(queue.InsFirst(5)); //ол
}
