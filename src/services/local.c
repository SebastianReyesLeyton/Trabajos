#include "local.h"

void avaiable( Local *l ) { l->state = FREE;}
void unavaiable( Local *l) {l ->state = OCCUPIED;}
void localInit( Local* l ) {
    l->name = "";
    l->code = 0;
    l->floor = 0;
    l->cost = 0;
    l->state = FREE;
}

void showLocal( Local l ) {
    printf("Name: %s\n", l.name);
    printf("Code: %d\n", l.code);
    if (l.state) {printf("State: Occupied\n");}
    else { printf("State: Free\n");}
    printf("Floor: %i\n", l.floor);
    printf("Cost: %i\n", l.cost);
}