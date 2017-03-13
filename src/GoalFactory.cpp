#include "GoalFactory.h"

#include <assert.h>

using namespace std;

Goal* GoalFactory::create_goal(const std::string& description, AcTick total, AcTick done, GoalIdentifier id, Goal* parent)
{
	GoalIdentifier id;
	if (parent)
		id.parent_id = parent->identifier.get_in_parent_id();


	assert(!description.empty());
	assert(total >= done);
	Goal* goal = new Goal(description, total, done, id);

	if (parent)
		parent->add_sub_goal(goal);
	return goal;
}
