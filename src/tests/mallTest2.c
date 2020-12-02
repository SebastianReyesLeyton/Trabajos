#include "../services/mall.h"

int main() {
    Mall m;
    mallInit( &m, 3, 5 );
    report( m );
    m.mall[0][0].cost = 1000;
    m.mall[0][1].cost = 10;
    m.mall[0][2].cost = 10000;
    m.mall[0][4].cost = 400000;
    m.mall[1][2].cost = 500;
    m.mall[1][4].cost = 4000;
    orderFloor( &m, 0 );
    orderFloor( &m, 1 );
    for (int j = 0; j < m.floors; j++) {
        for (int i = 0; i < m.localsFloor; i++) {
            printf("%d-%d ", m.mall[j][i].code, m.mall[j][i].cost);
        }
        printf("\n");
    }

    printf("%d\n",rent( &m, 0, 0 ));
    return 0;
}