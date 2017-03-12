#ifndef GOAL_MANAGER_H_
#define GOAL_MANAGER_H_

#include "Goal.h"

class GoalManager
{
public:
	GoalManager()
	{

	}

	GoalIdentifier create_goal(const std::string& desc, AcTick total, AcTick done, Goal* parent = nullptr);

private:
	Goals head_goals;
};

#endif
