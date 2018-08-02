#include "queue.h"
#include "cluster.h"
#include <gtest.h>

TEST(TCluster, can_create_cluster)
{
    ASSERT_NO_THROW(TCluster queue(0, 64, 10, 5));
}

