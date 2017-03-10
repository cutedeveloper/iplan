#include "GoalFactory.h"

using namespace std;

Goal* GoalFactory::create_goal(std::string description, AcTick total, AcTick done, Goal* parent)
{
	Goal* goal = new Goal(description, total, done);

	if (parent)
		parent->add_sub_goal(goal);

	return goal;
}
