#include "Goal.h"

using namespace std;

void Goal::add_sub_goal(Goal* goal)
{
	sub_goals.push_back(GoalUniquePointer(goal));
}

size_t Goal::sub_goals_count() const
{
	return sub_goals.size();
}