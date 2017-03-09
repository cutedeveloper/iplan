#ifndef GOAL_H_
#define GOAL_H_

#include <string>

typedef size_t AcTick;

class Goal
{
private:
    std::string description;
    AcTick total_actick;
    AcTick done_actick;
};

#endif
