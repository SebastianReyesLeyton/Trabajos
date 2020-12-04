#include "./parkingLot.h"

void parkingLotInit( ParkingLot* p ) {
    p->id = 0;
    p->type = CAR;
    p->state = FREE;
}

void changeToCar( ParkingLot* p ) {
    p->type = CAR;
}

void changeToMotorcycle( ParkingLot* p ) {
    p->type = MOTORCYCLE;
}

void unavaiableParkingLot( ParkingLot* p ) {
    p->state = OCCUPIED;
}

void avaiableParkingLot( ParkingLot* p ) {
    p->state = FREE;
}

void showParkingLot( ParkingLot p ){
    printf("Id: %d.\n", p.id);
    if (p.type == CAR) {printf("Tipo: Carro.\n");}
    else {printf("Tipo: Moto.\n");}

    if (p.state == FREE) {printf("Estado: Libre.\n");}
    else {printf("Estado: Ocupado.\n");}
}