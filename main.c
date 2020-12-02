#include "src/services/mall.h"

enum process { INIT=0, RENT, ORDERFLOOR, REPORT, MODIFYLOCALS, 
               VACATELOCALS, ENTERVEHICLE, EXTENDPARKING, 
               STATEPARKING, FINISH, PARKING, MALL  };

void init( Mall *mall ) {
    int n, m;
    printf("Numero de pisos: ");
    scanf("%d", &n);
    printf("Numero de locales por piso: ");
    scanf("%d", &m);
    mallInit( mall, n, m );
} 

void optionsMall(int *state) {
    int ans = 0;

    while (ans < 1 || ans > 6 ) {
        printf( "1) Alquilar un local. \n" );
        printf( "2) Ordenar un piso. \n" );
        printf( "3) Generar un reporte de estado por piso. \n" );
        printf( "4) Modificar información de locales. \n" );
        printf( "5) Desocupar locales. \n" );
        printf( "6) Salir \n\n" );
        printf( "  Opcion: " );
        scanf( "%d", &ans );
    }
    switch (ans) {
        case 1: *state = RENT; break;
        case 2: *state = ORDERFLOOR; break;
        case 3: *state = REPORT; break;
        case 4: *state = MODIFYLOCALS; break;
        case 5: *state = VACATELOCALS; break;
        default: *state = FINISH; break;
    }
}

void optionsParking(int *state) {
    int ans = 0;

    while ( ans < 1 || ans > 4 ) {
        printf( "1) Entra un vehiculo. \n" );
        printf( "2) Agrandar parqueadero. \n" );
        printf( "3) Estado del parqueadero. \n" );
        printf( "4) Salir. \n\n" );
        printf( "  Opcion: " );
        scanf( "%d", &ans );
    }
    switch (ans) {
        case 1: *state = ENTERVEHICLE; break;
        case 2: *state = EXTENDPARKING; break;
        case 3: *state = STATEPARKING; break;
        default: *state = FINISH; break;
    }
}

void initOptions(int *state) {
    int ans = 0;

    while ( ans < 1 || ans > 2 ) {
        printf( "1) Iniciar. \n" );
        printf( "2) Salir. \n\n" );
        printf( "  Opcion: " );
        scanf( "%d", &ans );
    }
    switch (ans) {
        case 1: *state = INIT; break;
        default: *state = FINISH; break;
    }
}


void optionsVehicleMall(int *state) {
    int ans = 0;

    while ( ans < 1 || ans > 2 ) {
        printf( "1) Centro Comercial. \n" );
        printf( "2) Parqueadero. \n" );
        printf( "3) Salir. \n\n" );
        printf( "  Opcion: " );
        scanf( "%d", &ans );
    }
    switch (ans) {
        case 1: *state = MALL; break;
        case 2: *state = PARKING; break;
        default: *state = FINISH; break;
    }
}

int main() {
    int state = INIT;
    while (state != FINISH) {
        initOptions( &state );
        if (state = INIT) {
            Mall mall;
            init( &mall );
            while (state != FINISH) {
                optionsVehicleMall( &state );
                if (state == MALL) {
                    int floor;
                    switch (state) {
                        case RENT:
                            int value;
                            printf("Introduzca su capacidad de pago para alquilar el local: ");
                            scanf("%d", &value);
                            if (rent( &mall, floor, value )) printf("Proceso de alquiler exitoso !!! \n");
                            else printf("No se pudo encontrar un local que cumpla con los parametros establecidos. \n");
                            break;
                        case ORDERFLOOR:
                            break;
                        case REPORT: 
                            break;
                        case MODIFYLOCALS: 
                            break;
                        case VACATELOCALS: 
                            break;
                        default: 
                            break;
                    }
                }
            }
        }
    }
    return 0;
}