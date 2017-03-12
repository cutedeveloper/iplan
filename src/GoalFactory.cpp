#include "GoalFactory.h"

#include <assert.h>

using namespace std;

Goal* GoalFactory::create_goal(const std::string& description, AcTick total, AcTick done)
{
	assert(!description.empty());
	assert(total >= done);
	Goal* goal = new Goal(description, total, done);
	return goal;
}
