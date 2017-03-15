#include "Goal.h"

#include <iostream>

using namespace std;

AcTick Goal::get_total_actick() const
{
	AcTick sub_goals_actick = 0;
	for (auto&& goal : sub_goals)
		sub_goals_actick += goal->get_total_actick();

	return total_actick + sub_goals_actick;
}

void Goal::add_sub_goal(Goal* goal)
{
	sub_goals.push_back(GoalUniquePointer(goal));
	goal->set_in_parent_id(sub_goals.size());
}

size_t Goal::sub_goals_count() const
{
	return sub_goals.size();
}

void Goal::set_total_actick(const AcTick total)
{
	assert(total >= done_actick);
	total_actick = total;
}

AcTick Goal::get_done_actick() const
{
	AcTick sub_goals_actick = 0;
	for (auto&& goal : sub_goals)
		sub_goals_actick += goal->get_done_actick();

	return done_actick + sub_goals_actick;
}

void Goal::set_done_actick(const AcTick& value)
{
	assert(value <= total_actick);
	done_actick = value;
}

double Goal::get_progress_percent() const
{
	double percent = (static_cast<double>(get_done_actick()) / get_total_actick()) * 100;
	assert(percent <= 100);
	assert(percent >= 0);
	return percent;
}
