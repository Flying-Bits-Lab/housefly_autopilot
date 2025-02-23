tests: src/*.c test/*.c include/*.h	
	gcc -I include src/*.c test/*.c -o tests

clean:	
	rm tests