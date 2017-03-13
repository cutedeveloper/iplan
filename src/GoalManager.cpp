#include "GoalManager.h"
#include "GoalFactory.h"

using namespace std;

Goal* GoalManager::create_goal(const std::string& desc, AcTick total, AcTick done, Goal* parent)
{
	Goal* goal = GoalFactory::create_goal(desc, total, done, parent, head_goals.size() + 1);
	if (!parent)
		head_goals.push_back(unique_ptr<Goal>(goal));

	return goal;
}
