#include "../services/parking.h"

int main() {
    Parking p;
    parkingInit( &p );
    changeSize( &p, 4 );
    p.arr[2].type = MOTORCYCLE;
    showParkingState(p);
    printf("\n------------------\n");
    changeSize( &p, 11 );
    showParkingState(p);

    printf("\n------------------\n");

    printf("%d\n", enter( &p, CAR ));
    printf("%d\n", enter( &p, CAR ));
    printf("%d\n", enter( &p, CAR ));
    printf("%d\n", enter( &p, CAR ));
    printf("%d\n", enter( &p, CAR ));
    printf("%d\n", enter( &p, CAR ));
    printf("%d\n", enter( &p, CAR ));
    printf("%d\n", enter( &p, CAR ));
    printf("%d\n", enter( &p, MOTORCYCLE ));
    showParkingState(p);

    printf("\n------------------\n");

    leaveParking( &p, 2 );
    showParkingState(p);
    return 0;
}