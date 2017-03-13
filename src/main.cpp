// In the name of God

#include "GoalManager.h"

int main(int argc, char** argv)
{
	GoalManager goal_manager;
	GoalIdentifier id = goal_manager.create_goal("desc", 12, 10);

//	printf("goal(%d, %d)", std::get<0>(id), std::get<1>(id));
}
