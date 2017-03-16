#ifndef GOAL_MANAGER_H_
#define GOAL_MANAGER_H_

#include "Goal.h"

#include <memory>
#include <iostream>

class GoalPrinter
{
public:
	virtual void print_goal(const Goals& goal) const = 0;
};

class LinearGoalPrinter : public GoalPrinter
{
public:
	void print_goal(const Goals &goals) const
	{
		bool is_first_item = true;
		for (auto&& goal : goals)
		{
			if (!is_first_item)
				std::cout <<", ";
			std::cout << goal->get_description() << "[";
			print_goal(goal->get_sub_goals());
			std::cout << "]";
			is_first_item = false;
		}
	}
};

class HierarchyGoalPrinter : public GoalPrinter
{
public:
	void print_goal(const Goals &goals) const
	{
		print_goal(goals, 1);
	}

private:
	void print_goal(const Goals &goals, unsigned int depth) const
	{
		for (auto&& goal : goals)
		{
			print_depth(depth);
			printf("%s (%lu %s of %lu %s) %f%%\n", goal->get_description().c_str(), goal->get_done_actick(),
				   goal->get_step_unit().c_str(), goal->get_total_actick(), goal->get_step_unit().c_str(), goal->get_progress_percent());
			print_goal(goal->get_sub_goals(), depth + 1);
		}
	}

	void print_depth(unsigned int depth) const
	{
		std::string line(depth, '.');
		std::cout << line;
	}
};

class GoalManager
{
public:
	GoalManager()
	: printer(new HierarchyGoalPrinter)
	{
	}

	Goal* create_goal(const std::string& desc, AcTick total = 0, AcTick done = 0, Goal* parent = nullptr,
					  const std::string& unit = std::string());
	void print_goals();

private:
	Goals head_goals;
	std::unique_ptr<GoalPrinter> printer;
};

#endif
