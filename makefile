strtest: dir.c
	gcc dir.c -o strtest

clean:
	rm *~

run: strtest
	./strtest
