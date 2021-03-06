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
	gcc main.c $(services)/local.c $(services)/mall.c $(services)/parkingLot.c $(services)/parking.c $(services)/database.c -o main.exe -lrt

parkingLotTest:
	gcc $(tests)/parkingLotTest.c $(services)/parkingLot.c -o parkingLotTest.out -lrt

parkingLotTest2:
	gcc $(tests)/parkingLotTest2.c $(services)/parkingLot.c -o parkingLotTest2.out -lrt

parkingTest:
	gcc $(tests)/parkingTest.c $(services)/parkingLot.c $(services)/parking.c -o parkingTest.out -lrt

delete: 
	rm *.out *.exe

deleteDat:
	rm *.dat