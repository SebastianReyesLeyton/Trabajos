#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <stdio.h>
#include <stdlib.h>
#include "./state.h"

typedef struct ParkingLot {
    int id;
    enum vehicle type;
    enum states state;
} ParkingLot;

void parkingLotInit( ParkingLot* );
void changeToCar( ParkingLot* );
void changeToMotorcycle( ParkingLot* );
void unavaiableParkingLot( ParkingLot* );
void avaiableParkingLot( ParkingLot* );
void showParkingLot( ParkingLot );

#endif