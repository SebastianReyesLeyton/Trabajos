#include "local.h"

void avaiable( Local *l ) { l->state = FREE;}
void unavaiable( Local *l) {l ->state = OCCUPIED;}