// In the name of God

#include "GoalManager.h"

int main(int argc, char** argv)
{
	GoalManager manager;
	auto a= manager.create_goal("goal A", 0, 0, nullptr, "Pages");
	manager.create_goal("Goal A-1", 10, 0, a);
	auto b = manager.create_goal("Goal B", 0, 0, nullptr, "word");
	manager.create_goal("Goal B-2", 10, 0, b);
	auto b3 = manager.create_goal("Goal B-3", 10, 0, b);
	auto b4 = manager.create_goal("Goal B-4", 10, 0, b3);
	b4->set_done_actick(5);
	manager.print_goals();
}
