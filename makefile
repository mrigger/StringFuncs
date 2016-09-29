strtest: Stringy.c
	 gcc Stringy.c -o strtest


clean:
	rm *~


run: strtest
	./strtest
