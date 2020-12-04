#include "src/services/mall.h"

enum process { INIT=0, RENT, ORDERFLOOR, REPORT, MODIFYLOCALS, 
               VACATELOCALS, ENTERVEHICLE, EXTENDPARKING, 
               STATEPARKING, SHOWLOCAL, FINISH, PARKING, MALL,
               LOADFILE };

void clear() {
    system("clear");
}

void pause() {
    system("sleep 2");
}

void init( Mall *mall ) {
    int n, m;
    clear();
    printf("Numero de pisos: ");
    scanf("%d", &n);
    printf("Numero de locales por piso: ");
    scanf("%d", &m);
    mallInit( mall, n, m );
} 

void optionsMall( int *state, Mall mall ) {
    int ans = 0;

    while (ans < 1 || ans > 7 ) {
        clear();
        printf("                   Centro comercial\n\n");
        showMall( mall );
        printf("\n");
        printf("                      Opciones\n\n");
        printf( "1) Alquilar un local. \n" );
        printf( "2) Ordenar un piso. \n" );
        printf( "3) Generar un reporte de estado por piso. \n" );
        printf( "4) Modificar información de locales. \n" );
        printf( "5) Desocupar locales. \n" );
        printf( "6) Mostrar Local. \n");
        printf( "7) Salir \n\n" );
        printf( "  Opcion: " );
        scanf( "%d", &ans );
    }
    switch (ans) {
        case 1: *state = RENT; break;
        case 2: *state = ORDERFLOOR; break;
        case 3: *state = REPORT; break;
        case 4: *state = MODIFYLOCALS; break;
        case 5: *state = VACATELOCALS; break;
        case 6: *state = SHOWLOCAL; break;
        default: *state = FINISH; break;
    }
}

void optionsParking(int *state) {
    int ans = 0;

    while ( ans < 1 || ans > 4 ) {
        clear();
        printf("                      Opciones\n\n");
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

    while ( ans < 1 || ans > 3 ) {
        clear();
        printf("                      Opciones\n\n");
        printf( "1) Iniciar. \n" );
        printf( "2) Cargar datos anteriores. \n");
        printf( "3) Salir. \n\n" );
        printf( "  Opcion: " );
        scanf( "%d", &ans );
    }
    switch (ans) {
        case 1: *state = INIT; break;
        case 2: *state = LOADFILE; break;
        default: *state = FINISH; break;
    }
}

void localOptions( Mall m, Local *l ) {
    int ans = 0;
    int state = 0;
    char c;

    while ( ans != 6 ) {
        while ( ans < 1 || ans > 6 ) {
            clear();
            printf("                      Opciones\n\n");
            printf( "1) Modificar nombre. \n" );
            printf( "2) Modificar costo. \n" );
            printf( "3) Modificar estado. \n" );
            printf( "4) Modificar piso del local. \n" );
            printf( "5) Mostrar info del local. \n" );
            printf( "6) Salir. \n\n" );
            printf( "  Opcion: " );
            scanf( "%d", &ans );
        }

        switch (ans) {
        case 1:
            printf("Introduce el nuevo nombre: ");
            while ((c = getchar()) != EOF && c != '\n');
            fgets(l->name, N, stdin);
            l->name[strlen(l->name) - 1] = '\0';
            ans = 0;
            break;
        case 2:
            printf("Introduce el nuevo costo: ");
            scanf("%d", &l->cost);
            ans = 0;
            break;
        case 3:
            while ( state < 1 || state > 2 ) {
                clear();
                printf("1) Libre. \n");
                printf("2) Ocupada. \n\n");
                printf("  Opcion: ");
                scanf("%d", &state);
            }
            state--;
            if (!state) { avaiable( l ); }
            else { unavaiable( l ); }
            ans = 0;
            break;
        case 4:
            printf("Introduce el piso en el cual quieres situar el local: ");
            scanf("%d", &l->floor);
            l->floor = m.floors - l->floor;
            ans = 0;
            break;
        case 5:
            showLocal(*l);
            pause();
            ans = 0;
            break;
        default:
            break;
        }
    }
}


void optionsVehicleMall(int *state) {
    int ans = 0;

    while ( ans < 1 || ans > 3 ) {
        system("clear");
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
        if (state == INIT) {
            Mall mall;
            init( &mall );
            pause();
            while ( state != FINISH ) {
                optionsVehicleMall( &state );
                if (state == MALL) {
                    while ( state != FINISH ) {
                        optionsMall( &state, mall );
                        int floor, value, ans;
                        Local l, old;
                        switch (state) {
                            case RENT:
                                clear();
                                printf("Introduzca el piso: ");
                                scanf("%d", &floor);
                                printf("Introduzca su capacidad de pago para alquilar el local: ");
                                scanf("%d", &value);
                                ans = rent( &mall, mall.floors - floor, value);
                                if (ans != -1) printf("Proceso de alquiler exitoso !!! \n");
                                else printf("No se pudo encontrar un local que cumpla con los parametros establecidos. \n");
                                pause();
                                break;
                            case ORDERFLOOR:
                                clear();
                                printf("Introduzca el piso el cual quieres ordenar: ");
                                scanf("%d", &floor);
                                orderFloor( &mall, mall.floors - floor );
                                printf("Proceso completado.\n");
                                break;
                            case REPORT: 
                                clear();
                                printf("Reporte \n\n");
                                report( mall );
                                pause();
                                break;
                            case MODIFYLOCALS:
                                clear();
                                localInit( &l );
                                printf("Codigo del local a modificar: ");
                                scanf( "%d", &l.code );
                                old = seekLocal( mall, l.code );
                                showLocal( old );
                                l = old;
                                localOptions( mall, &l );
                                pause();
                                modifyLocals( &mall, old, l );
                                break;
                            case VACATELOCALS: 
                                clear();
                                printf("Introduce el codigo del local a desocupar: ");
                                scanf("%d", &value);
                                vacateLocal( &mall, value );
                                break;
                            case SHOWLOCAL:
                                clear();
                                printf("Introduce el codigo del local que quieres consultar: ");
                                scanf("%d", &value);
                                showLMall( mall, value );
                                pause();
                                break;
                            default: 
                                break;
                        }
                    }
                    state = MALL;
                }
                else if ( state == PARKING ) {
                    printf("En proceso de generar el menu.\n");
                    state = PARKING;
                }
            }
            state = INIT;
        }
        else if (state == LOADFILE) {
            printf("Por implementar.\n");
            state = LOADFILE;
        }
    }
    return 0;
}