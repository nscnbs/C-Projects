// newagent.c

#include "agents.h"

struct agent newagent(int x, int y){

    struct agent new = {x, y};

    return new;
}