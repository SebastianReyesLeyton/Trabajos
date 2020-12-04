#include "../services/parkingLot.h"

int main() {
    ParkingLot p;
    parkingLotInit( &p );
    changeToMotorcycle( &p );
    if (p.type == CAR) {printf("Espacio para carro.\n");}
    else {printf("Espacio para moto.\n");}

    if (p.state == FREE) {printf("Espacio disponible.\n");}
    else {printf("Espacio ocupado.\n");}

    printf("Id: %d\n", p.id);

    printf("\n\nDescripcion:\n");
    showParkingLot( p );

    return 0;
}