#include "./parking.h"

void parkingInit( Parking* p ) {
    p->n = 0;
    p->arr = (ParkingLot *)calloc(0, sizeof(ParkingLot));
    free(p->arr);
    p->m = 0;
}

void changeSize( Parking *p, int n ) {
    ParkingLot pl;
    ParkingLot *arr = (ParkingLot *)calloc(n, sizeof(ParkingLot));
    parkingLotInit( &pl );
    for (int i = 0; i < n; i++) {
        if (i < p->n ) {arr[i] = p->arr[i];}
        else {
            pl.id = i;
            arr[i] = pl;
        }
    }
    p->arr = arr;
    p->n = n;
}

void alertParking( Parking p ) {
    printf("El parqueadero esta llegando a su maxima capacidad (lleva %d, %d el %.1f%)\n", p.m, p.n, ((float)(p.m) / (float)(p.n))*100 );
}

int enter( Parking *p, enum vehicle t ) {
    int ans = -1;
    for (int i = 0; i < p->n && ans == -1; i++) {
        if (p->arr[i].type == t && p->arr[i].state == FREE) {
            ans = i;
            p->m++;
            p->arr[ans].state = OCCUPIED;
            if (p->m >= p->n*0.8) alertParking( *p );
        }
    }
    return ans;
}

int changeSpaceTo( Parking *p, int pos, enum vehicle t ) {
    int ans = -1;
    if (pos < p->n && pos >= 0 && p->arr[pos].state == FREE) {
        if (t == CAR) { changeToCar( &p->arr[pos] );}
        else { changeToMotorcycle( &p->arr[pos] );}
        ans = 1;
    }
    return ans;
}

int leaveParking( Parking *p, int pos ) {
    int ans = -1;
    if (pos < p->n && pos >= 0 && p->arr[pos].state == OCCUPIED) {
        p->arr[pos].state = FREE;
        ans = 1;
        p->m--;
        if (p->m >= p->n*0.8) alertParking( *p );
    }
    return ans;
}

void showParkingState( Parking p ) {
    for (int i = 0; i < p.n; i++) {
        if (p.arr[i].state == FREE) {
            showParkingLot( p.arr[i] );
        }
    }
}