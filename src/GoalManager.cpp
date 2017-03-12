#include "GoalManager.h"
#include "GoalFactory.h"

using namespace std;

GoalIdentifier GoalManager::create_goal(const std::string& desc, AcTick total, AcTick done, Goal* parent)
{
	GoalIdentifier id = make_tuple(head_goals.size() + 1, HEAD_GOAL_SUB_ID);
	Goal* goal = GoalFactory::create_goal(desc, total, done, id ,parent);

	if (!parent)
		head_goals.push_back(unique_ptr<Goal>(goal));

	return id;
}
