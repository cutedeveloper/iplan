#include <gtest/gtest.h>
#include "GoalManager.h"

TEST(GoalManagerTest, TestGoalCreation)
{
	GoalManager goal_manager;
	Goal* a = goal_manager.create_goal("desc", 12, 10);
	EXPECT_EQ(a->get_parent_id(), -1);
	EXPECT_EQ(a->get_in_parent_id(), 1);

	Goal* b = goal_manager.create_goal("Desc 2", 12, 10, a);
	EXPECT_EQ(b->get_parent_id(), 1);
	EXPECT_EQ(b->get_in_parent_id(), 1);

	Goal* c = goal_manager.create_goal("Desc 2", 12, 10, a);
	EXPECT_EQ(c->get_parent_id(), 1);
	EXPECT_EQ(c->get_in_parent_id(), 2);

	Goal* d = goal_manager.create_goal("Desc 2", 12, 10);
	EXPECT_EQ(d->get_parent_id(), -1);
	EXPECT_EQ(d->get_in_parent_id(), 2);

	Goal* e = goal_manager.create_goal("Desc 2", 12, 10, b);
	EXPECT_EQ(e->get_parent_id(), 1);
	EXPECT_EQ(e->get_in_parent_id(), 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

