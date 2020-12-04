#ifndef PARKING_H
#define PARKING_H

#include "./parkingLot.h"

typedef struct Parking {
    int n;
    ParkingLot *arr;
    int m;
} Parking;

void parkingInit( Parking* );
void changeSize( Parking*, int );
int enter( Parking*, enum vehicle );
int changeSpaceTo( Parking*, int, enum vehicle );
int leaveParking( Parking*, int );
void alertParking( Parking );
void showParkingState( Parking );

#endif