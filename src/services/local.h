#ifndef LOCAL_H
#define LOCAL_H

#include <stdio.h>
#include <stdlib.h>
#include "./state.h"
typedef struct Local {
    char* name;             // Local name
    int code;               // Code of local
    int floor;              // Floor of the mall where it's located
    int state;              // If local is free or occupied
    int cost;               // Local rental cost
} Local;

void avaiable( Local* );
void unavaiable( Local* );
void localInit( Local* );
void showLocal( Local );

#endif