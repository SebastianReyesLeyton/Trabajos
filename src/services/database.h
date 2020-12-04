#ifndef DATABASE_H
#define DATABASE_H

#include <stdlib.h>
#include "./parking.h"
#include "./mall.h"

int saveInfo( Parking, Mall );
int loadInfo( Parking*, Mall* );

#endif