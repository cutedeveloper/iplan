// In the name of God

#include "GoalManager.h"

int main(int argc, char** argv)
{
	GoalManager goal_manager;
	Goal* a = goal_manager.create_goal("desc", 12, 10);

	printf("goal(%d, %d)", a->get_parent_id(), a->get_in_parent_id());

	Goal* b = goal_manager.create_goal("Desc 2", 12, 10, a);
	printf("goal(%d, %d)", b->get_parent_id(), b->get_in_parent_id());

	Goal* c = goal_manager.create_goal("Desc 2", 12, 10, a);
	printf("goal(%d, %d)", c->get_parent_id(), c->get_in_parent_id());

	Goal* d = goal_manager.create_goal("Desc 2", 12, 10);
	printf("goal(%d, %d)", d->get_parent_id(), d->get_in_parent_id());
}
