services=src/services
tests=src/tests

localTest: 
	gcc $(tests)/localTest.c $(services)/local.c -o localTest.out -lrt

delete: 
	rm *.out