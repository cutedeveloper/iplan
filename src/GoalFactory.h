#ifndef GOAL_FACTORY_H_
#define GOAL_FACTORY_H_

#include "Goal.h"

class GoalFactory
{
public:
	static Goal* create_goal(std::string description, AcTick total, AcTick done, Goal* parent);
};

#endif
