#include "GoalManager.h"
#include "GoalFactory.h"

#include <iostream>

using namespace std;

Goal* GoalManager::create_goal(const std::string& desc, AcTick total, AcTick done, Goal* parent)
{
	Goal* goal = GoalFactory::create_goal(desc, total, done, parent, head_goals.size() + 1);
	if (!parent)
		head_goals.push_back(unique_ptr<Goal>(goal));

	return goal;
}

void GoalManager::print_goals()
{
	if (printer)
	printer->print_goal(head_goals);
}


