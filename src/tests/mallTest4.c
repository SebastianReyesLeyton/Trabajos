#include "../services/mall.h"

int main() {
    Mall m;
    mallInit( &m, 3, 5 );
    m.mall[0][0].cost = 1000;
    m.mall[0][0].name = "1000";
    unavaiable( &m.mall[0][0] );
    showLocal( m.mall[0][0] );
    printf("\n");
    vacateLocal( &m , 0 );
    showLocal( m.mall[0][0] );
    return 0;
}