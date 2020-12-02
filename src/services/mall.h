#ifndef MALL_H
#define MALL_H

#include "string.h"
#include "./local.h"
#include "./pair.h"

typedef struct Mall {
    Local **mall;
    int floors;                 // Number of floors of the mall
    int localsFloor;            // Number of local by floor

} Mall;

void mallInit( Mall*, int, int );
void report( Mall );
void orderFloor( Mall*, int );
int rent( Mall*, int, int );
int modifyLocals( Mall*, int, Local);
void vacateLocal( Mall*, int );

#endif