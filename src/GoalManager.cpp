#include "GoalManager.h"
#include "GoalFactory.h"

using namespace std;

int GoalManager::create_goal(const std::string& desc, AcTick total, AcTick done, Goal* parent)
{
	Goal* goal = GoalFactory::create_goal(desc, total, done);

	if (parent)
		parent->add_sub_goal(goal);
	else
		head_goals.push_back(unique_ptr<Goal>(goal));
}
