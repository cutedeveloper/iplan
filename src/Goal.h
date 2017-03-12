#ifndef GOAL_H_

#define GOAL_H_

#include <string>
#include <memory>
#include <vector>

typedef size_t AcTick;

class Goal;
typedef std::unique_ptr<Goal> GoalUniquePointer;
typedef std::vector<GoalUniquePointer> Goals;

class Goal
{
public:
	Goal(const std::string& desc, AcTick total, AcTick done)
	: description(desc)
	, total_actick(total)
	, done_actick(done)
	{

	}
	const std::string& get_description() const
	{
		return description;
	}

	void set_description(const std::string& desc)
	{
		description = desc;
	}

	void add_sub_goal(Goal* goal);
	size_t sub_goals_count() const;
private:
    std::string description;
    AcTick total_actick;
    AcTick done_actick;
	Goals sub_goals;
};

#endif
