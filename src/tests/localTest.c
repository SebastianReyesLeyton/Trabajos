#include "../services/local.h"

int main() {
    Local l;
    localInit( &l );
    l.name = "Quest";
    l.cost = 10000;
    showLocal(l);
    return 0;
}