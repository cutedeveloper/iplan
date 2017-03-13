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

class GoalIdentifier
{
public:
	static constexpr int HEAD_GOAL_PARENT_ID = -1;
	GoalIdentifier(int parent_id, int in_parent_id)
	: parent_id(parent_id)
	, in_parent_id(in_parent_id)
	{
	}

	GoalIdentifier() = delete;

	int get_parent_id() const
	{
		return parent_id;
	}

	void set_parent_id(const int pid)
	{
		parent_id = pid;
	}

	int get_in_parent_id() const
	{
		return in_parent_id;
	}

	void set_in_parent_id(const int in_pid)
	{
		in_parent_id = in_pid;
	}

private:
	int parent_id;
	int in_parent_id;
};

class Goal
{
public:
	Goal(const std::string& desc, AcTick total, AcTick done, const GoalIdentifier& id)
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
