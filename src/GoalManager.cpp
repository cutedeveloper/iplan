#include "GoalManager.h"
#include "GoalFactory.h"

using namespace std;

GoalIdentifier GoalManager::create_goal(const std::string& desc, AcTick total, AcTick done, Goal* parent)
{
	GoalIdentifier id(GoalIdentifier::HEAD_GOAL_PARENT_ID, head_goals.size());
	Goal* goal = GoalFactory::create_goal(desc, total, done, id ,parent);

	if (!parent)
		head_goals.push_back(unique_ptr<Goal>(goal));

	return id;
}
