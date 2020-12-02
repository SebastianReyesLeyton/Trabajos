#include "../services/mall.h"

int main() {

    Mall m;
    mallInit( &m, 7, 15 );
    report( m );
    return 0;
}