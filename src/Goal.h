#ifndef GOAL_H_
#define GOAL_H_

#include <string>
#include <memory>
#include <vector>

typedef size_t AcTick;

class Goal
{
public:
	typedef std::unique_ptr<Goal> GoalUniquePointer;
	typedef std::vector<GoalUniquePointer> SubGoals;
	void add_sub_goal(Goal* goal);
	size_t sub_goals_count() const;
private:
    std::string description;
    AcTick total_actick;
    AcTick done_actick;
	SubGoals sub_goals;
};

#endif
