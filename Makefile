services=src/services
tests=src/tests

localTest: 
	gcc $(tests)/localTest.c $(services)/local.c -o localTest.out -lrt

mallTest:
	gcc $(tests)/mallTest.c $(services)/local.c $(services)/mall.c -o mallTest.out -lrt

mallTest2:
	gcc $(tests)/mallTest2.c $(services)/local.c $(services)/mall.c -o mallTest2.out -lrt

mallTest3:
	gcc $(tests)/mallTest3.c $(services)/local.c $(services)/mall.c -o mallTest3.out -lrt

mallTest4:
	gcc $(tests)/mallTest4.c $(services)/local.c $(services)/mall.c -o mallTest4.out -lrt

main:
	gcc main.c $(services)/local.c $(services)/mall.c -o main.out -lrt

delete: 
	rm *.out