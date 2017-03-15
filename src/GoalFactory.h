#ifndef GOAL_FACTORY_H_
#define GOAL_FACTORY_H_

#include "Goal.h"

class GoalFactory
{
public:
	static Goal* create_goal(const std::string& description, AcTick total, AcTick done, Goal* parent, int in_parent_id,
							 const std::string& step_unit = std::string());
};

#endif
