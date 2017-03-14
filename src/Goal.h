#ifndef GOAL_H_

#define GOAL_H_

#include <string>
#include <memory>
#include <vector>
#include <tuple>
#include <assert.h>

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

	GoalIdentifier()
	: parent_id(HEAD_GOAL_PARENT_ID)
	, in_parent_id(HEAD_GOAL_PARENT_ID)
	{
	}

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
		assert(in_pid != HEAD_GOAL_PARENT_ID);
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

	int get_parent_id() const
	{
		return identifier.get_parent_id();
	}

	int get_in_parent_id() const
	{
		return identifier.get_in_parent_id();
	}

	void set_parent_id(const int parent_id)
	{
		identifier.set_parent_id(parent_id);
	}

	void set_in_parent_id(const int in_parent_id)
	{
		identifier.set_in_parent_id(in_parent_id);
	}

	AcTick get_total_actic() const;

	void add_sub_goal(Goal* goal);
	size_t sub_goals_count() const;
	AcTick get_total_actick() const;
	void set_total_actick(const AcTick total);

	AcTick get_done_actick() const;
	void set_done_actick(const AcTick& value);

private:
	std::string description;
	AcTick total_actick;
	AcTick done_actick;
	GoalIdentifier identifier;
	Goals sub_goals;
};

#endif
