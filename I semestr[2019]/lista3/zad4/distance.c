// distance.c

#include "agents.h"
#include <math.h>

double distance(struct agent a1, struct agent a2){

    double dist = sqrt((a1.x - a2.x)*(a1.x - a2.x) + (a1.y - a2.y)*(a1.y - a2.y));

    return dist;
}

