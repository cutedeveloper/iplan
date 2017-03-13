#include "GoalFactory.h"

#include <assert.h>

using namespace std;

Goal* GoalFactory::create_goal(const std::string& description, AcTick total, AcTick done, Goal* parent, int in_parent_id)
{
	assert(!description.empty());
	assert(total >= done);

	GoalIdentifier id;
	if (parent)
		id.set_parent_id(parent->get_in_parent_id());
	else
		id.set_in_parent_id(in_parent_id);

	Goal* goal = new Goal(description, total, done, id);

	if (parent)
		parent->add_sub_goal(goal);
	return goal;
}
