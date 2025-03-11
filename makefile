tests: src/*.c test/*.c include/*.h	
	gcc src/*.c test/*.c -o tests

clean:	
	rm tests