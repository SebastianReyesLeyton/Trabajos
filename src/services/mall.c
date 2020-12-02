#include "./mall.h"

void mallInit( Mall* mall, int n, int m ){
    mall->localsFloor = m;
    mall->floors = n;

    mall->mall = ( Local** ) calloc(n+1, sizeof(Local *));
    for (int i = 0; i < n; i++) {
        mall->mall[i] = (Local *) calloc(m, sizeof(Local));
    }

    Local l;
    localInit( &l );
    int cont = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
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
        printf("%d floor: %d\n", i+1, cant);
    }
}

void orderFloor( Mall *m, int floor ) {
    
    Local tmp;
    for (int i = 0; i < m->localsFloor; i++) {
        tmp = m->mall[floor][i];
        int j = i - 1;
        while (j >= 0 && m->mall[floor][j].cost < tmp.cost) {
            m->mall[floor][j+1].name = m->mall[floor][j].name;
            m->mall[floor][j+1].cost = m->mall[floor][j].cost;
            m->mall[floor][j+1].state = m->mall[floor][j].state;
            j--;
        }
        m->mall[floor][j+1].name = tmp.name;
        m->mall[floor][j+1].cost = tmp.cost;
        m->mall[floor][j+1].state = tmp.state;
    }
}

int rent( Mall* m, int floor, int quantity ) {
    int ans = -1;
    for ( int i = 0; i < m->localsFloor; i++ ) {
        if (m->mall[floor][i].state == FREE && m->mall[floor][i].cost <= quantity) {
            unavaiable( &m->mall[floor][i] );
            ans = i;
            i = m->localsFloor;
        }
    }
    return ans;
}

int modifyLocals( Mall *m, int oldFloor, Local local ) {
    int ans = -1;
    for ( int j = 0; j < m->localsFloor; j++ ){
        if (!strcmp(m->mall[oldFloor][j].name, local.name)) {
            int tmp = rent( m, local.floor, local.cost );
            printf("%d\n", tmp);
            if (oldFloor != local.floor && tmp != -1 ) {
                local.code = m->mall[local.floor][tmp].code;
                local.state = m->mall[local.floor][tmp].state;
                m->mall[local.floor][tmp] = local;
                showLocal( m->mall[local.floor][tmp] );
                Local l;
                localInit( &l );
                l.code = m->mall[oldFloor][j].code;
                m->mall[oldFloor][j] = l;
                ans = 1;
            }
        }
    }
    return ans;
}

void vacateLocal( Mall *m, int code ) {
    int floor = (code / m->localsFloor);
    int j = floor*m->localsFloor - code;
    avaiable( &m->mall[floor][j] );
}