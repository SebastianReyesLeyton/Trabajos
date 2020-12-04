#include "./mall.h"

void mallInit( Mall* mall, int n, int m ){
    mall->localsFloor = m;
    mall->floors = n;

    mall->mall = ( Local** ) calloc(n+1, sizeof(Local *));
    for (int i = 0; i < n; i++) {
        mall->mall[i] = (Local *) calloc(m, sizeof(Local));
    }

    int cont = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Local l;
            localInit( &l );
            l.code = cont;
            mall->mall[i][j] = l;
            cont++;
        }
    }

}

void report( Mall m ) {
    for (int i = 0; i < m.floors; i++ ) {
        int cant = 0;
        for (int j = 0; j < m.localsFloor; j++) {
            if (m.mall[i][j].state == FREE) cant++;
        }
        printf("Piso %d: %d\n", i+1, cant);
    }
}

void orderFloor( Mall *m, int floor ) {
    
    Local tmp;
    for (int i = 0; i < m->localsFloor; i++) {
        tmp = m->mall[floor][i];
        int j = i - 1;
        while (j >= 0 && m->mall[floor][j].cost < tmp.cost) {
            strcpy(m->mall[floor][j+1].name, m->mall[floor][j].name);
            m->mall[floor][j+1].cost = m->mall[floor][j].cost;
            m->mall[floor][j+1].state = m->mall[floor][j].state;
            j--;
        }
        strcpy(m->mall[floor][j+1].name, tmp.name);
        m->mall[floor][j+1].cost = tmp.cost;
        m->mall[floor][j+1].state = tmp.state;
    }
}

int rent( Mall* m, int floor, int quantity ) {
    int ans = -1;
    for ( int i = 0; i < m->localsFloor; i++ ) {
        if (m->mall[floor][i].state == FREE && m->mall[floor][i].cost <= quantity) {
            unavaiable( &m->mall[floor][i] );
            showLocal( m->mall[floor][i] );
            ans = i;
            i = m->localsFloor;
        }
    }
    return ans;
}

int modifyLocals( Mall *mall, Local old, Local local ) {
    int ans = -1;
    int floor = (int)(old.code / mall->localsFloor);
    int j = old.code - floor*mall->localsFloor;
    mall->mall[floor][j] = local;
    if (old.floor != local.floor) {
        ans = rent( mall, local.floor, local.cost );
        if (ans != -1) {
            mall->mall[local.floor][ans] = mall->mall[floor][j];
            localInit( &mall->mall[floor][j] );
        }
        else {
            mall->mall[floor][j].floor = floor;
        }
    }
    else {
        ans = 1;
    }
    return ans;
}

void vacateLocal( Mall *mall, int code ) {
    int floor = (int)(code / mall->localsFloor);
    int j = code - floor*mall->localsFloor;
    avaiable( &mall->mall[floor][j] );
}

Local seekLocal( Mall mall, int code ) {
    int floor = (int)(code / mall.localsFloor);
    int j = code - floor*mall.localsFloor;
    return mall.mall[floor][j];
}

void showMall( Mall mall ) {
    for (int i = 0; i < mall.floors; i++) {
        for (int j = 0; j < mall.localsFloor; j++ ) {
            printf("%d ", mall.mall[i][j].code);
        }
        printf("\n");
    }
}

void showLMall( Mall mall, int code ) {
    int floor = (int)(code / mall.localsFloor);
    int j = code - floor*mall.localsFloor;
    showLocal( mall.mall[floor][j] );
}