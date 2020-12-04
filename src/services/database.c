#include "./database.h"

int saveInfo( Parking p, Mall mall ) {
    FILE *f;
    f = fopen("dbParking.dat", "wb");
    if (f == NULL) {
        printf("No se escribe en este archivo.\n");
        return 0;
    }
    //showParkingState( p );
    fprintf(f, "%d %d\n", p.n, p.m);
    for (int i = 0; i < p.n; i++) {
        fprintf( f, "%d %d %d\n", p.arr[i].id, p.arr[i].state, p.arr[i].type );
    }
    fclose(f);

    f = fopen("dbMall.dat", "wb");
    if (f == NULL) {
        printf("No se escribe en este archivo.\n");
        return 0;
    }
    //showParkingState( p );
    fprintf(f, "%d %d\n", mall.floors, mall.localsFloor);
    for (int i = 0; i < mall.floors; i++) {
        for (int j = 0; j < mall.localsFloor; j++) {
            fprintf( f, "%d %d %d %d\n", mall.mall[i][j].code, mall.mall[i][j].cost , mall.mall[i][j].floor, mall.mall[i][j].state );
            fprintf( f, "%s\n", mall.mall[i][j].name);
        }
    }
    fclose(f);

    return 1;
}

int loadInfo( Parking* p, Mall* mall ) {
    FILE *f;
    f = fopen("dbParking.dat", "rb");
    if (f == NULL) {
        printf("No se lee en este archivo.\n");
        return 0;
    }
    fscanf(f, "%d %d", &p->n, &p->m);
    changeSize( p, p->n );
    for (int i = 0; i < p->n; i++) {
        fscanf( f, "%d %d %d", &(p->arr[i].id), &(p->arr[i].state), &(p->arr[i].type) );
    }
    fclose(f);

    f = fopen("dbMall.dat", "rb");
    if (f == NULL) {
        printf("No se lee en este archivo.\n");
        return 0;
    }
    //showParkingState( p );
    fscanf(f, "%d %d\n", &(mall->floors), &(mall->localsFloor));
    mallInit( mall, mall->floors, mall->localsFloor );
    for (int i = 0; i < mall->floors; i++) {
        for (int j = 0; j < mall->localsFloor; j++) {
            fscanf( f, "%d %d %d %d\n", &(mall->mall[i][j].code), &(mall->mall[i][j].cost) , &(mall->mall[i][j].floor), &(mall->mall[i][j].state) );
            fgets( mall->mall[i][j].name, N, f );
            mall->mall[i][j].name[strlen(mall->mall[i][j].name) - 1] = '\0';
        }
    }
    fclose(f);  

    return 1;
}