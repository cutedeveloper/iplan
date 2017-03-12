#ifndef GOAL_H_

#define GOAL_H_

#include <string>
#include <memory>
#include <vector>
#include <tuple>

typedef size_t AcTick;

class Goal;
typedef std::unique_ptr<Goal> GoalUniquePointer;
typedef std::vector<GoalUniquePointer> Goals;

/// ID of goals, for head goals the second element is HEAD_GOAL_SUB_ID
constexpr int HEAD_GOAL_SUB_ID = -1;
constexpr int GOAL_ID_MAIN_INDEX = 0;
constexpr int GOAL_ID_SUB_INDEX = 1;
typedef std::tuple<int, int> GoalIdentifier;

class Goal
{
public:
	Goal(const std::string& desc, AcTick total, AcTick done, GoalIdentifier id)
	: description(desc)
	, total_actick(total)
	, done_actick(done)
	, identifier(id)
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

	const GoalIdentifier& get_identifier() const
	{
		return identifier;
	}

	void add_sub_goal(Goal* goal);
	size_t sub_goals_count() const;
private:
    std::string description;
    AcTick total_actick;
    AcTick done_actick;
	GoalIdentifier identifier;
	Goals sub_goals;
};

#endif
