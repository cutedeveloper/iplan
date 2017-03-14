#ifndef GOAL_MANAGER_H_
#define GOAL_MANAGER_H_

#include "Goal.h"

class GoalManager
{
public:
	GoalManager()
	{

	}

	Goal* create_goal(const std::string& desc, AcTick total = 0, AcTick done = 0, Goal* parent = nullptr);

private:
	Goals head_goals;
};

#endif
