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

TEST(GoalManagerTest, TestGoalStep)
{
	GoalManager goal_manager;
	Goal* a = goal_manager.create_goal("desc", 12, 10, nullptr, "word");
	EXPECT_EQ(a->get_step_unit(), "word");

	Goal* b = goal_manager.create_goal("Desc 2", 12, 10, a);
	EXPECT_EQ(b->get_step_unit(), "word");

	Goal* c = goal_manager.create_goal("Desc 2", 12, 10, b);
	EXPECT_EQ(c->get_step_unit(), "word");
}

TEST(GoalActickTest, TestTotalActick)
{
	GoalManager goal_manager;
	Goal* a = goal_manager.create_goal("desc", 12, 10);
	Goal* b = goal_manager.create_goal("Desc 2", 12, 10, a);
	EXPECT_EQ(a->get_total_actick(), 24);
	EXPECT_EQ(b->get_total_actick(), 12);
}

TEST(GoalActickTest, TestDonelActick)
{
	GoalManager goal_manager;
	Goal* a = goal_manager.create_goal("desc", 12, 10);
	Goal* b = goal_manager.create_goal("Desc 2", 12, 10, a);
	EXPECT_EQ(a->get_done_actick(), 20);
	EXPECT_EQ(b->get_done_actick(), 10);
}

TEST(GoalActickTest, TestProgressPercent)
{
	GoalManager goal_manager;
	Goal* a = goal_manager.create_goal("desc");
	Goal* b = goal_manager.create_goal("Desc 2", 10, 5, a);
	Goal* c = goal_manager.create_goal("Desc 2", 30, 5, a);
	EXPECT_EQ(a->get_progress_percent(), 25);
	EXPECT_EQ(b->get_progress_percent(), 50);
	EXPECT_NEAR(c->get_progress_percent(), 16.6, 0.07);
	c->set_done_actick(15);
	EXPECT_EQ(a->get_progress_percent(), 50);
	EXPECT_EQ(b->get_progress_percent(), 50);
	EXPECT_EQ(c->get_progress_percent(), 50);
	c->set_done_actick(30);
	b->set_done_actick(10);
	EXPECT_EQ(a->get_progress_percent(), 100);
	EXPECT_EQ(b->get_progress_percent(), 100);
	EXPECT_EQ(c->get_progress_percent(), 100);
	a->set_total_actick(60);
	EXPECT_EQ(a->get_progress_percent(), 40);
	EXPECT_EQ(b->get_progress_percent(), 100);
	EXPECT_EQ(c->get_progress_percent(), 100);
	Goal* d = goal_manager.create_goal("Desc 2", 100, 0, b);
	EXPECT_EQ(a->get_progress_percent(), 20);
	EXPECT_NEAR(b->get_progress_percent(), 9, 0.1);
	EXPECT_EQ(c->get_progress_percent(), 100);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

